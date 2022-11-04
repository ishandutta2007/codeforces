#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int n, q, ver[N], go[N][26], pa[N], len[N], tot, sz[N], son[N], top[N], dfn[N], dfc, pos[N];
char s[N];
vector<int> G[N];
int extend(int p, int x) {
	int np = ++tot;
	len[np] = len[p] + 1;
	while (p && !go[p][x]) {
		go[p][x] = np;
		p = pa[p];
	}
	if (!p) pa[np] = 1;
	else {
		int q = go[p][x];
		if (len[q] == len[p] + 1) pa[np] = q;
		else {
			int nq = ++tot;
			len[nq] = len[p] + 1;
			memcpy(go[nq], go[q], sizeof(go[q]));
			pa[nq] = pa[q];
			pa[q] = pa[np] = nq;
			while (p && go[p][x] == q) {
				go[p][x] = nq;
				p = pa[p];
			}
		}
	}
	return np;
}
void dfs1(int u) {
	sz[u] = 1;
	for (int v : G[u]) {
		dfs1(v);
		sz[u] += sz[v];
		if (sz[son[u]] < sz[v]) son[u] = v;
	}
}
void dfs2(int u, int tp) {
	top[u] = tp;
	pos[dfn[u] = ++dfc] = u;
	if (son[u]) {
		dfs2(son[u], tp);
	}
	for (int v : G[u]) if (v != son[u]) {
		dfs2(v, v);
	}
}
struct Event {
	int i, len, tim;
};
vector<Event> ev[N];
void add_event(int i) {
	int x = ver[i];
	while (x > 1) {
		int y = top[x];
		ev[y].push_back((Event){i, len[x] - len[pa[y]], i + len[pa[y]]});
		x = pa[y];
	}
}
struct Query {
	int i, len, id;
};
vector<Query> q1[N], q2[N];
long long ans[N];
void add_query(int l, int r, int id) {
	int x = ver[l];
	while (x > 1) {
		int y = top[x];
		if (len[pa[y]] < r - l + 1) {
			q1[y].push_back((Query){l - 1, min(len[x], r - l + 1) - len[pa[y]], id});
			q2[y].push_back((Query){r + 1, min(len[x], r - l + 1) - len[pa[y]], id});
		}
		x = pa[y];
	}
}
int bit0[N];
long long bit1[N];
void bit_add(int x) {
	int i = x;
	while (i <= tot) {
		bit0[i]++;
		bit1[i] += x;
		i += i & -i;
	}
}
void bit_clear(int i) {
	while (i <= tot) {
		bit0[i] = 0;
		bit1[i] = 0;
		i += i & -i;
	}
}
int bit_sum0(int i) {
	int res = 0;
	while (i > 0) {
		res += bit0[i];
		i -= i & -i;
	}
	return res;
}
long long bit_sum1(int i) {
	long long res = 0;
	while (i > 0) {
		res += bit1[i];
		i -= i & -i;
	}
	return res;
}
void solve(vector<Event> &ev, vector<Query> &q1, vector<Query> &q2) {
	if (!q1.empty()) {
		sort(ev.begin(), ev.end(), [](Event a, Event b) {
			return a.i < b.i;
		});
		sort(q1.begin(), q1.end(), [](Query a, Query b) {
			return a.i < b.i;
		});
		int i = 0;
		for (auto &Q : q1) {
			while (i < (int)ev.size() && ev[i].i <= Q.i) {
				bit_add(ev[i].len);
				i++;
			}
			ans[Q.id] -= 1ll * Q.len * (i - bit_sum0(Q.len)) + bit_sum1(Q.len);
		}
		for (auto &E : ev) {
			bit_clear(E.len);
		}
	}
	if (!q2.empty()) {
		sort(ev.begin(), ev.end(), [](Event a, Event b) {
			return a.tim + a.len < b.tim + b.len;
		});
		sort(q2.begin(), q2.end(), [](Query a, Query b) {
			return a.i < b.i;
		});
		int i = 0;
		for (auto &Q : q2) {
			while (i < (int)ev.size() && ev[i].tim + ev[i].len <= Q.i) {
				bit_add(ev[i].len);
				i++;
			}
			ans[Q.id] += 1ll * Q.len * (i - bit_sum0(Q.len)) + bit_sum1(Q.len);
		}
		for (auto &E : ev) {
			bit_clear(E.len);
		}
		reverse(ev.begin(), ev.end());
		reverse(q2.begin(), q2.end());
		i = 0;
		for (auto &Q : q2) {
			while (i < (int)ev.size() && ev[i].tim + ev[i].len > Q.i) {
				bit_add(ev[i].tim);
				i++;
			}
			ans[Q.id] += 1ll * Q.i * bit_sum0(Q.i) - bit_sum1(Q.i);
			if (Q.i - Q.len > 0) {
				ans[Q.id] -= 1ll * (Q.i - Q.len) * bit_sum0(Q.i - Q.len) - bit_sum1(Q.i - Q.len);
			}
		}
		for (auto &E : ev) {
			bit_clear(E.tim);
		}
	}
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	ver[n + 1] = tot = 1;
	for (int i = n; i >= 1; i--) ver[i] = extend(ver[i + 1], s[i] - 'a');
	for (int i = 2; i <= tot; i++) G[pa[i]].push_back(i);
	dfs1(1);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++) add_event(i);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		add_query(l, r, i);
	}
	for (int i = 1; i <= tot; i++) solve(ev[i], q1[i], q2[i]);
	for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
	return 0;
}