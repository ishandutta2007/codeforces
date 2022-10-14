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
const int mod = 1e9 + 7, abc = 864197532, N = 100005, logN = 20, K = 333;

lli dp[2001][2001], unb[2001];
bool rain[2000];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0, l, r; i < k; ++i) {
        cin >> l >> r;
        for (int j = l; j < r; ++j) {
            rain[j] = true;
        }
    }
    for (int i = 0; i <= n; ++i) unb[i] = 0;
    vector <pii> a(m + 1, mp(0, 0));
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].X >> a[i].Y;
        if (!unb[a[i].X] || a[unb[a[i].X]].Y > a[i].Y) unb[a[i].X] = i;
    }
    for (int j = 0; j <= n; ++j) {
        for (int i = 0; i <= m; ++i) {
            dp[j][i] = 1ll << 60;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            // no change
            int nxt = j;
            if (!rain[i] || nxt) {
                dp[i + 1][nxt] = min(dp[i + 1][nxt], dp[i][j] + a[nxt].Y);
            }
            // change
            nxt = unb[i];
            if (!rain[i] || nxt) {
                dp[i + 1][nxt] = min(dp[i + 1][nxt], dp[i][j] + a[nxt].Y);
            }
            // change to 0
            nxt = 0;
            if (!rain[i] || nxt) {
                dp[i + 1][nxt] = min(dp[i + 1][nxt], dp[i][j] + a[nxt].Y);
            }
        }
    }
    lli ans = 1ll << 60;
    for (int i = 0; i <= m; ++i) ans = min(ans, dp[n][i]);
    cout << (ans >= 1ll << 40 ? -1 : ans) << endl;
}