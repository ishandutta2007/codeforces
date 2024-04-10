#include<bits/stdc++.h>

using namespace std;

int cnt[27];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k, ans;
    cin >> t;
    string s;
    while (t--) {
        cin >> n >> k >> s;
        ans = 0;
        for (int i = 0; i < (k + 1) / 2; ++i) {
            for (int j = 0; j < 26; ++j) cnt[j] = 0;
            for (int j = i; j < n; j += k) cnt[s[j] - 'a']++;
            for (int j = k - i - 1; j < n; j += k) cnt[s[j] - 'a']++;
            int imax = 0;
            for (int j = 0; j < 26; ++j) imax = max(imax, cnt[j]);
            if (k % 2 == 1 && i == k / 2) {
                ans += (n / k - imax / 2);
            }
            else {
                ans += (2 * n / k - imax);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}