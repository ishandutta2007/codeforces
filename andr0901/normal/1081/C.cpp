#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> dp(n, vector <int> (k + 1));
    dp[0][0] = m;
    forn (i, 1, n) {
        dp[i] = dp[i - 1];
        forn (j, 1, k + 1) 
            dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j - 1] * (m - 1)) % MOD;
    }
    cout << dp[n - 1][k];
    return 0;
}