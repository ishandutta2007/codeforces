/*
                _____________   ______________       __
               / _________  /\ /_____   _____/\     / /\
              / /\       / /  \\    /  /\    \ \   / /  \
             / /  \_____/ /   / \__/  /  \____\/  / /   /
            / /   /    / /   /    /  /   /       / /   /
           / /   /    / /   /    /  /   /       / /   /
          / /   /    / /   /    /  /   /       / /   /
         / /___/____/ /   /    /  /   /       / /___/________
        /____________/   /    /__/   /       /______________/\
        \            \  /     \  \  /        \              \ \
         \____________\/       \__\/          \______________\/
           ___       ___      ___      ___    ______________
          /  /\     /  /\    /  /\    /  /\  /_____   _____/\
         /  /__\___/  /  \  /  /  \  /  /  \ \    /  /\    \ \
        /____    ____/   / /  /   / /  /   /  \__/  /  \____\/
        \   /   /\   \  / /  /_____/  /   /     /  /   /
         \_/   /  \___\/ /   _____   /   /     /  /   /
          /   /   /     /  /\    /  /   /     /  /   /
         /   /   /     /  /  \__/  /   /     /  /   /
        /___/   /     /__/   / /__/   /     /__/   /
        \   \  /      \  \  /  \  \  /      \  \  /
         \___\/        \__\/    \__\/        \__\/

          A FAN OF YHT

*/
/*
_/_/_/_/    _/_/_/_/_/  _/_/_/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/  _/  _/
_/      _/  _/  _/    _/    _/_/
_/_/_/_/      _/_/     _/_/_/_/_/

_/_/_/_/    _/    _/  _/      _/
_/      _/   _/  _/   _/_/  _/_/
_/      _/    _/_/    _/ _/_/ _/
_/      _/     _/     _/  _/  _/
_/      _/    _/_/    _/      _/
_/      _/   _/  _/   _/      _/
_/_/_/_/    _/    _/  _/      _/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
% djq dxm
*/
#include <bits/stdc++.h>
using namespace std;
//Fast IO start
namespace io {
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE + 1], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE + 1], *os = obuf, *ot = obuf + BUFSIZE;
	inline char read_char() {
		if (is == it) {
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
			if (is == it) *it++ = EOF;
		}
		return *is++;
	}
	template <class T>
	inline void read_int(T &x) {
		T f = 1;
		char c = read_char();
		while (!isdigit(c)) {
			if (c == '-') f = -1;
			c = read_char();
		}
		x = 0;
		while (isdigit(c)) {
			x = x * 10 + c - '0';
			c = read_char();
		}
		x *= f;
	}
	inline void read_str(char *s) {
		char c = read_char();
		while (c <= ' ') {
			c = read_char();
		}
		while (c > ' ') {
			*s++ = c;
			c = read_char();
		}
		*s = 0;
	}
	inline void flush() {
		fwrite(obuf, 1, os - obuf, stdout);
		os = obuf;
	}
	inline void print_char(char c) {
		*os++ = c;
		if (os == ot) {
			flush();
		}
	}
	template <class T>
	inline void print_int(T x, char c = 0) {
		static char q[40];
		if (!x) {
			print_char('0');
		} else {
			if (x < 0) {
				print_char('-');
				x = -x;
			}
			int top = 0;
			while (x) {
				q[top++] = x % 10 + '0';
				x /= 10;
			}
			while (top--) {
				print_char(q[top]);
			}
		}
		if (c) print_char(c);
	}
	inline void print_str(char *s, char c = 0) {
		while (*s) {
			print_char(*s++);
		}
		if (c) print_char(c);
	}
	struct flusher_t {
		inline ~flusher_t() {
			flush();
		}
	} flusher;
}
using io::read_char;
using io::read_int;
using io::read_str;
using io::print_char;
using io::print_int;
using io::print_str;
//Fast IO end
const int N = 300005;
const int LOGN = 19;
struct Graph {
	int n, m;
	vector<int> V;
	vector<pair<int, int> > E[N];
} ori, tr, qg;
namespace TJ {
int dfn[N], low[N], vis[N], bel[N], dfc, tot;
vector<int> bridge;
void dfs(const Graph &G, int u, int fid) {
	dfn[u] = low[u] = ++dfc;
	for (int i = 0; i < (int)G.E[u].size(); i++) {
		int v = G.E[u][i].first, id = G.E[u][i].second;
		if (!dfn[v]) {
			dfs(G, v, id);
			low[u] = min(low[u], low[v]);
			if (dfn[u] < low[v]) bridge[id] = 1;
		} else if (id != fid) {
			low[u] = min(low[u], dfn[v]);
		}
	}
}
void ff(const Graph &G, int u, int k) {
	bel[u] = k;
	vis[u] = 1;
	for (int i = 0; i < (int)G.E[u].size(); i++) {
		int v = G.E[u][i].first, id = G.E[u][i].second;
		if (!bridge[id] && !vis[v]) ff(G, v, k);
	}
}
inline void solve(const Graph &G) {
	bridge.resize(G.m + 1);
	for (int i = 1; i <= G.m; i++) bridge[i] = 0;
	for (int i = 0; i < (int)G.V.size(); i++) {
		int u = G.V[i];
		dfn[u] = vis[u] = 0;
	}
	dfc = 0;
	for (int i = 0; i < (int)G.V.size(); i++) {
		int u = G.V[i];
		if (!dfn[u]) {
			dfs(G, u, 0);
		}
	}
	tot = 0;
	for (int i = 0; i < (int)G.V.size(); i++) {
		int u = G.V[i];
		if (!vis[u]) {
			++tot;
			ff(G, u, tot);
		}
	}
}
inline void gettr(const Graph &G, Graph &ret) {
	solve(G);
	ret.n = tot;
	ret.m = 0;
	for (int _ = 0; _ < (int)G.V.size(); _++) {
		int u = G.V[_];
		for (int i = 0; i < (int)G.E[u].size(); i++) {
			int v = G.E[u][i].first;
			if (bel[u] < bel[v]) {
				++ret.m;
				ret.E[bel[u]].push_back(make_pair(bel[v], ret.m));
				ret.E[bel[v]].push_back(make_pair(bel[u], ret.m));
			}
		}
	}
}
}
namespace TR {
int pa[LOGN][N], dep[N], dfn[N], rt[N], vis[N], dfc;
inline bool cmp(int u, int v) {
	return dfn[u] < dfn[v];
}
inline int LCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 0; i < LOGN; i++) if ((dep[u] - dep[v]) >> i & 1) u = pa[i][u];
	if (u == v) return u;
	for (int i = LOGN - 1; ~i; i--) if (pa[i][u] != pa[i][v]) u = pa[i][u], v = pa[i][v];
	return pa[0][u];
}
void dfs(int u, int lst, int depth, int rot) {
	pa[0][u] = lst;
	for (int i = 1; i < LOGN; i++) pa[i][u] = pa[i - 1][pa[i - 1][u]];
	dep[u] = depth;
	dfn[u] = ++dfc;
	rt[u] = rot;
	vis[u] = 1;
	for (int i = 0; i < (int)tr.E[u].size(); i++) {
		int v = tr.E[u][i].first;
		if (v == lst) continue;
		dfs(v, u, depth + 1, rot);
	}
}
int stk[N];
inline void getVT(vector<int> &V) {
	sort(V.begin(), V.end(), cmp);
	V.resize(unique(V.begin(), V.end()) - V.begin());
	vector<int> tmp;
	for (int i = 0, j; i < (int)V.size(); i = j) {
		int tp = 0;
		for (j = i; j < (int)V.size() && rt[V[i]] == rt[V[j]]; j++) {
			int u = V[j];
			if (!tp) { stk[++tp] = u; continue; }
			int lca = LCA(u, stk[tp]);
			tmp.push_back(lca);
			while (dfn[lca] < dfn[stk[tp]]) {
				if (dfn[lca] >= dfn[stk[tp - 1]]) {
					++qg.m;
					qg.E[lca].push_back(make_pair(stk[tp], qg.m));
					qg.E[stk[tp]].push_back(make_pair(lca, qg.m));
					if (stk[--tp] != lca) stk[++tp] = lca;
					break;
				}
				++qg.m;
				qg.E[stk[tp - 1]].push_back(make_pair(stk[tp], qg.m));
				qg.E[stk[tp]].push_back(make_pair(stk[tp - 1], qg.m));
				tp--;
			}
			stk[++tp] = u;
		}
		while (tp > 1) {
			++qg.m;
			qg.E[stk[tp - 1]].push_back(make_pair(stk[tp], qg.m));
			qg.E[stk[tp]].push_back(make_pair(stk[tp - 1], qg.m));
			tp--;
		}
	}
	for (int i = 0; i < (int)tmp.size(); i++) V.push_back(tmp[i]);
	sort(V.begin(), V.end());
	V.resize(unique(V.begin(), V.end()) - V.begin());
}
inline void Init() {
	for (int i = 1; i <= tr.n; i++) if (!vis[i]) {
		dfs(i, 0, 0, i);
	}
}
}
int main() {
	int Q;
	read_int(ori.n);
	read_int(ori.m);
	read_int(Q);
	for (int i = 1; i <= ori.n; i++) ori.V.push_back(i);
	for (int i = 1; i <= ori.m; i++) {
		int u, v;
		read_int(u);
		read_int(v);
		ori.E[u].push_back(make_pair(v, i));
		ori.E[v].push_back(make_pair(u, i));
	}
	TJ::gettr(ori, tr);
	vector<int> obel(TJ::bel, TJ::bel + ori.n + 1);
	TR::Init();
	vector<int> V, QV;
	int yhtioiakwenle = 0, djqdxmtietie = 0;
	qg.n = tr.n;
	while (Q--) {
		qg.m = 0;
		int n1, m1;
		read_int(n1);
		read_int(m1);
		V.clear();
		QV.clear();
		for (int i = 1; i <= n1; i++) {
			int u;
			read_int(u);
			u = obel[(u + yhtioiakwenle - 1) % ori.n + 1];
			V.push_back(u);
			QV.push_back(u);
		}
		for (int i = 1; i <= m1; i++) {
			int u, v;
			read_int(u);
			u = obel[(u + yhtioiakwenle - 1) % ori.n + 1];
			read_int(v);
			v = obel[(v + yhtioiakwenle - 1) % ori.n + 1];
			if (u != v) {
				++qg.m;
				qg.E[u].push_back(make_pair(v, qg.m));
				qg.E[v].push_back(make_pair(u, qg.m));
			}
			V.push_back(u);
			V.push_back(v);
		}
		TR::getVT(V);
		qg.V.swap(V);
		TJ::solve(qg);
		int ok = 1;
		for (int i = 1; i < (int)QV.size(); i++) {
			int u = QV[i];
			if (TJ::bel[u] != TJ::bel[QV[0]]) {
				ok = 0;
				break;
			}
		}
		djqdxmtietie++;
		if (ok) {
			print_char('Y');
			print_char('E');
			print_char('S');
			print_char('\n');
			yhtioiakwenle = (yhtioiakwenle + djqdxmtietie) % ori.n;
		} else {
			print_char('N');
			print_char('O');
			print_char('\n');
		}
		for (int i = 0; i < (int)qg.V.size(); i++) {
			int u = qg.V[i];
			qg.E[u].clear();
		}
	}
	return 0;
}