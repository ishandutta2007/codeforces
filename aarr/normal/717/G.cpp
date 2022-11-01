#include <bits/stdc++.h>
using namespace std;

const int N = 2000 * 1000 + 5;
const long long inf = 1000ll * 1000 * 1007 * N; 
int t;
int n, m, k;
int st = 0, ed = 1;
string p, s[N];

int a[N];
int from[N], to[N], cap[N];
long long dis[N];
int cost[N];
bool mark[N];
int par[N];
vector <int> adj[N];

void add_edge(int u, int v, int cp, int ct) {
//	cout << "79 " << u << " " << v << " " << cp << " " << ct << endl;
	from[t] = u, to[t] = v, cap[t] = cp, cost[t] = ct;
	adj[u].push_back(t);
	t++;
	from[t] = v, to[t] = u, cap[t] = 0, cost[t] = -ct;
	adj[v].push_back(t);
	t++;
}

pair <bool, long long> upd() {
//	cout << "74 " << endl;
	fill(dis, dis + t + 1, -inf);
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
			if (dis[v] + w > dis[u] && cap[x]) {
			//	cout << "63 " << x << " " << u << " " << w << " " << endl;
				dis[u] = dis[v] + w;
				q.push(u);
				mark[u] = true;
				par[u] = x;
			}
		}
	}
	int v = ed;
	long long cst = 0;
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

pair <int, long long> mcmf() {
	int fl = 0;
	long long cst = 0;
	for (int i = 0; i < k; i++) {
		auto p = upd();
		cst += p.second;
	}
	return {fl, cst};
}

bool check(int x, int y) {
	for (int i = 0; i < s[y].size(); i++) {
		if (x + i >= p.size() || p[x + i] != s[y][i]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> p >> m;
	ed = n;
	for (int i = 1; i <= m; i++) {
		cin >> s[i] >> a[i];
		
	}
	for (int i = 0; i < n; i++) {
		add_edge(i, i + 1, N, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check(i, j)) {
				add_edge(i, i + s[j].size(), 1, a[j]);
			}
		}
	}
	cin >> k;
	auto p = mcmf();
	cout << p.second;
	return 0;
}