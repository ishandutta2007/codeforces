/*input
5
1 2
2 3
3 4
4 5
*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN = 100007;
int N, deg[MAXN], match[MAXN];
vector<int> comp[MAXN], G[MAXN];
unordered_set<int> temp[MAXN];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		temp[u].insert(v);
		temp[v].insert(u);
	}
	
	vector<int> st;
	for (int u = 1; u <= N; ++u) if ((int) temp[u].size() == 1) st.push_back(u);
	while (!st.empty()) {
		int u = st.back();
		st.pop_back();
		if (!comp[u].empty()) continue;

		if (temp[u].empty()) {
			comp[G[u][0]].push_back(u);
		} else {
			assert((int) temp[u].size() == 1);
			int v = *temp[u].begin();
			if (comp[v].empty()) {
				for (int w : G[v]) {
					temp[w].erase(v);
					if ((int) temp[w].size() == 1) st.push_back(w);
				}
			}
			comp[v].push_back(u);
		}
	}

	int64_t ans = 0;
	for (int u = 1; u <= N; ++u) if (!comp[u].empty()) {
		ans += (int) comp[u].size();
		comp[u].push_back(u);
		for (int i = 0; i < (int) comp[u].size(); ++i) {
			match[comp[u][i]] = comp[u][(i + 1) % (int) comp[u].size()];
		}
	}
	cout << ans * 2 << '\n';
	for (int u = 1; u <= N; ++u) {
		cout << match[u] << ' ';
	}
}