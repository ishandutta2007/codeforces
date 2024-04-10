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
const int mod = 998244353, abc = 864197532, N = 300087, K = 111, logN = 18;

lli dp[N][2], pw[N], cnt[N][2];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw[0] = 1;
    pw[1] = 2;
    cnt[1][0] = cnt[1][1] = 1;
    for (int i = 2; i < N; ++i) {
        dp[i][0] = (dp[i - 1][1] * 2 + cnt[i - 1][1] + dp[i - 1][0]) % mod;
        dp[i][1] = dp[i - 1][0];
        cnt[i][0] = (cnt[i - 1][1] * 2 + cnt[i - 1][0]) % mod;
        cnt[i][1] = cnt[i - 1][0];
        pw[i] = pw[i - 1] * 2 % mod;
    }
    int n, m;
    cin >> n >> m;
    string s[n];
    int cnt = 0;
    for (int i = 0; i < n; ++i) cin >> s[i], cnt += count(all(s[i]), 'o');
    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        int now = 0;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'o') {
                now++;
            } else {
                (ans += (dp[now][0] + dp[now][1]) * pw[cnt - now]) %= mod;
                now = 0;
            }
        }
        (ans += (dp[now][0] + dp[now][1]) * pw[cnt - now]) %= mod;
    }
    for (int j = 0; j < m; ++j) {
        int now = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i][j] == 'o') {
                now++;
            } else {
                (ans += (dp[now][0] + dp[now][1]) * pw[cnt - now]) %= mod;
                now = 0;
            }
        }
        (ans += (dp[now][0] + dp[now][1]) * pw[cnt - now]) %= mod;
    }
    cout << ans;
}