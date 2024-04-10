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
}
using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

int mod;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	}
	return s;
}

constexpr int N = 2e3 + 5;
int n, f[N][N], s[N][N], g[N][N];
int F[N], C[N][N];
vector<int> e[N], son[N];
void dfs(int id, int ff) {
	f[id][0] = s[id][0] = 1;
	for(int it : e[id]) {
		if(it == ff) continue;
		son[id].push_back(it);
		dfs(it, id);
	}
	for(int k = 0; k <= n; k++) {
		int prod = 1;
		for(int it : son[id]) prod = 1ll * prod * s[it][k] % mod;
		static int pre[N], suf[N];
		int L = son[id].size();
		pre[0] = suf[L + 1] = 1;
		for(int i = 1; i <= L; i++) {
			pre[i] = 1ll * pre[i - 1] * s[son[id][i - 1]][k] % mod;
		}
		for(int i = L; i; i--) {
			suf[i] = 1ll * suf[i + 1] * s[son[id][i - 1]][k] % mod;
			g[son[id][i - 1]][k] = 1ll * pre[i - 1] * suf[i + 1] % mod;
		}
	}
	for(int it : son[id]) 
		for(int k = 1; k <= n; k++)
			add(g[it][k], g[it][k - 1]);
	for(int k = 1; k <= n; k++) {
		int prod = 1;
		for(int it : son[id]) prod = 1ll * prod * s[it][k] % mod;
		add(f[id][k], prod);
		for(int it : son[id]) {
			int coef = f[it][k];
			coef = 1ll * coef * g[it][k - 1] % mod;
			add(f[id][k], coef);
		}
	}
	for(int i = 1; i <= n; i++) {
		s[id][i] = s[id][i - 1];
		add(s[id][i], f[id][i]);
	}
}
void solve() {
	cin >> n >> mod;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= i; j++) {
			if(!j) C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1], add(C[i][j], C[i - 1][j]);
		}
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i < n; i++) {
		F[i] = 1;
		for(int it : son[1]) F[i] = 1ll * F[i] * s[it][i - 1] % mod;
	}
	for(int i = 1; i < n; i++) {
		int ans = 0;
		for(int j = 1; j <= i; j++) {
			int coef = 1ll * C[i][j] * F[j] % mod;
			if(i - j & 1) add(ans, mod - coef);
			else add(ans, coef);
		}
		cout << ans << " ";
	}
	cout << endl;
}
int main() {
	int T = 1;
//	cin >> T;
	while(T--) solve();
	return 0;
}