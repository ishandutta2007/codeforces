#include <bits/stdc++.h>
using namespace std;

const int N = 2000 * 1000 + 5;
const long long inf = 1000ll * 1000 * 1007 * N; 
int t;
int n;
int st = 0, ed = 1;

int x[N], y[N];
int from[N], to[N], cap[N];
long double dis[N];
double cost[N];
bool mark[N];
int par[N];
vector <int> adj[N];

void add_edge(int u, int v, int cp, double ct) {
	from[t] = u, to[t] = v, cap[t] = cp, cost[t] = ct;
	adj[u].push_back(t);
	t++;
	from[t] = v, to[t] = u, cap[t] = 0, cost[t] = -ct;
	adj[v].push_back(t);
	t++;
}

pair <bool, long double> upd() {
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
			long double w = cost[x];
			int u = to[x];
			if (dis[v] + w + 0.00000001 < dis[u] && cap[x]) {
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
	long double cst = 0;
	while (v != st) {
		int x = par[v];
	//	cout << "82 " << v << " " << x << " " << cost[x] << endl;
		cap[x]--;
		cap[x ^ 1]++;
		cst += cost[x];
		v = from[x];
	}
//	cout << "71 " << cst << endl;
	return {true, cst};
}

pair <int, long double> mcmf() {
	int fl = 0;
	long double cst = 0;
	while (true) {
		auto p = upd();
		if (!p.first) {
			break;
		}
		fl++;
		cst += p.second;
	}
	return {fl, cst};
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		add_edge(0, i * 2, 2, 0);
		add_edge(i * 2 + 1, 1, 1, 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (y[j] > y[i]) {
				add_edge(j * 2, i * 2 + 1, 1, sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])));
			}
		}
	}
//	for (int k = 1; k < t; k++) {
//		cout << "83 " << k << " " << from[k] << " " << to[k] << endl;
//	}
	auto p = mcmf();
//	cout << "72 " << p.first << endl;
	if (p.first == n - 1) {
		cout << fixed << setprecision(8);
		cout << p.second;
	}
	else {
		cout << -1;
	}
	return 0;
}