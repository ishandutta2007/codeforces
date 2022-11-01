#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int INF = 1e9, maxn = 1e6;

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
     
/** Read */
     
static const int buf_size = 4096;
     
inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
     
inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
    return c;
}
     
template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

struct segTree {
	segTree() {}
	struct node {
		int sum, val;
	};
	vector<node> t;
	void build(int v, int l, int r) {
		if(l == r) {
			t[v].val = -1;
			t[v].sum = 1;
		} else {
			int m = (l + r) >> 1;
			build(v * 2 + 1, l, m);
			build(v * 2 + 2, m + 1, r);
			t[v].val = -1;
			t[v].sum = t[v * 2 + 1].sum + t[v * 2 + 2].sum;
		}
	}
	void push(int v) {
		if(!t[v].val) {
			t[v * 2 + 1].val = t[v * 2 + 1].sum = t[v * 2 + 2].val = t[v * 2 + 2].sum = 0;
			t[v].val = -1;
		}
	}
	int get(int v, int l, int r, int l1, int r1) {
		if(r < l1 || r1 < l) return 0;
		if(l1 <= l && r <= r1) return t[v].sum;
		push(v);
		int m = (l + r) >> 1;
		return get(v * 2 + 1, l, m, l1, r1) + get(v * 2 + 2, m + 1, r, l1, r1);
	}
	void upd(int v, int l, int r, int l1, int r1) {
		if(r < l1 || r1 < l) return;
		if(l1 <= l && r <= r1) {
			t[v].val = t[v].sum = 0;
			return;
		}
		push(v);
		int m = (l + r) >> 1;
		upd(v * 2 + 1, l, m, l1, r1);
		upd(v * 2 + 2, m + 1, r, l1, r1);
		t[v].sum = t[v * 2 + 1].sum + t[v * 2 + 2].sum;
	}
};

int n, k, hed[maxn], len[maxn], tsz[maxn], dep[maxn], up[maxn][20], tin[maxn], tout[maxn], tik_tak, top[maxn];
vector<int> g[maxn];

void dfs(int v, int p) {
	tin[v] = tik_tak++;
	up[v][0] = p;
	for(int i = 1; i < 20; i++) up[v][i] = up[up[v][i - 1]][i - 1];
	tsz[v] = 1;
	for(int to : g[v]) if(to != p) {
		dep[to] = dep[v] + 1;
		dfs(to, v);
		tsz[v] += tsz[to];
	}
	hed[v] = v;
	len[v] = 1;
	int kid = -1;
	for(int to : g[v]) if(to != p && 2 * tsz[to] >= tsz[v]) kid = to;
	if(kid != -1) {
		hed[v] = hed[kid];
		len[hed[v]]++;
	}
	tout[v] = tik_tak++;
}

inline bool upper(int u, int v) {
	return tin[u] < tin[v] && tout[u] > tout[v];
}

inline int lca(int u, int v) {
	if(tin[u] > tin[v]) swap(u, v);
	if(u == v || upper(u, v)) return u;
	for(int i = 19; i >= 0; i--)
		if(!upper(up[u][i], v))
			u = up[u][i];
	return up[u][0];
}

segTree rt[maxn];

inline int get(int u, int v) {
	int ret = 0;
	while(hed[u] != hed[v]) {
		ret += rt[hed[v]].get(0, 0, len[hed[v]] - 1, dep[hed[v]] - dep[v], len[hed[v]] - 1);
		v = up[top[hed[v]]][0];
	}
	return ret + rt[hed[u]].get(0, 0, len[hed[u]] - 1, dep[hed[u]] - dep[v], dep[hed[u]] - dep[u]);
}

inline int upd(int u, int v) {
	while(hed[u] != hed[v]) {
		rt[hed[v]].upd(0, 0, len[hed[v]] - 1, dep[hed[v]] - dep[v], len[hed[v]] - 1);
		v = up[top[hed[v]]][0];
	}
	rt[hed[u]].upd(0, 0, len[hed[u]] - 1, dep[hed[u]] - dep[v], dep[hed[u]] - dep[u]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	n = readInt();
	k = readInt();
	for(int i = 0; i < n - 1; i++) {
		int u = readInt(), v = readInt();
		u--; v--;
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(0, 0);
	for(int u = 0; u < n; u++) if(hed[u] == u) {
		rt[u].t.resize(4 * len[u]);
		rt[u].build(0, 0, len[u] - 1);
	}
	k = n - k;
	memset(top, -1, sizeof(top));
	for(int i = 0; i < n; i++) if(top[hed[i]] == -1 || dep[i] < dep[top[hed[i]]]) top[hed[i]] = i;
	vector<bool> ok(n, false);
	for(int i = n - 1; i >= 0; i--) {
		int u = n - 1, v = i;
		int w = lca(u, v);
		int x = get(w, u) + get(w, v) - get(w, w);
		if(x <= k) {
			k -= x;
			upd(w, u);
			upd(w, v);
			ok[i] = true;
		}
	}
	for(int i = 0; i < n; i++) if(!ok[i]) cout << i + 1 << ' ';
}