#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, tmp, GCD = 0, res, tmp2;

ll Rand(ll l, ll r) {
	return l + ((1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1))
			 + (1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1))
			 + (1LL * rand() * (RAND_MAX + 1))
			 + rand()) % (r - l + 1);
}

int main() {
	cin >> n;
	cout << "? " << Rand(1, n) << endl;
	fflush(stdout);
	cin >> tmp2;
	for (int i = 1; i <= 27; i++) {
		cout << "? " << Rand(1, n) << endl;
		fflush(stdout);
		cin >> tmp;
		GCD = __gcd(GCD, abs(tmp - tmp2));
	}
	int l = 1, r = 1000000000;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		cout << "> " << mid << endl;
		fflush(stdout);
		cin >> tmp;
		if (tmp) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	for (int i = r - 1; i >= l - 1; i--) {
		cout << "> " << i << endl;
		fflush(stdout);
		cin >> tmp;
		if (tmp) {
			res = i + 1;
			break;
		}
	}
	cout << "! " << res - GCD * (n - 1) << " " << GCD << endl;
	return 0;
}