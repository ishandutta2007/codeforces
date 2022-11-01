#include <bits/stdc++.h>

using namespace std;

#define int long long

int t, x, y, p, q;

main() {
	cin >> t;
	while(t--) {
		cin >> x >> y >> p >> q;
		int a = p - q, b = p, c = x * q - y * p, A = -x, B = x - y, G = __gcd(llabs(a), llabs(b));
		if(c % G || A < 0 && b == 0 || B < 0 && a == 0) {
			cout << -1 << '\n';
			continue;
		}
		a = - (a / G);
		b /= G;
		int L;
		if(a == 0) {
			L = (-A + b - 1) / b;
		} else if(b == 0) {
			L = (-B + a - 1) / a;
		} else {
			L = max((-A + b - 1) / b, (-B + a - 1) / a);
		}
		cout << A + B + L * (b + a) << '\n';
	}
}