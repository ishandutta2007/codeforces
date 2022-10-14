#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1001, logN = 18, K = 500, C = 100;

lli solve(string s, int m, int d) {
    int n = s.length();
    lli dp[n + 1][m][2];
    fop (i,0,n + 1) fop (j,0,m) fop (k,0,2) dp[i][j][k] = 0;
    dp[0][0][0] = 1; // 0 no, 1 -> <
    fop (i,0,n) fop (j,0,m) fop (k,0,2) {
        if (!dp[i][j][k]) continue;
        if (i & 1) {
            int dd;
            if (k) dd = 10;
            else dd = s[i] - '0' + 1;
            if (d < dd) {
                if (k || d < dd - 1) dp[i + 1][(j * 10 + d) % m][1] = (dp[i + 1][(j * 10 + d) % m][1] + dp[i][j][k]) % mod;
                else dp[i + 1][(j * 10 + d) % m][0] = (dp[i + 1][(j * 10 + d) % m][0] + dp[i][j][k]) % mod;
            }
        } else {
            int dd;
            if (k) dd = 10;
            else dd = s[i] - '0' + 1;
            fop (p,0,dd) if (p != d) {
                if (k || p < dd - 1) dp[i + 1][(j * 10 + p) % m][1] = (dp[i + 1][(j * 10 + p) % m][1] + dp[i][j][k]) % mod;
                else dp[i + 1][(j * 10 + p) % m][0] = (dp[i + 1][(j * 10 + p) % m][0] + dp[i][j][k]) % mod;
            }
        }
    }
    return dp[n][0][1];
}

int re(string s, int m, int d) {
    int n = s.length();
    int ans = 0;
    fop (i,0,n) {
        if (i & 1) {
            if (s[i] - '0' != d) return 0;
        } else {
            if (s[i] - '0' == d) return 0;
        }
        ans = (ans * 10 + s[i] - '0') % m;
    }
    return ans == 0;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, d;
    cin >> m >> d;
    string a, b;
    cin >> a >> b;
    cout << (solve(b, m, d) - solve(a, m, d) + re(b, m, d) + mod) % mod << endl;
}