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
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

deque<int> * darr[(int)1e6];
int ans[(int)1e6];
vector<int> adj[(int)1e6];

deque<int> &arr(int u) { return *darr[u]; }

void dfs(const int u, const int parent) {
	if (parent != -1)
		adj[u].erase(find(adj[u].begin(), adj[u].end(), parent));

	if (adj[u].empty())
		darr[u] = new deque<int>{ 1 };
	else {
		for (const int &v : adj[u])
			dfs(v, u);
		const auto wIt = max_element(adj[u].begin(), adj[u].end(), [](const int &x, const int &y) {
			return darr[x]->size() < darr[y]->size();
		});
		const int w = *wIt;
		adj[u].erase(wIt);

		darr[u] = darr[w];
		darr[u]->push_front(1);
		ans[u] = ans[w] + 1;

		if (arr(u)[ans[u]] == 1)
			ans[u] = 0;
		for (const int &v : adj[u])
			for (int i = 0; i < darr[v]->size(); ++i)
				arr(u)[i + 1] += arr(v)[i];

		if (!adj[u].empty()) {
			const int w2 = *max_element(adj[u].begin(), adj[u].end(), [](const int &x, const int &y) {
				return darr[x]->size() < darr[y]->size();
			});
			const int i = max_element(darr[u]->begin(), darr[u]->begin() + min(darr[u]->size(), darr[w2]->size() + 1)) - darr[u]->begin();
			
			if (arr(u)[i] > arr(u)[ans[u]] || (arr(u)[i] == arr(u)[ans[u]] && i < ans[u]))
				ans[u] = i;

			for (const int &v : adj[u])
				delete darr[v];
		}
	}
	adj[u].clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0, -1);
	for (int i = 0; i < n; ++i)
		cout << ans[i] << '\n';
	return 0;
}