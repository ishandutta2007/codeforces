#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<int> adj[(int)1e5];
int indeg[(int)1e5];
int E[(int)1e5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> E[i];

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		++indeg[u];
	}

	vector<int> tasks[2];
	for (int i = 0; i < N; ++i)
		if (indeg[i] == 0)
			tasks[E[i]].push_back(i);

	int ans = 0;
	for(;;) {
		if (!tasks[0].empty()) {
			int u = tasks[0].back();
			tasks[0].pop_back();
			for (int &v : adj[u])
				if (--indeg[v] == 0)
					tasks[E[v]].push_back(v);
		} else {
			if (tasks[1].empty())
				break;
			do {
				int u = tasks[1].back();
				tasks[1].pop_back();
				for (int &v : adj[u])
					if (--indeg[v] == 0)
						tasks[E[v]].push_back(v);
			} while (!tasks[1].empty());
			++ans;
		}
	}
	cout << ans;
	return 0;
}