#include<bits/stdc++.h>

using namespace std;

string s[15];

void solve() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    set < int > good;
    for (int i = 0; i <= 9; ++i) good.insert(i);
    for (int i = 1; i <= n; ++i) if (good.find(s[i][0] - '0') != good.end()) good.erase(s[i][0] - '0');
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (s[i] == s[j]) {
                int x = (*good.begin());
                s[i][0] = char('0' + x);
                ans++;
                good.erase(x);
            }
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i) cout << s[i] << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}