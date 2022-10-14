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
const int mod = 1e9 + 7, abc = 864197532, N = 504, K = 111;

int dp[2][N][N];
string s[N];
int n, m;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    if (s[0][0] != s[n - 1][m - 1]) return cout << 0 << endl, 0;
    int d = n + m - 2 >> 1;
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            int x1 = a, y1 = d - x1, x2 = b, y2 = n - 1 - d + m - 1 - x2;
            if (0 <= x1 && x1 < n && 0 <= x2 && x2 < n && 0 <= y1 && y1 < m && 0 <= y2 && y2 < m) {
                if (x1 <= x2 && y1 <= y2) if (s[x1][y1] == s[x2][y2]) dp[d & 1][a][b] = 1;
            }
        }
    }
    d--;
    for (; ~d; --d) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[d & 1][i][j] = 0;
            }
        }
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                int x1 = a, y1 = d - x1, x2 = b, y2 = n - 1 - d + m - 1 - x2;
                if (0 <= x1 && x1 < n && 0 <= x2 && x2 < n && 0 <= y1 && y1 < m && 0 <= y2 && y2 < m) {
                    if (x1 + 1 < n && x2 - 1 >= 0 && s[x1 + 1][y1] == s[x2 - 1][y2]) dp[d & 1][a][b] = (dp[d & 1][a][b] + dp[d & 1 ^ 1][a + 1][b - 1]) % mod;
                    if (x1 + 1 < n && y2 - 1 >= 0 && s[x1 + 1][y1] == s[x2][y2 - 1]) dp[d & 1][a][b] = (dp[d & 1][a][b] + dp[d & 1 ^ 1][a + 1][b]) % mod;
                    if (y1 + 1 < m && x2 - 1 >= 0 && s[x1][y1 + 1] == s[x2 - 1][y2]) dp[d & 1][a][b] = (dp[d & 1][a][b] + dp[d & 1 ^ 1][a][b - 1]) % mod;
                    if (y1 + 1 < m && y2 - 1 >= 0 && s[x1][y1 + 1] == s[x2][y2 - 1]) dp[d & 1][a][b] = (dp[d & 1][a][b] + dp[d & 1 ^ 1][a][b]) % mod;
                }
            }
        }
    }
    cout << dp[0][0][n - 1] << endl;
}