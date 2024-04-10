#include <bits/stdc++.h>

using namespace std;

typedef std::pair<int, int> ii;

const int ms = 200200;

int cap[ms];
std::vector<ii> edges[ms];
int used[2 * ms];
bool visit[ms];

int dfs(int on) {
	visit[on] = true;
	int ans = cap[on];
	for(auto e : edges[on]) {
		if(visit[e.first]) {
			continue;
		}
		int need = dfs(e.first);
		used[e.second] -= need;
		ans += need;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> cap[i];
		sum += cap[i];
	}
	if(sum != 0) {
		std::cout << "Impossible\n";
		return 0;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;v--;
		edges[u].emplace_back(v, 2 * i);
		edges[v].emplace_back(u, 2 * i + 1);
	}
	bool valid = true;
	for(int i = 0; i < n; i++) {
		valid = valid && (visit[i] || dfs(i) == 0);
	}
	if(valid) {
		cout << "Possible\n";
		for(int i = 0; i < m; i++) {
			cout << -(used[2 * i] - used[2 * i + 1]) << endl;
		}
	} else {
		cout << "Impossible\n";
	}
}