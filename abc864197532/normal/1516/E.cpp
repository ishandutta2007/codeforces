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
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 487, logN = 18;

lli dp[N][N], C[N][N], fac[N], inv[N];

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

lli bfC(int n, int k) {
    lli ans = 1;
    for (int i = n; i >= n - k + 1; --i) {
        ans = ans * i % mod;
    }
    for (int i = 1; i <= k; ++i) ans = ans * inv[i] % mod;
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fac[0] = 1;
    C[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = modpow(i, mod - 2);
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= mod) C[i][j] -= mod;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int k = 2; k <= i; ++k) {
                dp[i][j] = (dp[i][j] + C[i - 1][k - 1] * fac[k - 1] % mod * dp[i - k][j - 1]) % mod;
            }
        }
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        lli ans = 0;
        if (i & 1 ^ 1) ans = 1;
        for (int sz = 2; sz <= min(n, 400); ++sz) {
            lli res = 0;
            for (int j = sz - (i & 1), cnt = 0; j > 0 && cnt <= i; j -= 2, cnt += 2) {
                res = (res + dp[sz][j]) % mod;
            }
            (ans += bfC(n, sz) * res) %= mod;
        }
        cout << ans << ' ';
    }
    cout << endl;
}