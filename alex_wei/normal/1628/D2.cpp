//#pragma GCC optimize(3)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int, int>
#define pll pair <ll, ll>
#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x), end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define FileI(x) freopen(x, "r", stdin)
#define FileO(x) freopen(x, "w", stdout)
#define y1 y_chenxiaoyan_1

bool Mbe;
namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
// 	#define gc getchar()
	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
		ll x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return sgn ? -x : x;
	}
	template <class T>
		inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
	template <class T>
		inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int mod = 1e9 + 7;
void add(ll &x, ll y) {x = (x + y) % mod;}

ll ksm(ll a, ll b) {
	ll s = 1;
	while(b) {
		if(b & 1) s = s * a % mod;
		a = a * a % mod, b >>= 1;
	} return s;
}

const int N = 1e6 + 5;
ll n, m, k, fc[N], ifc[N];
ll bin(int n, int m) {return n < m ? 0 : fc[n] * ifc[m] % mod * ifc[n - m] % mod;}
void solve() {
	ll ans = 0; cin >> n >> m >> k;
	if(n == m) return cout << m * k % mod << endl, void();
	for(int i = 1; i <= m; i++) add(ans, 1ll * i * k % mod * ksm(ksm(2, n - i), mod - 2) % mod * bin(n - i - 1, m - i));
	cout << ans << endl;
}

bool Med;
int main() {
	for(int i = fc[0] = 1; i < N; i++) fc[i] = fc[i - 1] * i % mod;
	ifc[N - 1] = ksm(fc[N - 1], mod - 2);
	for(int i = N - 2; ~i; i--) ifc[i] = ifc[i + 1] * (i + 1) % mod;
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	int T; cin >> T;
	while(T--) solve();
	return flush(), 0;
} //