#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5;

queue <int> q;
int dis[N];
int d2[N];
int a[N];
int cnt[N];
vector <int> adj[N];
vector <int> b[N];
map <pair <int, int>, bool> mp;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
	}
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	fill(dis, dis + n + 1, N);
	dis[a[k]] = 0;
	q.push(a[k]);
	while (q.size()) {
		int v = q.front();
		q.pop();
		for (auto u : adj[v]) {
			if (dis[u] == N) {
				dis[u] = dis[v] + 1;
				q.push(u);
			}
			if (dis[u] == dis[v] + 1) {
			//	b.push_back(1);
				cnt[u]++;
				mp[{v, u}] = true;
			//	cout << "73 " << v << " " << u << endl;
			}
		}
	}
	int mini = 0, maxi = 0;
	for (int i = 1; i < k; i++) {
		if (!mp[{a[i + 1], a[i]}]) {
			mini++;
			maxi++;
		}
		else if (cnt[a[i]] > 1) {
			maxi++;
		}
	}
	cout << mini << " " << maxi << endl;
	return 0;
}