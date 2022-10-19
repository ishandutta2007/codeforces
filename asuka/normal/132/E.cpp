#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 605, M = N * N;

struct edge {int to, nxt, cap, cost;} e[M << 1];

int head[N], tot = 1;

void add(int u, int v, int cap, int cost) {
	e[++tot] = (edge) {v, head[u], cap, cost};
	head[u] = tot;
	e[++tot] = (edge) {u, head[v], 0, -cost};
	head[v] = tot;
}

queue<int> q;
int S, T, from[N], dis[N], f[N];
bool inq[N];

bool SPFA() {
	memset(from, -1, sizeof from);
	memset(dis, 0x3f, sizeof dis);
	memset(f, 0, sizeof f);
	q.push(S); dis[S] = 0; inq[S] = 1; f[S] = inf;

	while (!q.empty()) {
		int u = q.front();
		q.pop(); inq[u] = 0;

		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to, cap = e[i].cap, w = e[i].cost;

			if (cap > 0 && dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				from[v] = i; f[v] = min(f[u], cap);

				if (!inq[v]) q.push(v);
			}
		}
	}

	return from[T] != -1;
}

int flow, cost;

void EK() {
	while (SPFA()) {
		flow += f[T];
		cost += f[T] * dis[T];

		for (int i = T; i != S; i = e[from[i] ^ 1].to) {
			e[from[i]].cap -= f[T];
			e[from[i] ^ 1].cap += f[T];
		}
	}
}

int n, m, a[N], col[N], lst[26], id[N][N];
vector<int> g[N];

void dfs(int u, int c) {
	col[u] = c;

	for (int v : g[u]) dfs(v, c);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);

	rep(i, 1, n) scanf("%d", &a[i]);

	int s = n + n + 1, t = n + n + 2, o = n + n + 3;
	S = n + n + 4; T = n + n + 5;
	add(s, o, m, 0);
	add(t, s, inf, 0);

	rep(i, 1, n) {
		add(o, i + i - 1, 1, __builtin_popcount(a[i]));
		add(S, i + i, 1, 0);
		add(i + i - 1, T, 1, 0);

		rep(j, i + 1, n) {
			id[i][j] = tot + 1;
			add(i + i, j + j - 1, 1, a[i] != a[j] ? __builtin_popcount(a[j]) : 0);
		}

		add(i + i, t, 1, 0);
	}

	EK();
	vector<pii> ans;

	rep(i, 1, n) rep(j, i + 1, n) {
		if (e[id[i][j]].cap == 0)
			g[i].pb(j);
	}

	int c = 0;

	rep(i, 1, n) {
		if (!col[i])
			dfs(i, ++c);
	}

	rep(i, 1, n) {
		if (lst[col[i]] != a[i]) {
			ans.emplace_back(col[i], a[i]);
		}

		lst[col[i]] = a[i];

		ans.emplace_back(col[i], -1);
	}

	printf("%d %d\n", SZ(ans), cost);

	for (auto [u, v] : ans) {
		u--;

		if (v == -1) {
			printf("print(%c)\n", 'a' + u);

		} else {
			printf("%c=%d\n", 'a' + u, v);
		}
	}

	return 0;
}