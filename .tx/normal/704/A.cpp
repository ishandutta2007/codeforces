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

set<int> cnt[333333];
vector<int> es;

int main() {
    sciid(n, q);
    int ans = 0;
    int last = 0;
    int aid = 0;
    while (q-- > 0) {
        sciid(x, y);
        if (x == 1) {
            cnt[y].insert(aid);
            es.push_back(y);
            aid++;
            ans++;
        } else if (x == 2) {
            ans -= cnt[y].size();
            cnt[y].clear();
        } else {
            while (last < y) {
                int app = es[last];
                if (cnt[app].find(last) != cnt[app].end()) {
                    cnt[app].erase(last);
                    ans--;
                }
                last++;
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}