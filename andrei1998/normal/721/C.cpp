#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int NMAX = 5000 + 5;

vector <pair <int, int> > graph[NMAX];

int n, t;

int dp[NMAX][NMAX];
int father[NMAX][NMAX];

bool vis[NMAX];

void dfs(int node) {
    vis[node] = true;
	for (int i = 0; i <= n; ++ i)
		dp[node][i] = t + 1;

	if (node == n) {
		dp[node][1] = 0;
		father[node][1] = n;
		return ;
	}

	for (auto it: graph[node])
		if (!vis[it.first])
			dfs(it.first);

	for (auto it: graph[node])
		for (int i = 1; i <= n; ++ i)
			if (dp[it.first][i - 1] + it.second < dp[node][i]) {
				dp[node][i] = dp[it.first][i - 1] + it.second;
				father[node][i] = it.first;
			}
}

int main() {
	int m;
	cin >> n >> m >> t;

	int a, b, c;
	while (m --) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	dfs(1);

	int best = 1;
	for (int i = 1; i <= n; ++ i)
		if (dp[1][i] <= t)
			best = i;

	cout << best << '\n';

	vector <int> ans;
	int node = 1;

	while (node != n) {
		ans.push_back(node);
        node = father[node][best --];
	}

	ans.push_back(node);

	for (int i = 0; i < ans.size(); ++ i)
		cout << ans[i] << " \n"[i + 1 == ans.size()];
	return 0;
}