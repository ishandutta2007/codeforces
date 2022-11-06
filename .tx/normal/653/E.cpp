#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

const string FAIL = "impossible";
const string OK = "possible";

int nums[333333];

unordered_set<int> fs[333333];
set<int> nused;
int k0 = 0;

void dfs(int v) {
    nused.erase(v);
    int i = -1;
    while (true) {
        set<int>::iterator it = nused.upper_bound(i);
        if (it == nused.end()) {
            break;
        }
        i = *it;
        if (fs[v].find(i) == fs[v].end()) {
            if (v == 0) {
                k0++;
            }
            dfs(i);
        }
    }
}

int main() {
    sciiid(n, m, k);
    for (int i = 0; i < n; i++) {
        nums[i] = i;
    }
    random_shuffle(nums + 1, nums + n);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        x = nums[x];
        y = nums[y];
        fs[x].insert(y);
        fs[y].insert(x);
    }

    if (fs[0].size() > n - 1 - k) {
        cout << FAIL;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        nused.insert(i);
    }

    dfs(0);

    if (k0 <= k && nused.empty()) {
        cout << OK;
    } else {
        cout << FAIL;
    }


    return 0;
}