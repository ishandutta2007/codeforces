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

	int n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	n += n;
	vector<ll> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());

	ll ans = (a[n / 2 - 1] - a[0]) * (a.back() - a[n / 2]);

	for (int i = 1; i + n / 2 - 1 < n - 1; ++i)
		ans = min(ans, (a.back() - a[0]) * (a[i + n/2 - 1] - a[i]));

	cout << ans;
	return 0;
}