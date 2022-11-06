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
vector<int> adj[(int)2e5];
int cnt[(int)2e5];
ll ans = 0;

vector<ll> dfs(int u, int p) {
	vector<vector<ll>> all;
	vector<ll> total(k, 0);
	cnt[u] = 1;

	for (auto &&v : adj[u])
		if (v != p) {
			all.emplace_back(dfs(v, u));
			ans += all.back().back() * (n - cnt[v]);
			rotate(all.back().begin(), all.back().end() - 1, all.back().end());
			cnt[u] += cnt[v];
			for (int i = 0; i < k; ++i)
				total[i] += all.back()[i];
		}

	ll addAns = 0;
	for (auto &&v : all) {
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < k; ++j)
				addAns += v[i] * (total[j] - v[j]) * ((i + j + k - 1) / k);
	}
	assert((addAns & 1) == 0);
	ans += addAns >> 1;
	ans += accumulate(total.begin() + 1, total.end(), 0ll);
	++total[0];
	return total;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	cout << ans;
	return 0;
}