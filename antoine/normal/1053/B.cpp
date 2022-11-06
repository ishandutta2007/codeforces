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

int popCnt(ll x) {
	int res = 0;
	while (x) {
		res++;
		x &= x - 1;
	}
	return res;
}

int n;
int a[(int)3e5 + 3];
int cs[(int)3e5 + 3];
int cnt[(int)3e5 + 3][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		a[i] = popCnt(x);
		assert(a[i] < 64);
	}

	partial_sum(a, a + n + 1, cs);

	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < 2; ++j)
			cnt[i][j] = cnt[i + 1][j] + ((cs[i] & 1) == j);
	}


	ll ans = 0;

	for (int i = 1; i <= n; ++i) {
		int sum = 0, mx = 0;
		for (int j = i; j <= n; ++j) {
			sum += a[j];
			mx = max(mx, a[j]);
			ans += sum >= (mx << 1) && !(sum & 1);
			if (sum >= 128) {
				ans += cnt[j + 1][cs[i - 1] & 1];
				break;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}