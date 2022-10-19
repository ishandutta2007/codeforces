#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015;
int S, T, cur[N * 2], head[N * 2], tot = 1;

struct ed { int to, nxt, cap; } e[N * 6];

void add(int u, int v, int w) {
	e[++tot] = (ed) { v, head[u], w};
	head[u] = tot;
	e[++tot] = (ed) { u, head[v], 0};
	head[v] = tot;
}

int dep[N * 2];

bool bfs() {
	queue<int> q;
	memset(dep, -1, sizeof dep);
	q.push(S);
	dep[S] = 0;

	while (!q.empty()) {
		int u = q.front();
		cur[u] = head[u];
		q.pop();

		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to, cap = e[i].cap;

			if (cap > 0 && dep[v] == -1) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}

	return dep[T] != -1;
}

int n1, n2, m, q;

int dfs(int u, int d) {
	if (!d || u == T) return d;
	int f = 0;

	for (int i = cur[u]; i; i = e[i].nxt) {
		cur[u] = i;
		int v = e[i].to, cap = e[i].cap;

		if (cap > 0 && dep[v] == dep[u] + 1) {
			int o = dfs(v, min(cap, d));
			d -= o, e[i].cap -= o;
			f += o, e[i ^ 1].cap += o;
		}
	}

	return f;
}

void dinic() {
	while (bfs()) dfs(S, inf);
}

bool vis[N * 2], on[N];

void Dfs(int u) {
	vis[u] = 1;

	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v <= n1 + n2 && e[i].cap && !vis[v])
			Dfs(v);
	}
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d%d%d%d", &n1, &n2, &m, &q);
	S = n1 + n2 + 1, T = S + 1;

	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, n1 + v, 1);
	}

	rep(i, 1, n1) add(S, i, 1);
	rep(i, 1, n2) add(n1 + i, T, 1);
	dinic();
	vector<tuple<int, int, int>> vec;
	ll sum = 0;

	rep(u, 1, n1) {
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (n1 < v && v <= n1 + n2 && e[i].cap == 0) {
				on[u] = 1;
				vec.eb(u, v - n1, i / 2);
				sum += i / 2;
			}
		}
	}

	rep(u, 1, n1) {
		if (!vis[u] && !on[u])
			Dfs(u);
	}

	rep(_, 1, q) {
		int o;
		scanf("%d", &o);

		if (o == 1) {
			auto [u, v, i] = vec.back();
			vec.pop_back();
			sum -= i;
			printf("1\n%d\n%lld\n", vis[v + n1] ? -v : u, sum);
			fflush(stdout);
		} else {
			printf("%d\n", SZ(vec));
			for (auto [u, v, i] : vec)
				printf("%d ", i);
			printf("\n");
			fflush(stdout);
		}
	}
	return 0;
}