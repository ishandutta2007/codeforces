#include <bits/stdc++.h>

using namespace std;

#define int long long
pair < int, int > pref[200005];
pair < int, int > pref_min[200005];
pair < int, int > pref_max[200005];

int f(string &s) {
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0, x = 0, y = 0;
    for (auto c : s) {
        if (c == 'W') x++;
        if (c == 'A') y++;
        if (c == 'S') x--;
        if (c == 'D') y--;
        x1 = min(x1, x);
        x2 = max(x2, x);
        y1 = min(y1, y);
        y2 = max(y2, y);
    }
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    s = '#' + s;
    for (int i = 1; i <= n; ++i) pref[i] = {0, 0}, pref_min[i] = {0, 0}, pref_max[i] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1];
        pref_min[i] = pref_min[i - 1];
        pref_max[i] = pref_max[i - 1];
        if (s[i] == 'W') pref[i].first++;
        if (s[i] == 'A') pref[i].second++;
        if (s[i] == 'S') pref[i].first--;
        if (s[i] == 'D') pref[i].second--;
        pref_min[i].first = min(pref_min[i].first, pref[i].first);
        pref_max[i].first = max(pref_max[i].first, pref[i].first);
        pref_min[i].second = min(pref_min[i].second, pref[i].second);
        pref_max[i].second = max(pref_max[i].second, pref[i].second);
    }
    int ans = (pref_max[n].first - pref_min[n].first + 1) * (pref_max[n].second - pref_min[n].second + 1);
    int min_x = pref[n].first, min_y = pref[n].second, max_x = pref[n].first, max_y = pref[n].second;
    for (int i = n - 1; i > 0; --i) {
        int add = 0;
        if (pref[i].second == pref_min[i].second) add = 1;
        ans = min(ans, (max(max_y - 1, pref_max[i].second) - min(min_y - 1, pref_min[i].second - add) + 1) * (max(max_x, pref_max[i].first) - min(min_x, pref_min[i].first) + 1));
        add = 0;
        if (pref[i].second == pref_max[i].second) add = 1;
        ans = min(ans, (max(max_y + 1, pref_max[i].second + add) - min(min_y + 1, pref_min[i].second) + 1) * (max(max_x, pref_max[i].first) - min(min_x, pref_min[i].first) + 1));
        add = 0;
        if (pref[i].first == pref_min[i].first) add = 1;
        ans = min(ans, (max(max_y, pref_max[i].second) - min(min_y, pref_min[i].second) + 1) * (max(max_x - 1, pref_max[i].first) - min(min_x - 1, pref_min[i].first - add) + 1));
        add = 0;
        if (pref[i].first == pref_max[i].first) add = 1;
        ans = min(ans, (max(max_y, pref_max[i].second) - min(min_y, pref_min[i].second) + 1) * (max(max_x + 1, pref_max[i].first + add) - min(min_x + 1, pref_min[i].first) + 1));
        min_x = min(min_x, pref[i].first);
        max_x = max(max_x, pref[i].first);
        min_y = min(min_y, pref[i].second);
        max_y = max(max_y, pref[i].second);
    }
    s[0] = 'W';
    ans = min(ans, f(s));
    s[0] = 'S';
    ans = min(ans, f(s));
    s[0] = 'A';
    ans = min(ans, f(s));
    s[0] = 'D';
    ans = min(ans, f(s));
    cout << ans << '\n';
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}