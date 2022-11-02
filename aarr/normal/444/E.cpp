#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 3005;
int s, cnt;

pair <int , pair <int, int> > e[N];
vector <int> adj[N];
bool mark[N], mark2[N];
int c[N];
vector <int> vec[3];


void dfs(int v, int k) {
	mark2[v] = true;
	for (auto u : adj[v]) {
		if (!mark[u] && !mark2[u]) {
			dfs(u, k);
		}
	}
	vec[k].push_back(v);


}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		e[i] = {-w, {u, v}};
	}
	sort(e + 1, e + n);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i < n; i++) {
		int u = e[i].second.first, v = e[i].second.second;
		if (mark[u] || mark[v]) {
			continue;
		}
		fill(mark2, mark2 + n + 1, false);
		vec[0].clear();
		vec[1].clear();
		mark[v] = mark[u] = true;
		dfs(u, 0);
		dfs(v, 1);
		mark[v] = mark[u] = false;
		if (vec[0].size() > vec[1].size()) {
			vec[0].swap(vec[1]);
		}
		for (auto x : vec[0]) {
			//cout << "71 " << i << " " << x << " " << u << " " << v << endl;
			mark[x] = true;
			cnt++;
			s += c[x];
		}
		if (s >= vec[1].size()) {
			cout << -e[i].first;
			return 0;
		}

	}
	cout << 0;
}