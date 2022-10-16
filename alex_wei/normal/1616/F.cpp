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

const int N = 64;
int T, n, m, c[N << 2], e[N][N];
void solve() {
	cin >> n >> m, mem(e, -1, N); vector <vint> a;
	for(int i = 0; i < m; i++) {
		int u = read() - 1, v = read() - 1, w = read();
		e[u][v] = e[v][u] = i, c[i] = w == -1 ? 3 : w;
		if(w != -1) {vint f(m + 1); f[i] = 1, f[m] = w, a.pb(f);}
	} for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			for(int k = j + 1; k < n; k++)
				if((~e[i][j]) && (~e[j][k]) && (~e[i][k])) {
					vint f(m + 1);
					f[e[i][j]] = f[e[j][k]] = f[e[i][k]] = 1, a.pb(f);
				}
	for(int i = 0, p = -1; i < a.size(); i++, p = -1) {
		for(int j = 0; j < m && p == -1; j++) if(a[i][j]) p = j;
		if(p == -1 && a[i][m]) return puts("-1"), void();
		if(p == -1) {swap(a[i], a.back()), a.pop_back(), i--; continue;}
		if(a[i][p] == 2) for(int &it : a[i]) it = (3 - it) % 3;
		for(int j = 0; j < a.size(); j++) if(i != j && a[j][p])
			for(int k = m; k >= p; k--) a[j][k] = (a[j][k] + a[i][k] * (3 - a[j][p])) % 3;
	} for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < m; j++)
			if(a[i][j]) {c[j] = a[i][m]; break;}
	for(int i = 0; i < m; i++) cout << (c[i] == 0 ? 3 : c[i]) << " "; cout << endl;
}
bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> T; while(T--) solve();
	return flush(), 0;
}