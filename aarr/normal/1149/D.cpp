#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 72, Q = 20, inf = 1000 * 1000 * 1000 + 7;
int t, q, sz;


int part[N], pr[N];
int dis[N][1 << Q];
bool mark[N][1 << Q];
vector <int> adj1[N], adj2[N];
queue <pair <int, int> > q1, q2;


void dfs(int v) {
	sz++;
	for (auto u : adj1[v]) {
		if (!part[u]) {
			part[u] = part[v];
			dfs(u);
		}
	}
}

int get(int x, int y) {
	return (x >> y) & 1;
}

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w == a) {
			adj1[u].push_back(v);
			adj1[v].push_back(u);
		}
		else {
			adj2[u].push_back(v);
			adj2[v].push_back(u);			
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!part[i]) {
			t++;
			sz = 0;
			part[i] = t;
			dfs(i);
			for (int j = 1; j <= n; j++) {
				if (part[i] == part[j]) {
					if (sz <= 3) {
						pr[j] = -1;
					}
					else {
						pr[j] = q;
					}
				}
			}
			if (sz > 3) {
				q++;
			}
		//	if (sz <= 3) {
		//		part[i] = -1;
		//		dfs(i, -1);
		//		t--;
		//	}
		} 
	}
	for (int i = 1; i <= n; i++) {
	//	if (part[i] > 0) {
	//		part[i]--;
	//	}
	//	cout << "72 " << i << " " << part[i] << " " << pr[i] << endl;
		for (int mask = 0; mask < (1 << q); mask++) {
			dis[i][mask] = inf;
		}
	}
	int smsk = 0;
	if (pr[1] >= 0) {
		smsk = (1 << pr[1]);
	}
	dis[1][smsk] = 0;
	q1.push({1, smsk});
	while (q1.size() || q2.size()) {
		int v, mv;
		if (q1.size() && (!q2.size() || dis[q1.front().first][q1.front().second] < dis[q2.front().first][q2.front().second])) {
			v = q1.front().first, mv = q1.front().second;
			q1.pop();
		}
		else {
			v = q2.front().first, mv = q2.front().second;
			q2.pop();			
		}
	//	cout << "73 " << v << " " << mv << endl; 
		if (mark[v][mv]) {
			continue;
		}
		mark[v][mv] = true;
		for (auto u : adj1[v]) {
			int mask = mv;
			if (pr[u] >= 0) {
				mask |= (1 << pr[u]);
			}
			if (dis[v][mv] + a < dis[u][mask]) {
				dis[u][mask] = dis[v][mv] + a;
				q1.push({u, mask});
			}
		}
		for (auto u : adj2[v]) {
			if (pr[u] >= 0 && get(mv, pr[u])) {
				continue;
			}
			if (part[u] == part[v]) {
				continue;
			}
			int mask = mv;
			if (pr[u] >= 0) {
				mask |= (1 << pr[u]);
			}
			if (dis[v][mv] + b < dis[u][mask]) {
				dis[u][mask] = dis[v][mv] + b;
				q2.push({u, mask});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int ans = inf;
		for (int mask = 0; mask < (1 << q); mask++) {
			ans = min(ans, dis[i][mask]);
		}
		cout << ans << " ";
	}
	return 0;
}