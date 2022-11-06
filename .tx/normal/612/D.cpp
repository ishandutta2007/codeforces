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

int main() {
    sciid(n, k);
    vector<pair<int, int> > ps;
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        ps.push_back({x, -1});
        ps.push_back({y, 1});
    }

    sort(ps.begin(), ps.end());

    vector<pair<int, int> > ans;
    int ck = 0;

    for (auto& p : ps) {
        if (p.second == -1) {
            ck++;
            if (ck == k) {
                ans.push_back({p.first, -1});
            }
        } else {
            if (ck == k) {
                ans.back().second = p.first;
            }
            ck--;
        }
    }

    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i.first << " " << i.second << "\n";
    }


    return 0;
}