#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 1000087, logN = 17, K = 333;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

lli dp[1001][2001];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, pa, pb;
    cin >> n >> pa >> pb;
    int al = pa + pb;
    pa = 1ll * pa * modpow(al, mod - 2) % mod;
    pb = 1ll * pb * modpow(al, mod - 2) % mod;
    dp[1][0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * pa) % mod;
            dp[i][j + i] = (dp[i][j + i] + dp[i][j] * pb) % mod;
        }
    }
    lli ans = 0, p = pa * modpow(1 + mod - pa, mod - 2) % mod;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n * 2; ++j) {
            if (j >= n) ans = (ans + dp[i][j] * j) % mod;
            else if (i == n) ans = (ans + dp[i][j] * (i + j + p)) % mod;
        }
    }
    cout << ans << endl;
}