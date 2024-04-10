#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 333;

int dp[201][201][201];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[0][i][j] = -1 << 30;
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                dp[i + 1][j][k] = -1 << 30;
            }
        }
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                int &trans1 = dp[i + 1][j][k + (s[i] == t[0])];
                trans1 = max(trans1, dp[i][j][k] + k * (s[i] == t[1]));
                int &trans2 = dp[i + 1][j + 1][k + (t[0] == t[0])];
                trans2 = max(trans2, dp[i][j][k] + k * (t[0] == t[1]));
                int &trans3 = dp[i + 1][j + 1][k + (t[1] == t[0])];
                trans3 = max(trans3, dp[i][j][k] + k * (t[1] == t[1]));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout << ans << endl;
}