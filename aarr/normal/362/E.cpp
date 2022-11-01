#include <bits/stdc++.h>
using namespace std;

const int N = 2000 * 1000 + 5;
const long long inf = 1000ll * 1000 * 1007 * N; 
int t;
int n, k;
int st = 1, ed = 1;

int x[N], y[N];
int from[N], to[N], cap[N];
long long dis[N];
int cost[N];
bool mark[N];
int par[N];
vector <int> adj[N];

void add_edge(int u, int v, int cp, int ct) {
	from[t] = u, to[t] = v, cap[t] = cp, cost[t] = ct;
	adj[u].push_back(t);
	t++;
	from[t] = v, to[t] = u, cap[t] = 0, cost[t] = -ct;
	adj[v].push_back(t);
	t++;
}

pair <int, long long> upd() {
//	cout << "74 " << endl;
	fill(dis, dis + t + 1, inf);
	fill(mark, mark + n * 2 + 7, false);
	fill(par, par + n * 2 + 7, 0);
	dis[st] = 0;
	queue <int> q;
	q.push(st);
	mark[st] = true;
	while (q.size()) {
		int v = q.front();
		q.pop();
		if (!mark[v]) {
			continue;
		}
	//	cout << "78 " << v << " " << dis[v] << endl;
		mark[v] = false;
		for (auto x : adj[v]) {
			int w = cost[x];
			int u = to[x];
			if (dis[v] + w < dis[u] && cap[x]) {
			//	cout << "63 " << x << " " << u << " " << w << " " << endl;
				dis[u] = dis[v] + w;
				q.push(u);
				mark[u] = true;
				par[u] = x;
			}
		}
	}
	if (dis[ed] == inf) {
		return {false, 0};
	}
	int v = ed;
	int mn = N;
	while (v != st) {
		int x = par[v];
		mn = min(mn, cap[x]);
		v = from[x];
	}
	v = ed;
	long long cst = 0;
	while (v != st) {
		int x = par[v];
//		cout << "82 " << v << " " << x << " " << cost[x] << endl;
		cap[x] -= mn;
		cap[x ^ 1] += mn;
		cst += cost[x];
		v = from[x];
	}
//	cout << "71 " << mn << " " << cst << endl;
	return {mn, cst};
}

pair <int, long long> mcmf() {
	int fl = 0;
	long long cst = 0;
	while (true) {
		auto p = upd();
		for (int i = 0; i < p.first; i++) {
			if (p.second + cst > k) {
				return {fl, cst};
			}
			fl++;
			cst += p.second;			
		}

	}
	return {fl, cst};
}

int main() {
	cin >> n >> k;
	ed = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (x) {
				add_edge(i, j, x, 0);
				add_edge(i, j, k + 1, 1);
			}
		}
	}
	add_edge(1, n, 1, k + 1);
	auto p = mcmf();
	cout << p.first;
	return 0;
}