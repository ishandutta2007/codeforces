#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 +5 ;
int dp[maxn], pref[maxn];

inline int get_s(int l, int r, int n) {
    r = min(r, n);
    l = max(l, 1);
    return pref[r] - pref[l - 1];
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        s = "#" + s;
        for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + (s[i] - '0');
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            if (s[i] == '0' && get_s(i - k, i, n) == 0 && get_s(i, i + k, n) == 0) dp[i] = max(dp[i], dp[max(0, i - k - 1)] + 1);
        }
        cout << dp[n] << '\n';
    }
    return 0;
}