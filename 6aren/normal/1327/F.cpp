#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 500005;
const int MOD = 998244353;

int l[N], r[N], x[N];
int s[N], maxl[N], dp[N], pref[N];

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, m, k;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> x[i];
        r[i]++;
    }
    int ans = 1;
    for (int foo = 0; foo < k; foo++) {
        for (int i = 1; i <= n + 1; i++) {
            s[i] = maxl[i] = dp[i] = pref[i] = 0; 
        }
        for (int i = 1; i <= m; i++) {
            if (bit(x[i], foo)) {
                s[l[i]]++;
                s[r[i]]--;
            } else {
                maxl[r[i]] = max(maxl[r[i]], l[i]);
            }
        }
        dp[0] = pref[0] = 1;
        for (int i = 1; i <= n + 1; i++) {
            s[i] += s[i - 1];
            pref[i] = pref[i - 1];
            maxl[i] = max(maxl[i], maxl[i - 1]);
            if (s[i]) continue;
            if (maxl[i]) dp[i] = pref[i - 1] - pref[maxl[i] - 1];
            else dp[i] = pref[i - 1];
            if (dp[i] < 0) dp[i] += MOD;
            pref[i] = (pref[i - 1] + dp[i]) % MOD;
            //cout << foo << ' ' << i << ' ' << dp[i] << endl;
        }
        ans = 1LL * dp[n + 1] * ans % MOD;
        if (ans < 0) ans += MOD;
    }
    cout << ans;
    return 0;
}