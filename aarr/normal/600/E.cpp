#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;


const int N = 100 * 1000 + 5;

bool mark[N];
vector <long long> vec[N];
map <int, int> mp[N];
long long ans[N];
int c[N];
vector <int> adj[N];

void dfs(int v) {
	mark[v] = true;
	mp[v][c[v]] = 1;
	vec[v].push_back(-c[v]);
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u);
			if (vec[u].size() > vec[v].size()) {
				mp[v].swap(mp[u]);
				vec[v].swap(vec[u]);
			}
			for (int i = 0; i < vec[u].size(); i++) {
				vec[v].push_back(0);
			}
			for (auto p : mp[u]) {
				int x = p.first, cnt = p.second;
			//	cout << "23 " << v << " " << u << " " << x << " " << cnt << " " << mp[v][x] << endl;
				for (int i = mp[v][x]; i < mp[v][x] + cnt; i++) {
					vec[v][i] -= x;
				}
				mp[v][x] += cnt;
			}
		}
		
	}
//	cout << "49 " << v << endl;
//	for (auto y : vec[v]) {
//		cout << y << " ";
//	}
//	cout << endl;
	int x = lower_bound(vec[v].begin(), vec[v].end(), 0) - vec[v].begin() - 1;
	ans[v] = -vec[v][x];	
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}