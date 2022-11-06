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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	map<int, int> occ;
	for (int i = 0; i < m; ++i)
		occ[i] = n / m;
	ll ans = 0;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		auto it = occ.lower_bound(a[i] % m);
		if (it != occ.end()) {
			ans += it->first - a[i] % m;
			a[i] += it->first - a[i] % m;
		} else {
			it = occ.begin();
			ans += it->first + m - a[i] % m;
			a[i] += it->first + m - a[i] % m;
		}
		if (--it->second == 0)
			occ.erase(it);
	}
	cout << ans << '\n';
	for (auto &&x : a)
		cout << x << ' ';
	return 0;
}