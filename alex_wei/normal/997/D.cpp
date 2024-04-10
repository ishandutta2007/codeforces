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
	int read() {
		int x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return sgn ? -x : x;
	}
	char rdc() {char s = gc; while(!isalpha(s)) s = gc; return s;}
	char rdd() {char s = gc; while(!isdigit(s)) s = gc; return s;}
	template <class T>
		void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
	template <class T>
		void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int N = 1e4 + 5;
const int K = 75 + 5;
const int mod = 998244353;
void add(int &u, int v) {u += v, u >= mod && (u -= mod);}
int n, m, k, fc[K], C[K][K];

struct Tree {
	int sz, g[N][K], S[N][K], out[N][K], f[N][K]; vint e[N];
	void ad(int u, int v) {e[u].pb(v), e[v].pb(u);}
	void dfs1(int id, int fa) {
		g[id][0] = 1;
		for(int it : e[id]) if(it != fa) dfs1(it, id);
		for(int i = 2; i <= k; i += 2)
			for(int p = 0; p < i; p += 2) for(int it : e[id]) if(it != fa)
				add(g[id][i], 1ll * g[id][p] * g[it][i - p - 2] % mod);
		for(int i = 0; i <= k; i += 2)
			for(int it : e[id]) if(it != fa) add(S[id][i], g[it][i]);
	} void dfs2(int id, int fa) {
		if(fa) {
			out[id][0] = 1;
			for(int i = 2; i <= k; i += 2)
				for(int p = 0; p < i; p += 2) {
					int coef = out[fa][i - p - 2];
					add(out[id][i], 1ll * out[id][p] * coef % mod);
					coef = S[fa][i - p - 2] + mod - g[id][i - p - 2];
					add(out[id][i], 1ll * out[id][p] * coef % mod);
				}
		} for(int it : e[id]) if(it != fa) dfs2(it, id);
		f[id][0] = 1;
		for(int i = 2; i <= k; i += 2)
			for(int p = 0; p < i; p += 2) 
				for(int it : e[id])	{
					int coef = it == fa ? out[id][i - p - 2] : g[it][i - p - 2];
					add(f[id][i], 1ll * f[id][p] * coef % mod);
				}
	}
	void init() {dfs1(1, 0), dfs2(1, 0);}
} T1, T2;

bool Med;
int main() { /////////////
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n >> m >> k, T1.sz = n, T2.sz = m;
	if(k == 1) puts("0"), exit(0);
	for(int i = fc[0] = 1; i < K; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
	for(int i = 0; i < K; i++) for(int j = 0; j <= i; j++)
		C[i][j] = j == 0 || j == i ? 1 : (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	for(int i = 1; i < n; i++) T1.ad(read(), read());
	for(int i = 1; i < m; i++) T2.ad(read(), read());
	T1.init(), T2.init();
	for(int i = k, ans = 0; i <= k; i++, ans = 0) {
		if(i & 1) {cout << "0 "; continue;}
		static int f[K]; mem(f, 0, K);
		for(int q = 1; q <= m; q++)
			for(int l = 0; l <= i; l += 2)
				add(f[l], T2.f[q][l]);
		for(int p = 1; p <= n; p++)
			for(int l = 0; l <= i; l += 2)
				add(ans, 1ll * T1.f[p][l] * f[i - l] % mod * C[i][l] % mod);
		cout << ans << ' ';
	}
	return flush(), 0;
}