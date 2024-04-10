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
	cin.tie(0), cout.tie(0);

	ll n, k;
	cin >> n >> k;

	ll lo = 1, hi = 1e16;
	while (lo < hi) {
		const ll mid = (lo + hi) >> 1;
		if (k - mid <= n)
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << max(0LL, (k - 1) / 2 - lo + 1);
	return 0;
}