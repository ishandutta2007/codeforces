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

int  main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] = a[i] == m ? 0 : a[i] > m ? 1 : -1;
	}
	int mid = find(a.begin(), a.end(), 0) - a.begin();
	if (mid == a.size()) {
		cout << 0;
		return 0;
	}

	int sum = 0;

	map<int, int> left;
	for (int i = mid; i >= 0; --i) {
		++left[sum += a[i]];
	}

	sum = 0;
	map<int, int> right;
	for (int i = mid; i < n; ++i)
		++right[sum += a[i]];

	ll ans = 0;
	for (int s = -2 * n; s <= 2 * n; ++s) {
		ans += (ll)left[s] * right[-s];
		ans += (ll)left[s] * right[1-s];
	}
	cout << ans;
	return 0;
}