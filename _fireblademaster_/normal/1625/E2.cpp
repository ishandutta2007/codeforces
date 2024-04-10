#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
const int N = 700005;
int n, q;
char s[N];
int match[N];
vector<int> G[N];
int vis[N];
int id[N], fa[N];
int sta[N], top = 0;
int pre[N], is_l[N];

struct ctree {
	vector<ll> C;
	int lim;
	void init(int m) {
		C.resize(m + 1);
		for (int i = 0; i <= m; ++i) C[i] = 0;
		lim = m;
	}

	void update(int x, ll c) {
		while (x <= lim) {
			C[x] += c;
			x += (x & (-x));
		}
	}

	ll query(int x) {
		ll ans = 0;
		while (x) {
			ans += C[x];
			x -= (x & (-x));
		}
		return ans;
	}
}tr, T[N];

int dfn[N], tim = 0;
int deg[N];
ll func(int x) {
	return 1LL * x * (x + 1) / 2;
}

void dfs(int x) {
	dfn[x] = ++tim;
	deg[x] = sz(G[x]);
	tr.update(dfn[x], func(deg[x]));
	for (int i = 0; i < deg[x]; ++i) {
		int to = G[x][i];
		id[to] = i + 1;
		dfs(to);
	}
	T[x].init(deg[x]);
	for (int i = 1; i <= deg[x]; ++i) {
		T[x].update(i, 1);
	}
}

void init() {
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	top = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') {
			sta[++top] = i; 
		} else {
			if (top) {
				vis[sta[top]] = vis[i] = 1;
				--top;
			}
		}
	}
	tr.init(n + 5);
	top = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) continue;
		if (s[i] == '(') {
			fa[i] = sta[top];
			G[fa[i]].push_back(i);
			sta[++top] = i;
		} else {
			is_l[sta[top]] = i;
			match[sta[top]] = i;
			match[i] = sta[top--];
		}
	}
	dfs(0);
	for (int i = 0, p = 0; i <= n; ++i) {
		if (is_l[i]) p = i;
		pre[i] = p;
	}
}

ll calc(int l, int r) {
	int x = fa[l];
	int A = l, B = pre[r];
	int ql = T[x].query(id[l]), qr = T[x].query(id[match[r]]);
	ll ans = tr.query(dfn[B]) - tr.query(dfn[A] - 1);
	ans += func(qr - ql + 1);
	return ans;
}

void solve() {
	int t, l, r;
	while (q--) {
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			tr.update(dfn[l], -func(deg[l]));
			int x = fa[l];
			tr.update(dfn[x], -func(deg[x]));
			deg[x] -= 1;
			tr.update(dfn[x], func(deg[x]));
			T[x].update(id[l], -1);
		} else {
			printf("%lld\n", calc(l, r));
		}
	}
}

int main() {
	int t = 1;
#ifdef CASES_WITH_T
	scanf("%d", &t); 
#endif
	while (t--) {
		init();
		solve();
	}
	return 0;
}