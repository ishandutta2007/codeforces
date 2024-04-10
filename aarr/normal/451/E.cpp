#include <iostream>
//#define int long long
using namespace std;

const int N = 25, mod = 1000 * 1000 * 1000 + 7;
int n;
long long s;
int fp[N];

long long a[N];

int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}

int get(int x, int y) {
	return (x >> y) & 1;
}

long long get(int mask) {
	long long x = s + n - 1;
	for (int i = 0; i < n; i++) {
		if (get(mask, i)) {
			x -= a[i] + 1;
		}
	}
//	cout << "72 " << mask << " " << x << " " << n << endl;
	if (n - 1 > x) {
		return 0;
	}
	long long ans = 1;
	for (int i = 1; i < n; i++) {
		ans *= (x % mod);
		x--;
		ans %= mod;
		ans *= fp[i];
		ans %= mod;
	}
//	cout << "73 " << mask << " " << ans << endl;
	return ans;
}

int32_t main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		fp[i] = po(i, mod - 2);
	}
	long long ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		int x = get(mask);
		if (__builtin_popcount(mask) % 2) {
			ans -= x - mod;
		}
		else {
			ans += x;
		}
	}
	ans %= mod;
	cout << ans;
	return 0;
}