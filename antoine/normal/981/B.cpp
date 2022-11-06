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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<int, int> mp;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, x;
		cin >> a >> x;
		mp[a] = x;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int b, y;
		cin >> b >> y;
		mp[b] = max(mp[b], y);
	}
	ll ans = 0;
	for (auto &&x : mp)
		ans += x.second;
	cout << ans;
	return 0;
}