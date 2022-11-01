#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int mod = 1000 * 1000 * 1000 + 7;
const long long MAX = 2000ll * 1000 * 1000 * 1000 * 1000 * 1000;

int po(long long n, long long m) {
	if (m == 0)
		return 1;
	long long ans = po(n, m / 2);
	ans *= ans;
	ans %= mod;
	if (m % 2 == 1) {
		ans *= n;
		ans %= mod;
	}
	return ans;
}

vector <long long> v;
int32_t main() {
	long long x, n;
	cin >> x >> n;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			v.push_back(i);
		while (x % i == 0) {
			x /= i;
		}
	}
	if (x > 1)
		v.push_back(x);
	long long ans = 1;
	for (int i = 0; i < v.size(); i++) {
		long long p = v[i];
	//	cout << p << endl;
		while (p <= n) {
	//		cout << p << endl;
			long long t = n / p;
	//		cout << p << " " << t << endl;
			ans *= po(v[i] % mod, t);
			ans %= mod;
			if (p >= MAX / v[i])
				break;
			p *= v[i];
			if (p < v[i])
				break;
		}
	}
	cout << ans << endl;
	return 0;
}