#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll a = 1;
	ll b = 2;
	for (int i = 2;; i++) {
		ll c = a + b;
		if (c > n) {
			cout << i - 1 << endl;
			return 0;
		}
		a = b;
		b = c;
	}
	return 0;
}