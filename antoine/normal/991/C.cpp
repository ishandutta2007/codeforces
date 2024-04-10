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

ll f(ll n, ll k) {
	if (n <= k)
		return n;
	n -= k;
	n -= n / 10;
	return k + f(n, k);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;
	ll lo = 1;
	ll hi = n;
	while (lo < hi) {
		ll mid = (lo + hi) >> 1;
		
		if (f(n, mid) >= (n + 1) / 2)
			hi = mid;
		else
			lo = mid + 1;
	}

	cout << lo;
	return 0;
}