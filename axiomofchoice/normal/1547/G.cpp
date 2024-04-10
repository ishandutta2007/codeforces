// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#define repeat(i, a, b) for (int i = (a), ib = (b); i < ib; i++)
#define repeat_back(i, a, b) for (int i = (b) - 1, ib = (a);i >= ib; i--)
#define mst(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define int ll
using namespace std;
namespace start {
	typedef long long ll; const int inf = INT_MAX >> 1; const ll INF = INT64_MAX >> 1;
	typedef double lf; const lf pi = acos(-1);
	typedef pair<int, int> pii;
	mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
		ll read() { ll x; if (scanf("%lld", &x) != 1) exit(0); return x; } // will detect EOF
		ll readfast() {
			ll x = 0, tag = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') tag = -1;
			for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; // ungetc(c, stdin);
			return x * tag;
		}
		template <typename T> void write(T x) {
			if (x < 0) x = -x, putchar('-');
			if (x >= 10) write(x / 10);
			putchar(x % 10 + 48);
		}
		void print(ll x, bool e = 0) { printf("%lld%c", x, " \n"[e]); }
		lf readf() { lf x; if (scanf("%lf",&x) != 1) exit(0); return x; } // will detect EOF
		void printlf(lf x, bool e = 0) { printf("%.12f%c", x, " \n"[e]); }
		template <typename T> vector<T> &operator<<(vector<T> &a, const T &b) { a.push_back(b); return a; }
		template <typename T> T sqr(const T &x) { return x*x; }
		// int cansel_sync = (ios::sync_with_stdio(0), cin.tie(0), 0);
		constexpr int bitlog(ll x) { return __lg(x); } // floor(log2(x))
		template <typename T> void sortunique(vector<T> &a) {
			sort(a.begin(), a.end());
			a.erase(unique(a.begin(), a.end()), a.end());
		}
	const int N = 1000010;
	const lf eps = 1e-9;
	const int mod = (1 ? 1000000007 : 998244353);
		int mul(int a, int b, int m = mod) { return 1ll * a * b % m; }
		int qpow(int a, ll b,int m = mod) {
			int ans = 1;
			for (; b; a = mul(a, a, m), b >>= 1) if (b & 1)
				ans = mul(ans, a, m);
			return ans;
		}
} using namespace start;
vector<int> a[N];
stack<int> stk;
bool vis[N], instk[N];
int dfn[N], low[N], co[N], w[N];
vector<int> sz;
int n, dcnt;
void dfs(int x) { // Tarjan
	vis[x] = instk[x] = 1; stk.push(x);
	dfn[x] = low[x] = ++dcnt;
	for(auto p : a[x]) {
		if (!vis[p]) dfs(p);
		if (instk[p]) low[x] = min(low[x], low[p]);
	}
	if (low[x] == dfn[x]) {
		int t; sz.push_back(0);
		do {
			t = stk.top();
			stk.pop();
			instk[t] = 0;
			sz.back() += w[x];
			co[t] = sz.size() - 1;
		} while (t != x);
	}
}
void getscc() {
	fill(vis, vis + n, 0);
	sz.clear();
	repeat (i, 0, n) if (!vis[i]) dfs(i);
}
void shrink() { // result: a, n (inplace)
	static set<pii> eset;
	eset.clear();
	getscc();
	repeat (i, 0, n)
	for (auto p : a[i])
	if (co[i] != co[p])
		eset.insert({co[i], co[p]});
	n = sz.size();
	repeat (i, 0, n){
		a[i].clear();
		w[i] = sz[i];
	}
	for(auto i : eset){
		a[i.fi].push_back(i.se);
		// a[i.se].push_back(i.fi);
	}
}
int ans[N];
void ddfs(int x) {
	vis[x] = 1; ans[x] = 0;
	if (x == co[0]) { ans[x] = (w[x] >= 2 ? -1 : 1); return; }
	int infty = 0, cnt = 0;
	for (auto p : a[x]) {
		if (!vis[p]) ddfs(p);
		if (ans[p] == -1) infty = 1;
		if (ans[p] == 2) cnt = 2;
		if (ans[p] == 1) cnt++;
	}
//	orz(x, infty, cnt, w[x]);
	if (cnt && w[x] >= 2) infty = 1;
	if (infty) ans[x] = -1; else ans[x] = min(cnt, 2ll);
}
void Solve() {
	int n0 = n = read(); int m = read();
	fill (w, w + n, 1);
	repeat (i, 0, n) a[i].clear();
	repeat (i, 0, m) {
		int x = read() - 1, y = read() - 1;
		if (x == y) w[x] = 2;
		else a[y].push_back(x);
	}
//	orzarr(w, n);
	shrink();
//	repeat (i, 0, n) {
//		cout << i << ": ";
//		orz(a[i]);
//	}
//	orz(sz);
//	orzarr(co, n0);
	fill (vis, vis + n, 0);
	repeat (i, 0, n) if (!vis[i]) ddfs(i);
	repeat (i, 0, n0) print(ans[co[i]], i == n0 - 1);
}
signed main() {
	// freopen("data.txt", "r", stdin);
	int T = 1; T = read();
	repeat (ca, 1, T + 1) {
		Solve();
	}
	return 0;
}