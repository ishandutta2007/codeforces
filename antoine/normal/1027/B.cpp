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

	ll n, q;
	cin >> n >> q;
	while (q--) {
		ll x, y;
		cin >> x >> y;
		--x, --y;
		if ((x + y) & 1)
			cout << 1 + (x / 2) * n + (x & 1) * ((n + 0) / 2) + y / 2 + (n*n + 1) / 2 << '\n';
		else
			cout << 1 + (x / 2) * n + (x & 1) * ((n + 1) / 2) + y / 2 << '\n';
	}
	return 0;
}