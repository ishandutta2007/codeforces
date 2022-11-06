#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int n, k;
int a[(int)1e5];
int dist[(int)1e5][100];
vector<int> adj[(int)1e5];

void bfs(int type) {
	queue<int> q;
	for (int i = 0; i < n; ++i)
		if (a[i] == type) {
			q.push(i);
			dist[i][type] = 0;
		}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for(const int v : adj[u])
			if (dist[v][type] == -1) {
				dist[v][type] = dist[u][type] + 1;
				q.push(v);
			}
			else
				assert(dist[v][type] <= dist[u][type] + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(dist, -1, sizeof dist);

	int s, m;
	cin >> n >> m >> k >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < k; ++i) {
		bfs(i);
	}
	for (int i = 0; i < n; ++i) {
		sort(dist[i], dist[i] + k);
		assert(dist[i][0] != -1);
		ll ans = 0;
		for (int j = 0; j < s; ++j)
			ans += dist[i][j];
		cout << ans << ' ';
	}
	return 0;
}