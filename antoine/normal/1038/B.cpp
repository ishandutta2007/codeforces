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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	ll n;
	cin >> n;
	if (n <= 2) {
		cout << "No\n";
		return 0;
	}
	const ll total = n*(n + 1) / 2;
	for (ll sum = 1;; ++sum)
		if (gcd(sum, total - sum) > 1) {
			cout << "Yes\n";
			cout << 1 << ' ' << sum << '\n';
			cout << n - 1;
			for (ll i = 1; i <= n; ++i)
				if (i != sum)
					cout << ' ' << i;
			cout << '\n';
			return 0;
		}
	return 0;
}