#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
	for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
	a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 4e5, INF = 0x7f7f7f7f7f7f7f7f;

int n, m, _, tot, etot = 1, qwq[N + 10], l[N + 10], r[N + 10], seq[N + 10], U[N + 10], V[N + 10], W[N + 10], dis1[N + 10], disn[N + 10], pre[N + 10], epre[N + 10];
bool vis[N + 10], evis[N + 10];
vector<tuple<int, int, int>> e[N + 10];

void adde(int x, int y, int z) { e[x].emplace_back(y, z, ++etot); }

struct Element {
	int u, val;
	bool operator < (const Element &rhs) const { return val > rhs.val; }
};
struct Node { int val; Node *ch[2]; } mem[(N << 2) + 10], *atot = mem, *rt;

template <class T> struct heap {
	T h[(N << 1) + 10]; int sz;
	void push(T x) { h[++sz] = x, push_heap(h + 1, h + 1 + sz); }
	void pop() { pop_heap(h + 1, h + 1 + sz), sz--; }
	T top() { return h[1]; }
	int size() { return sz; }
};
heap<Element> q;

void Dijkstra(int s, int *dis) {
	memset(vis, 0, sizeof(vis)), dis[s] = 0, q.push({s, 0ll});
	while (q.size()) {
		int u = q.top().u; q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (auto [v, w, i] : e[u])
			if (dis[u] + w < dis[v]) pre[v] = u, epre[v] = i, q.push({v, dis[v] = dis[u] + w});
	}
}

void dfs(int u, int id, int *dis, int *arr) {
	arr[u] = id;
	for (auto [v, w, i] : e[u]) {
		if (arr[v] || evis[i]) continue;
		if (dis[u] + w == dis[v]) dfs(v, id, dis, arr);
	}
}

void modify(Node *&u, int ql, int qr, int val, int l = 1, int r = tot - 1) {
	if (ql > r || qr < l) return ;
	if (u == 0) u = ++atot, u->val = INF;
	if (ql <= l && qr >= r) return u->val = min(u->val, val), void();
	int mid = (l + r) >> 1;
	modify(u->ch[0], ql, qr, val, l, mid), modify(u->ch[1], ql, qr, val, mid + 1, r);
}
int qpos(Node *u, int pos, int l = 1, int r = tot - 1) {
	if (u == 0) return INF;
	if (l == r) return u->val;
	int mid = (l + r) >> 1;
	return min(u->val, (pos <= mid) ? qpos(u->ch[0], pos, l, mid) : qpos(u->ch[1], pos, mid + 1, r));
}

struct OI {
	int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
	CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
	fr(n, m, _), memset(dis1, 0x3f, sizeof(dis1)), memset(disn, 0x3f, sizeof(disn));
	for (int i = 1; i <= m; i++) fr(U[i], V[i], W[i]), adde(U[i], V[i], W[i]), adde(V[i], U[i], W[i]);
	Dijkstra(n, disn), Dijkstra(1, dis1), pre[1] = 0;
	for (int i = n; i; i = pre[i]) seq[++tot] = i;
	for (int i = 1; i <= tot; i++) evis[epre[seq[i]]] = evis[epre[seq[i]] ^ 1] = 1;
	for (int i = 1; i <= tot; i++) dfs(seq[i], tot - i + 1, disn, r);
	reverse(seq + 1, seq + 1 + tot);
	for (int i = 1; i <= tot; i++) dfs(seq[i], i, dis1, l), qwq[epre[seq[i]] >> 1] = i - 1;
	for (int i = 1; i <= m; i++) {
		if (qwq[i]) continue;
		modify(rt, l[U[i]], r[V[i]] - 1, dis1[U[i]] + W[i] + disn[V[i]]), modify(rt, l[V[i]], r[U[i]] - 1, dis1[V[i]] + W[i] + disn[U[i]]);
	}
	while (_--) {
		int x = fr(), y = fr();
		if (qwq[x] == 0) {
			if (y > W[x]) printf("%lld\n", dis1[n]);
			else printf("%lld\n", min(dis1[n], min(dis1[U[x]] + y + disn[V[x]], dis1[V[x]] + y + disn[U[x]])));
		} else {
			if (y < W[x]) printf("%lld\n", dis1[n] - W[x] + y);
			else printf("%lld\n", min(dis1[n] - W[x] + y, qpos(rt, qwq[x])));
		}
	}
	return 0;
}