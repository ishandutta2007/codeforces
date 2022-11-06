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
const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<ll> pre(n + 1, 0);
	for (int i = 1; i < pre.size(); ++i)
		pre[i] = (pre[i - 1] + (i < k ? 0 : 1 + (i - k) / (k - 1))) % mod;


	vector<int> lo(n);
	stack<pair<int, int>> stck;
	for (int i = 0; i < n; ++i) {
		while (!stck.empty() && stck.top().second < a[i])
			stck.pop();

		lo[i] = stck.empty() ? 0 : stck.top().first + 1;

		stck.emplace(i, a[i]);
	}


	vector<int> hi(n);
	stck = stack<pair<int, int>>();
	for (int i = n - 1; i >= 0; --i) {
		while (!stck.empty() && stck.top().second <= a[i])
			stck.pop();

		hi[i] = stck.empty() ? n : stck.top().first;

		stck.emplace(i, a[i]);
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		assert(lo[i] <= i && hi[i] > i);
		// cerr << "DEBUG " << a[i] << ' ' << hi[i] - lo[i] << ' ' << pre[hi[i] - lo[i]] << endl;
		ans += (ll)a[i] * (pre[hi[i] - lo[i]] - pre[i - lo[i]] - pre[hi[i] - (i + 1)]) % mod;
	}
	cout << (ans % mod + mod) % mod << '\n';

	return 0;
}