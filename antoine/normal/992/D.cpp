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

/*
10 10
1 1 1 2 3 1 1 2 1 1
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	ll k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> last(n, -1);
	for(int i = n - 1; i >= 0; --i)
		if (a[i] == 1) {
			if (i == n - 1)
				last[i] = i;
			else
				last[i] = a[i + 1] != 1 ? i : last[i + 1];
		}

	vector<ll> cs(n);

	for (int i = 0; i < n; ++i)
		cs[i] = a[i] + (i ? cs[i - 1] : 0);

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll p = 1;
		for (int j = i; j < n; ++j) {
			const ll sum = cs[j] - (i ? cs[i - 1] : 0ll);
			if (a[j] != 1) {
				if ((double)p * a[j] > 3e18)
					break;
				p *= a[j];
				if (p > (ll)2e18  + 5)
					break;
				ans += k * sum == p;
			} else {
				assert(last[j] != -1);
				const ll farSum = cs[last[j]] - (i ? cs[i - 1] : 0ll);
				ans += p%k == 0 &&
					k*sum <= p &&
					k * farSum >= p;
				j = last[j];
			}
		}
	}
	cout << ans;
	return 0;
}