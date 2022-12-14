#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e4 + 100 + 10;
const ll inf = 1e18;

int n, a[maxn], deg[maxn], b[maxn], w[maxn];
bool mark[maxn];

ll dis[5][maxn];
vector<pair<int,int> > g[maxn];

void dijkstra(int src, int q){
	for (int u = 1; u <= n; u++)
		dis[q][u] = inf;
	dis[q][src] = 0;
	set<pair<ll, int> > s;
	for (int u = 1; u <= n; u++)
		s.insert({dis[q][u], u});
	while (!s.empty()){
		int v = (*s.begin()).second;
		s.erase(s.begin());
		for (auto edge : g[v]){
			if (dis[q][edge.first] > dis[q][v] + w[edge.second]){
				s.erase({dis[q][edge.first], edge.first});
				dis[q][edge.first] = dis[q][v] + w[edge.second];
				s.insert({dis[q][edge.first], edge.first});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int m, k;
	cin >> n >> m >> k;
	int s1, s2, f;
	cin >> s1 >> s2 >> f;
	for (int i = 1; i <= m; i++){
		int v, u;
		cin >> v >> u >> w[i];
		g[v].push_back({u, i});
	}
	for (int i = m + 1; i <= m + k; i++){
		int v, u;
		cin >> v >> u >> a[i] >> b[i];
		w[i] = b[i];
		g[v].push_back({u, i});
		deg[v] ++;
	}
	dijkstra(s1, 1);
	dijkstra(s2, 2);
	for (int x = 1; x <= 100; x++){
		for (int v = 1; v <= n; v++)
			if (!mark[v] and deg[v] and dis[1][v] < dis[2][v])
				for (auto edge : g[v])
					if (edge.second > m)
						w[edge.second] = a[edge.second], mark[v] = 1;
		dijkstra(s1, 1);
		dijkstra(s2, 2);
	}
	if (dis[1][f] < dis[2][f]){
		cout << "WIN" << endl;
		for (int i = m + 1; i <= m + k; i++)
			cout << w[i] << " ";
		cout << endl;
		return 0;
	}
	memset(mark, 0, sizeof mark);
	for (int i = m + 1; i <= m + k; i++)
		w[i] = b[i];
	dijkstra(s1, 1);
	dijkstra(s2, 2);
	for (int x = 1; x <= 100; x++){
		for (int v = 1; v <= n; v++)
			if (!mark[v] and deg[v] and dis[1][v] <= dis[2][v])
				for (auto edge : g[v])
					if (edge.second > m)
						w[edge.second] = a[edge.second], mark[v] = 1;
		dijkstra(s1, 1);
		dijkstra(s2, 2);
	}
	if (dis[1][f] <= dis[2][f]){
		cout << "DRAW" << endl;
		for (int i = m + 1; i <= m + k; i++)
			cout << w[i] << " ";
		cout << endl;
		return 0;
	}
	cout << "LOSE" << endl;
}