#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

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
    sciid(n, v);
    vector<pair<int, int> > a, b;
    for (int i = 0; i < n; i++) {
        sciid(t, p);
        (t == 1 ? a : b).push_back({p, i});
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    for (int i = 1; i < a.size(); i++) {
        a[i].first += a[i - 1].first;
    }
    for (int i = 1; i < b.size(); i++) {
        b[i].first += b[i - 1].first;
    }
    int ans = 0;
    int ai = -1;
    for (int i = 0; i <= b.size() && 2 * i <= v; i++) {
        int c = i == 0 ? 0 : b[i - 1].first;
        int ka = min((int) a.size(), v - 2 * i);
        if (ka > 0) {
            c += a[ka - 1].first;
        }
        if (c > ans) {
            ans = c;
            ai = i;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < ai; i++) {
        cout << b[i].second + 1 << "\n";
    }
    int ka = min((int) a.size(), v - 2 * ai);
    for (int i = 0; i < ka; i++) {
        cout << a[i].second + 1 << "\n";
    }

    return 0;
}