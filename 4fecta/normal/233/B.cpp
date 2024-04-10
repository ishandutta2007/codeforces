#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

ll n;

int s(ll x) {
	int r = 0;
	while (x > 0) {
		r += x % 10;
		x /= 10;
	}
	return r;
}

ll f(ll x) {
	return x*x+s(x)*x-n;
}

int main() {
	cin >> n;
	ll l = 0;
	ll r = (1LL<<31);
	for (int i = 0; i < 200; i++) {
		ll m = (l+r)/2;
		//cout << "l=" << l << ", r=" << r << endl;
		if (f(m) < 0) {
			l = m;
		} else {
			r = m;
		}
	}
	for (ll i = l-1000; i < l+1000; i++) {
		if (i <= 0)
			continue;
		if (f(i)==0) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}