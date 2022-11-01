#include <iostream>
using namespace std;


const int N = 2000 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;

long long fac[N];
int po(int x, int y) {
	if (y == 0)
		return 1;
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;;
	if (y % 2 == 1) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}
int chs(int x, int y) {
	long long ans = fac[x];
	ans *= po(fac[y], mod - 2);
	ans %= mod;
	ans *= po(fac[x - y], mod - 2);
	ans %= mod;
//	cout << "23 " << x << " " << y << " " << ans << endl;
	return ans;
}
int main() {
	int q;
	cin >> q;
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
	for (int i = 0; i < q; i++) {
		long long ans = 1;
		int x, y;
		cin >> x >> y;
		for (int j = 2; j * j <= x; j++) {
			int t = 0;
			while (x % j == 0) {
				t++;
				x /= j;
			}
			if (t) {
//				cout << 73 << " " << t << endl;
//				cout << "49 " << chs(y + t - 1, t) << endl;
				ans *= chs(y + t - 1, t);
				ans %= mod;
			}
			
		}
		if (x > 1)
			ans *= y;
		ans %= mod;
		ans *= po(2, y - 1);
		ans %= mod;
		cout << ans << endl;
	}
	return 0;
}