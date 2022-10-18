#include<bits/stdc++.h>

using namespace std;

int was[27];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        string ans = "";
        for (int i = 1; i <= b; ++i) ans += char('a' + i - 1);
        for (int i = b + 1; i <= a; ++i) ans += 'a';
        for (int i = a + 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) was[j] = 0;
            for (int j = i - a + 1; j < i; ++j) was[ans[j - 1] - 'a'] = 1;
            int cnt = 0;
            for (int j = 0; j < 26; ++j) cnt += was[j];
            if (cnt == b) {
                ans += ans[i - a];
            }
            else {
                for (int j = 0; j < 26; ++j) {
                    if (was[j] == 0) {
                        ans += char('a' + j);
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}