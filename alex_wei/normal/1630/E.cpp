
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
 	#define gc getchar()
//	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
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

const int N = 1e6 + 5;
const int mod = 998244353;
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	} return s;
}
int n, d, f[N], g[N], cnt[N], fc[N], ifc[N];
vector <int> buc;
int bin(int n, int m) {return 1ll * fc[n] * ifc[m] % mod * ifc[n - m] % mod;}
int main() {
	for(int i = fc[0] = 1; i < N; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
	ifc[N - 1] = ksm(fc[N - 1], mod - 2);
	for(int i = N - 2; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % mod;
	int T = read(), s1, s2;
	while(T--) {
		cin >> n, d = n, s1 = s2 = 0;
		mem(f, 0, n + 1), mem(g, 0, n + 1), mem(cnt, 0, n + 1), buc.clear();
		for(int i = 1; i <= n; i++) cnt[read()]++;
		for(int i = 1; i <= n; i++) if(cnt[i]) buc.pb(cnt[i]), d = __gcd(d, cnt[i]);
		if(buc.size() == 1) {puts("1"); continue;}
		for(int i = 1; i <= d; i++) if(d % i == 0) {
			int L = n / i, sum = 0; f[L] = fc[L];
			for(int it : buc) f[L] = 1ll * f[L] * ifc[it / i] % mod;
			for(int it : buc) g[L] = (g[L] + 1ll * (it / i) * sum) % mod, sum = (sum + it / i) % mod;
			g[L] = 1ll * g[L] * f[L] % mod * ksm(1ll * (L - 1) * L % mod, mod - 2) % mod * n * 2 % mod;
		} for(int i = 1; i <= n; i++) s1 = (s1 + f[__gcd(n, i)]) % mod, s2 = (s2 + g[__gcd(n, i)]) % mod;
		cout << 1ll * s2 * ksm(s1, mod - 2) % mod << "\n";
	}
	return flush(), 0;
}