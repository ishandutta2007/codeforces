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

vector<pair<int, lint> > a;
vector<pair<int, lint> > b;

int main() {
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        int x;
        char c;
        scanf("%d-%c", &x, &c);
        int y = c - 'a';
        if (!a.empty() && a.back().first == y) {
            a.back().second += x;
        } else {
            a.push_back({y, x});
        }
    }
    for (int i = 0; i < m; i++) {
        int x;
        char c;
        scanf("%d-%c", &x, &c);
        int y = c - 'a';
        if (!b.empty() && b.back().first == y) {
            b.back().second += x;
        } else {
            b.push_back({y, x});
        }
    }

    n = a.size();
    m = b.size();

    if (m == 1) {
        lint ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].first == b[0].first && a[i].second >= b[0].second) {
                ans += a[i].second - b[0].second + 1;
            }
        }
        cout << ans;
        return 0;
    }

    if (m == 2) {
        lint ans = 0;
        for (int i = 0; i + m <= n; i++) {
            bool ok = true;
            if (a[i].first != b[0].first || a[i].second < b[0].second) {
                ok = false;
            }
            if (a[i + m - 1].first != b[m - 1].first || a[i + m - 1].second < b[m - 1].second) {
                ok = false;
            }
            if (ok) {
                ans++;
            }
        }
        cout << ans;
        return 0;
    }

    vector<pair<int, int> > s;
    for (int i = 1; i + 1 < m; i++) {
        s.push_back(b[i]);
    }
    s.push_back({-1, -1});
    for (int i = 0; i < n; i++) {
        s.push_back(a[i]);
    }
    vector<int> z(s.size());
    int l = 0, r = 0;
    for (int i = 1; i < z.size(); i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }

    int ans = 0;
    for (int i = 0; i + m <= n; i++) {
        bool ok = true;
        if (a[i].first != b[0].first || a[i].second < b[0].second) {
            ok = false;
        }
        if (a[i + m - 1].first != b[m - 1].first || a[i + m - 1].second < b[m - 1].second) {
            ok = false;
        }
        if (z[m + i] < m - 2) {
            ok = false;
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}