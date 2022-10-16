#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define i128 __int128
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>
#define pll pair <ll, ll>
#define pii pair <int, int>

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

bool Mbe;
namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
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

const int N = 1 << 18;
const int mod = 998244353;
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	} return s;
}

int pre, r[N];
void init(int n) {
	if(pre != n) {
		for(int i = 0; i < n; i++) r[i] = (r[i >> 1] >> 1) | (i & 1 ? n >> 1 : 0);
	} pre = n;
}
void DFT(vint &a, int op, int n) {
	static ull w[N], f[N]; w[0] = 1, init(n);
	for(int i = 0; i < n; i++) f[i] = a[r[i]];
	for(int l = 1; l < n; l <<= 1) {
		int ww = ksm(op ? 3 : (mod + 1) / 3, mod / l / 2);
		for(int i = 1; i < l; i++) w[i] = w[i - 1] * ww % mod;
		for(int i = 0; i < n; i += l << 1)
			for(int j = 0; j < l; j++) {
				int y = f[i | j | l] * w[j] % mod;
				f[i | j | l] = f[i | j] - y + mod, f[i | j] += y;
			}
		if(l == 1 << 16) for(int i = 0; i < n; i++) f[i] %= mod;
	} if(!op) {
		int iv = ksm(n, mod - 2);
		for(int i = 0; i < n; i++) a[i] = f[i] % mod * iv % mod;
	} else for(int i = 0; i < n; i++) a[i] = f[i] % mod;
}

void NTT(vint &x, vint &y) {
	int len = x.size() + y.size() - 1;
	int n = 1 << (int)log2(len - 1) + 1; vint z(n, 0);
	x.resize(n), y.resize(n), DFT(x, 1, n), DFT(y, 1, n);
	for(int i = 0; i < n; i++) y[i] = 1ll * x[i] * y[i] % mod;
	DFT(y, 0, n), y.resize(len);
}

int n, m, ans, deg[N], fc[N];
vint f[N];
void solve(int l, int r) {
	if(l == r) return;
	int m = l + r >> 1;
	solve(l, m), solve(m + 1, r), NTT(f[m], f[r]);
	
}

bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n, fc[0] = 1;
	for(int i = 1; i <= n; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
	for(int i = 1, u, v; i < n; i++) deg[read()]++, deg[read()]++;
	f[1].pb(1), f[1].pb(deg[1]), m = 1;
	for(int i = 2; i <= n; i++) if(deg[i] > 1)
		f[++m].pb(1), f[m].pb(deg[i] - 1);
	solve(1, m);
	for(int i = 0; i <= m; i++) {
		int coef = 1ll * f[m][i] * fc[n - i] % mod;
		ans = (ans + (i & 1 ? mod - coef : coef)) % mod;
	} cout << ans << "\n";
	return cerr << "Time : " << clock() << endl, flush(), 0;
}