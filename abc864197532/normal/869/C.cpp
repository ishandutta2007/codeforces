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
const int mod = 998244353, abc = 864197532, N = 100087, logN = 17, K = 333;

lli C[5001][5001];
lli fac[5001];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i <= 5000; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
    fac[0] = 1;
    for (int i = 1; i <= 5000; ++i) fac[i] = fac[i - 1] * i % mod;
    int a, b, c;
    cin >> a >> b >> c;
    lli ans = 1, al = 0;
    for (int i = 0; i <= min(a, b); ++i) {
        al += C[a][i] * C[b][i] % mod * fac[i];
        al %= mod;
    }
    ans = ans * al % mod;
    al = 0;
    for (int i = 0; i <= min(a, c); ++i) {
        al += C[a][i] * C[c][i] % mod * fac[i];
        al %= mod;
    }
    ans = ans * al % mod;
    al = 0;
    for (int i = 0; i <= min(b, c); ++i) {
        al += C[b][i] * C[c][i] % mod * fac[i];
        al %= mod;
    }
    cout << ans * al % mod << endl;
}