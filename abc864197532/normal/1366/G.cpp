#include <bits/stdc++.h>
using namespace std;
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
const int mod = 1e9 + 7, x = 864197532, N = 10008, logN = 18, K = 500, C = 100;

int dp[N][N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int pt = -1, now = 0;
        for (int j = i; j < n; ++j) {
            now += (s[j] == '.' ? -1 : 1);
            if (now == 0) {
                pt = j;
                break;
            }
            if (now < 0) break;
        }
        for (int j = 0; j <= m; ++j) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if (j < m && s[i] == t[j]) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            if (~pt) dp[pt + 1][j] = min(dp[pt + 1][j], dp[i][j]);
            if (j && s[i] == '.') dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
        }
    }
    cout << dp[n][m] << endl;
}