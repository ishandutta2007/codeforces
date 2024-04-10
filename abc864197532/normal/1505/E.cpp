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
const int mod = 998244353, abc = 864197532, N = 200005, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector <vector <int>> dp(n, vector <int>(m));
    for (int i = n - 1; ~i; --i) {
        for (int j = m - 1; ~j; --j) {
            dp[i][j] = (s[i][j] == '*');
            vector <pii> pos[20];
            for (int ii = i; ii < n; ++ii) {
                for (int jj = j; jj < m; ++jj) {
                    if (ii == i && jj == j) continue;
                    if (s[ii][jj] == '*') {
                        pos[ii + jj].eb(ii, jj);
                    }
                }
            }
            for (int k = 0; k < 20; ++k) if (pos[k].size()) {
                int mn = 1 << 30;
                for (pii i : pos[k]) {
                    mn = min(mn, dp[i.X][i.Y]);
                }
                dp[i][j] += mn;
                break;
            }
        }
    }
    cout << dp[0][0] << endl;
}