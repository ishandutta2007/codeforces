#include <bits/stdc++.h>
using namespace std;
const long long INF = 1ll << 60;
namespace F {
const int V = 2005;
const int E = 10000;
int n, head[V], to[E], nxt[E], eid;
long long cap[E];
void Init(int _n) {
	n = _n;
	for (int i = 0; i < n; i++) head[i] = -1;
	eid = 0;
}
void _add_edge(int u, int v, long long w) {
	to[eid] = v;
	cap[eid] = w;
	nxt[eid] = head[u];
	head[u] = eid++;
}
void add_edge(int u, int v, long long w) {
	_add_edge(u, v, w);
	_add_edge(v, u, 0);
}
int que[V], lvl[V];
bool bfs(int s, int t) {
	int ql = 1, qr = 0;
	for (int i = 0; i < n; i++) lvl[i] = -1;
	que[++qr] = s;
	lvl[s] = 0;
	while (ql <= qr) {
		int u = que[ql++];
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (cap[i] > 0 && lvl[v] == -1) {
				lvl[v] = lvl[u] + 1;
				que[++qr] = v;
			}
		}
	}
	return lvl[t] != -1;
}
int vis[V];
long long dfs(int u, int t, long long fl) {
	if (u == t) return fl;
	long long res = 0;
	for (int &i = vis[u]; ~i; i = nxt[i]) {
		int v = to[i];
		if (lvl[v] == lvl[u] + 1 && cap[i] > 0) {
			long long tmp = dfs(v, t, min(fl, cap[i]));
			cap[i] -= tmp;
			cap[i ^ 1] += tmp;
			fl -= tmp;
			res += tmp;
			if (!fl) break;
		}
	}
	if (!res) lvl[u] = -1;
	return res;
}
long long Dinic(int s, int t) {
	long long res = 0;
	while (bfs(s, t)) {
		for (int i = 0; i < n; i++) vis[i] = head[i];
		res += dfs(s, t, INF);
	}
	return res;
}
}
int n, X[1005], Y[1005], W[1005];
map<pair<int, int>, int> mp;
int main() {
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 0; i < n; i++) scanf("%d%d%d", &X[i], &Y[i], &W[i]), mp[make_pair(X[i], Y[i])] = i, sum += W[i];
	F::Init(2 * n + 2);
	int s = 2 * n, t = 2 * n + 1;
	for (int i = 0; i < n; i++) {
		F::add_edge(i, i + n, W[i]);
		if (abs(X[i] % 2) == 1 && abs(Y[i] % 2) == 0) {
			F::add_edge(s, i, INF);
			pair<int, int> P;
			P = make_pair(X[i] - 1, Y[i]);
			if (mp.count(P)) F::add_edge(i + n, mp[P], W[mp[P]]);
			P = make_pair(X[i] + 1, Y[i]);
			if (mp.count(P)) F::add_edge(i + n, mp[P], W[mp[P]]);
		} else if (abs(X[i] % 2) == 0 && abs(Y[i] % 2) == 0) {
			pair<int, int> P;
			P = make_pair(X[i], Y[i] - 1);
			if (mp.count(P)) F::add_edge(i + n, mp[P], W[mp[P]]);
			P = make_pair(X[i], Y[i] + 1);
			if (mp.count(P)) F::add_edge(i + n, mp[P], W[mp[P]]);
		} else if (abs(X[i] % 2) == 0 && abs(Y[i] % 2) == 1) {
			pair<int, int> P;
			P = make_pair(X[i] - 1, Y[i]);
			if (mp.count(P)) F::add_edge(i + n, mp[P], W[mp[P]]);
			P = make_pair(X[i] + 1, Y[i]);
			if (mp.count(P)) F::add_edge(i + n, mp[P], W[mp[P]]);
		} else {
			F::add_edge(i + n, t, INF);
		}
	}
	printf("%lld\n", sum - F::Dinic(s, t));
	return 0;
}