#include <bits/stdc++.h>
using namespace std;

#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
//#define _USE_MATH_DEFINES
const int maxn = 100000, k = 26;
int dp[26][26], prv[26][26];
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            dp[i][j] = prv[i][j] = 0;
            if (s[0]-'a' != i)
                prv[i][j]++;
            if (s[1]-'a' != j)
                prv[i][j]++;
            if (i == j)
                prv[i][j] = maxn+1;
            dp[i][j] = prv[i][j];
        }
    }
    for (int i = 2; i < n; ++i) {
        for (int j1 = 0; j1 < k; ++j1) {
            for (int j2 = 0; j2 < k; ++j2) {
                prv[j1][j2] = dp[j1][j2];
                dp[j1][j2] = maxn+1;
            }
        }
        for (int j1 = 0; j1 < k; ++j1) {
            int m1 = 0, m2 = 1;
            if (j1 == 0)
                m1 = 2;
            if (j1 == 1)
                m2 = 2;
            if (prv[m1][j1] > prv[m2][j1])
                swap(m1, m2);
            for (int j2 = max(m1, m2)+1; j2 < k; ++j2) {
                if (j2 != j1) {
                    if (prv[j2][j1] < prv[m1][j1]) {
                        m2 = m1;
                        m1 = j2;
                    } else if (prv[j2][j1] < prv[m2][j1]) {
                        m2 = j2;
                    }
                }
            }
            for (int j2 = 0; j2 < k; ++j2) {
                if (j2 != j1) {
                    if (j2 == m1)
                        dp[j1][j2] = prv[m2][j1];
                    else
                        dp[j1][j2] = prv[m1][j1];
                    if (s[i]-'a' != j2)
                        dp[j1][j2]++;
                }
            }
        }
    }
    int ans = maxn+1;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            ans = min(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}