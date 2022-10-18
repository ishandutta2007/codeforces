#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int b, g, n, ans = 0;
    cin >> b >> g >> n;
    vector < pair < int, int > > t;
    for (int i = 0; i <= min(b, n); ++i) {
        int j = n - i;
        if (j > g) continue;
        t.push_back({i, j});
    }
    for (int i = 0; i < (int)t.size();) {
        int j = i;
        while (j < (int)t.size() && t[i].second + t[j].first <= n) ++j;
        ans++;
        i = j;
    }
    cout << ans << '\n';
    return 0;
}