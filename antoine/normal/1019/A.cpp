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

ll f(vector <vector<ll>> v, const int t) {
	ll res = 0;
	for (int i = 1; i < v.size(); ++i) {
		while (v[i].size() > t) {
			res += v[i].back();
			v[i].pop_back();
			v[0].push_back(0);
		}
	}
	priority_queue <ll, vector<ll>, greater<ll>> pq;

	for (int i = 1; i < v.size(); ++i)
		for (auto &&x : v[i])
			pq.push(x);
	while (v[0].size() <= t) {
		assert(!pq.empty());
		res += pq.top();
		pq.pop();
		v[0].push_back(0);
	}
	
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector<vector<ll>> v(m);


	for (int i = 0; i < n; ++i) {
		int p, c;
		cin >> p >> c;
		--p;
		v[p].push_back(c);
	}
	for (auto &&x : v)
		sort(x.rbegin(), x.rend());

	ll ans = 1e18;
	for (int t = 0; t < n; ++t)
		ans = min(ans, f(v, t));
	cout << ans;
	return 0;
}