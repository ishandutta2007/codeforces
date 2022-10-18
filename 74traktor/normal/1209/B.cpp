#include <bits/stdc++.h>

using namespace std;

pair < int, int > a[105];

main() {
/*#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "0" + s;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += (s[i] - '0');
    for (int timer = 1; timer <= 300000; ++timer) {
        int cur = 0;
        for (int j = 1; j <= n; ++j) {
            if (timer < a[j].second) cur += (s[j] - '0');
            else {
                int y = timer;
                y -= a[j].second;
                y /= a[j].first;
                if (y % 2 == 1) cur += (s[j] - '0');
                else cur += (1^(s[j] - '0'));
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}