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

int n, m;
vector<int> adj[150000];
bool visited[150000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		adj[i].push_back(i);
		sort(adj[i].begin(), adj[i].end());
	}

	for(int i = 0; i < n; ++i)
		if (!visited[i]) {
			for (auto &&x : adj[i]) {
				if (adj[x] != adj[i]) {
					cout << "NO";
					return 0;
				}
				visited[x] = true;
			}
		}
	cout << "YES";
	return 0;
}