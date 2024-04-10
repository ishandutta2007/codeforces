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
#include <stack>

using namespace std;

int n, m;
vector<int> adj[(int)1e5];
vector<int> adjT[(int)1e5];
bool visited[(int)1e5][2];
int choice[(int)1e5][2];

bool dfs(int u) {
	visited[u][0] = true;
	for (int &v : adj[u])
		if (visited[v][0] != visited[v][1])
			return true;
		else if (!visited[v][0] && dfs(v))
			return true;
	visited[u][1] = true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		while (c-- > 0) {
			int v;
			cin >> v;
			--v;
			adj[i].push_back(v);
			adjT[v].push_back(i);
		}
	}

	vector<int> nodes;
	for (int i = 0; i < n; ++i)
		if (adj[i].empty()) {
			nodes.push_back(i);
			visited[i][0] = true;
		}

	while (!nodes.empty()) {
		int u = nodes.back();
		nodes.pop_back();
		for (int &v : adjT[u]) {
			for (int p = 0; p < 2; ++p)
				if (visited[u][p] && !visited[v][!p]) {
					visited[v][!p] = true;
					choice[v][!p] = u;
					nodes.push_back(v);
				}
		}
	}

	int s;
	cin >> s;
	--s;
	if (visited[s][1]) {
		cout << "Win\n" << s + 1;
		for (int p = 1; adj[s].size(); p ^= 1) {
			s = choice[s][p];
			cout << ' ' << s + 1;
		}
		return 0;
	}

	memset(visited, false, sizeof visited);
	if (dfs(s))
		cout << "Draw";
	else
		cout << "Lose";

	return 0;
}