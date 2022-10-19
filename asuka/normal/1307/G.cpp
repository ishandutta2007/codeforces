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
const int N = 55;
struct edge {
	int to, nxt, cap, cost;
} e[N * N << 2];

int head[N], from[N], flow[N], dis[N], mincost, maxflow, tot = 1;

void add(int u, int v, int cap, int cost) {
	e[++tot] = (edge) {v, head[u], cap, cost};
	head[u] = tot;
	e[++tot] = (edge) {u, head[v], 0, -cost};
	head[v] = tot;
}

bool inque[N];
queue<int> q;
int n, m, Q;

bool SPFA() {
	q.push(1);
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0; flow[1] = inf;
	while (SZ(q)) {
		int u = q.front(); q.pop();
		inque[u] = 0;
		for (int i = head[u]; ~i; i = e[i].nxt) {
			int v = e[i].to, cap = e[i].cap, w = e[i].cost;
			if (cap > 0 && dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				from[v] = i; flow[v] = min(flow[u], cap);
				if (!inque[v]) q.push(v), inque[v] = 1;
			}
		}
	}
	return dis[n] < inf;
}

vector<pii> vec;

void solve() {
	while (SPFA()) {
		maxflow += flow[n];
		for (int i = n; i != 1; i = e[from[i] ^ 1].to) {
			mincost += flow[n] * e[from[i]].cost;
			e[from[i]].cap -= flow[n];
			e[from[i] ^ 1].cap += flow[n];
		}
		vec.emplace_back(maxflow, mincost);
	}
}

int main() {
	// freopen("spfb.in", "r", stdin);
	// freopen("spfb.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof head);
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, 1, w);
	}
	solve();
	scanf("%d", &Q);
	while (Q--) {
		int x;
		scanf("%d", &x);
		double ans = 1e10;
		for (auto [f, c] : vec) ans = min(ans, 1.0 * (x + c) / f);
		printf("%.10lf\n", 1.0 * ans);
	}
	return 0;
}