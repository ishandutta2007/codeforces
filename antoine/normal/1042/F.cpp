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

int n, k;
vector<int> adj[(int)1e6];
int ans = 0;

vector<int> f(const int u, const int parent) {
	if (adj[u].size() == 1)
		return{ 0 };

	vector<int> a;
	for (const int &v : adj[u])
		if (v != parent) {
			vector<int> b = f(v, u);
			transform(b.begin(), b.end(), b.begin(), [](const int &x) { return x + 1;  });
			a.insert(a.end(), b.begin(), b.end());
		}

	auto mid = partition(a.begin(), a.end(), [](const int &x) { return x > k / 2; });
	if (mid != a.end()) {
		*mid = *max_element(mid, a.end());
		a.erase(mid + 1, a.end());
		if (mid != a.begin() && *min_element(a.begin(), mid) + *mid <= k)
			a.pop_back();
	}

	if (a.size() > 2) {
		for (int i = 0; i < 2; ++i)
			swap(a[i], *min_element(a.begin() + i, a.end()));
		ans += a.size() - 2;
		a.erase(a.begin() + 2, a.end());
	}
	return a;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int root = 0;
	while (adj[root].size() == 1)
		assert(++root < n);

	ans += f(root, -1).size();
	cout << ans << endl;
	return 0;
}