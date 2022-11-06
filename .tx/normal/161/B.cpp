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

vector<int> ans[1111];

int main() {
    sciid(n, k);
    vector<pair<int, int> > t, c;
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        (y == 1 ? t : c).push_back({x, i});
    }
    sort(t.begin(), t.end());
    sort(c.begin(), c.end());
    double tc = 0;

    int ct = t.size();
    for (int i = 0; i < k - 1 && i < ct; i++) {
        ans[i].push_back(t.back().second);
        tc += t.back().first / 2.0;
        t.pop_back();
    }
    for (int i = ct; i < k - 1; i++) {
        ans[i].push_back(c.back().second);
        tc += c.back().first;
        c.pop_back();
    }
    if (!t.empty() && !c.empty()) {
        tc -= min(t[0].first, c[0].first) / 2.0;
    } else if (!t.empty()) {
        tc -= t[0].first / 2.0;
    }

    for (auto& it : t) {
        tc += it.first;
        ans[k - 1].push_back(it.second);
    }

    for (auto& it : c) {
        tc += it.first;
        ans[k - 1].push_back(it.second);
    }

    cout.precision(1);
    cout << fixed << tc << "\n";
    for (int i = 0; i < k; i++) {
        cout << ans[i].size() << " ";
        for (int j : ans[i]) {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}