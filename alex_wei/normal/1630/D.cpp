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

template <class T1, class T2> void cmin(T1 &a, T2 b) {a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b) {a = a > b ? a : b;}

const int N = 1e6 + 5;

ll n, m, a[N], b[N], c[N], e[N], par[N];
bool sgn(int x) {return x >= 0;}
void solve() {
	n = read(), m = read(); ll d = 0, ans = 0; mem(par, 0, n + 2), mem(e, 0x3f, n + 2);
	for(int i = 1; i <= n; i++) a[i] = read(), ans += abs(a[i]); a[n + 1] = 0;
	for(int i = 1; i <= m; i++) b[i] = read(), d = __gcd(d, b[i]);
	for(int i = 1; i <= n + 1; i++) c[i] = sgn(a[i]) != sgn(a[i - 1]);
	for(int i = 1; i <= n + 1; i++) par[i % d == 0 ? d : i % d] ^= c[i];
	for(int i = 1; i <= n + 1; i++) {
		a[i] = abs(a[i]);
		if(i <= n) cmin(e[i % d == 0 ? d : i % d], a[i]);
		a[i] += a[i - 1];
	}
	for(int i = 1; i <= d; i++) par[d + i] = par[i], e[d + i] = e[i];
	ll ans1 = 0, ans2 = 0, fir = -1;
	for(int i = 1; i <= d; i++) {
		if(par[i]) {
			if(fir == -1) fir = i;
			ll nxt = i + 1, mn = e[i];
			while(!par[nxt]) mn += e[nxt++];
			cerr << mn << endl;
			ans1 += mn, i = nxt;
		}
	}
	if(fir != -1) {
		for(int i = fir + 1; i <= d; i++) {
			if(par[i]) {
				ll nxt = i + 1, mn = e[i];
				while(!par[nxt]) mn += e[nxt++];
				ans2 += mn, i = nxt;
			}
		}
	} cout << ans - min(ans1, ans2) * 2 << "\n";
}
int main() {
	int T; cin >> T;
	while(T--) solve();
	return 0;
}