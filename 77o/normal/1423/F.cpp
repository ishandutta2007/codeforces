#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll n;
	int k;
	cin >> n >> k;
	ll s = n * (n - 1) / 2;
	s %= n;
	ll t = 0;
	ll cnt = 0;
	for (int i = 0; i < k; i++) {
		ll a, b;
		cin >> a >> b;
		(t += a * b) %= n;
		cnt += b;
	}
	if (cnt < n) {
		cout << "1\n";
	} else if (cnt > n) {
		cout << "-1\n";
	} else {
		if (s == t) {
			cout << "1\n";
		} else {
			cout << "-1\n";
		}
	}
    return 0;
}