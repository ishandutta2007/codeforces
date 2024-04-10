#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

ll f(ll n) {
	if (n <= 1)
		return n;
	return n % 2 + 2 * f(n / 2); 
}

ll solve(ll n, ll k, ll l, ll r) {
	// cout << n << " " << k << " " << l << " " << r << endl;
	if (l == 0 && r == (1ll << k) - 1)
		return f(n);
	
	ll ans = 0;

	ll mid = (1ll << (k - 1)) - 1;

	if (l < mid)
		ans += solve(n / 2, k - 1, l, min(r, mid));

	if (l <= mid && mid < r)
		ans += n % 2;

	if (mid+ 1 < r)
		ans += solve(n / 2, k - 1, max(l - mid - 1, 0ll), r - mid - 1);

	return ans;
}

int main() {
	// freopen("arithmetic.in", "r", stdin);
	// freopen("arithmetic.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, l, r;
	cin >> n >> l >> r;
	--l;
	ll k = 0;
	for (; n > (1ll << k) - 1; ++k);

	cout << solve(n, k, l, r) << endl;
}