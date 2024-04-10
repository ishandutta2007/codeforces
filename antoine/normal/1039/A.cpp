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

void No() {
	cout << "No\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int n;
	ll t;
	cin >> n >> t;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		--x[i];
		if (x[i] < i) No();
	}

	vector<int> dp(n, 0);
	for (int i = 0; i < n; ++i) {
		++dp[i];
		--dp[x[i]];
	}
	partial_sum(dp.begin(), dp.end(), dp.begin());
	assert(dp.back() == 0);

	vector<ll> lb(n);
	for(int i = 0; i < n; ++i)
		lb[i] = (dp[i] ? a[i + 1] : a[i]) + t;

	vector<ll> ub(n, (ll)3e18 + 999);
	for(int i = 0; i < n; ++i)
		if (x[i] != n - 1) {
			ub[x[i]] = a[x[i] + 1] + t - 1;
		}


	for (int i = 0; i < n; ++i)
		if (lb[i] > ub[i]) No();

	vector<ll> b(n);
	b[0] = lb[0];
	for (int i = 1; i < n; ++i) {
		b[i] = max(b[i - 1] + 1, lb[i]);
		if (b[i] > ub[i]) No();
	}
	cout << "Yes\n";
	for (auto &&x : b)
		cout << x << ' ';
	return 0;
}