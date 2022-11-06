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

ll f(ll n, ll m, ll k) {
	if (k < m) return -1;
	if ((n + m) & 1) return k - 1;
	return k - ((k - m) & 1 ? 2 : 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		ll n, m, k;
		cin >> n >> m >> k;
		n = abs(n);
		m = abs(m);
		if (n > m)
			swap(n, m);
		cout << f(n, m, k) << '\n';
	}
	return 0;
}