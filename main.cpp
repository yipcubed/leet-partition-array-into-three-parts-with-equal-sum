#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool canPartition(vector<int> &A, int start, int sum) {
        int sumi = 0;
        for (int i = start; i < A.size() - 1; ++i) {
            sumi += A[i];
            if (sumi == sum) {
                return true;
            }
        }
        return false;
    }

    bool canThreePartsEqualSum(vector<int> &A) {
        if (A.size() < 3) return false;
        if (A.size() == 3) return A[0] == A[1] && A[0] == A[2];
        int sum = 0;
        for (auto n: A)
            sum += n;
        if (sum % 3 != 0) return false;
        int n3 = sum / 3;
        int sumi = 0;
        for (int i = 0; i < A.size() - 2; ++i) {
            sumi += A[i];
            if (sumi == n3) {
                bool found = canPartition(A, i + 1, n3);
                if (found)
                    return true;
            }
        }
        return false;
    }
};

void test1() {
    vector<int> v1{0,2,1,-6,6,-7,9,1,2,0,1};

    cout << "t ? " << Solution().canThreePartsEqualSum(v1) << endl;

    vector<int> v2{0,2,1,-6,6,7,9,-1,2,0,1};

    cout << "f ? " << Solution().canThreePartsEqualSum(v2) << endl;

    vector<int> v3{3,3,6,5,-2,2,5,1,-9,4};

    cout << "t ? " << Solution().canThreePartsEqualSum(v3) << endl;
}

void test2() {

}

void test3() {

}