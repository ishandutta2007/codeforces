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
#include <stack>


using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b) {
	return a*b / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, ans = 0;
	cin >> n;

	for (ll i = max(1ll, n - 100); i <= n; ++i)
		for (ll j = max(1ll, n - 100); j <= n; ++j)
			for (ll k = max(1ll, n - 100); k <= n; ++k)
				ans = max(ans, lcm(lcm(i, j), k));
	cout << ans;
	return 0;
}