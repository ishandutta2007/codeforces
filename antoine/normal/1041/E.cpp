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

void No(const int reason) {
	cout << "NO\n";
	cerr << "reason: " << reason << '\n';
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<int> cnt(n, 0);
	vector<vector<int>> comps(n);

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		
		if (max(u, v) != n - 1 || u == v) No(0);
		
		const int x = min(u, v);
		if (++cnt[x] == 1)
			comps[x].push_back(x);
	}


	for (int i = 0; i < n - 1; ++i)
		if (!cnt[i]) {
			for (int j = i + 1;; ++j) {
				if (j >= n - 1) No(1);
				if (comps[j].size() < cnt[j]) {
					comps[j].push_back(i);
					break;
				}
			}
		}


	for (int i = 0; i < n; ++i) {
		assert(comps[i].size() <= cnt[i]);
		if (comps[i].size() != cnt[i]) No(2);
	}

	cout << "YES\n";
	for (auto &&v : comps) {
		v.push_back(n - 1);
		for (int i = 0; i + 1 < v.size(); ++i)
			cout << v[i] + 1 << ' ' << v[i + 1] + 1 << '\n';
	}
	return 0;
}