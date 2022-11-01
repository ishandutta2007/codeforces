#include <iostream>
using namespace std;

int l, m;

long long a[3][3];
long long b[3][3];
long long c[3][3];
long long get(long long x, int y) {
	return (x >> y) & 1;
}
void cal(long long x) {
	if (x == 0) {
	//	for (int i = 0; i < 2; i++) {
	//		for (int j = 0; j < 2; j++) {
	//			a[i][j] = c[i][j];
	//		}
	//	}
		return;
	}
	cal(x / 2);
	b[0][0] = a[0][0] * a[0][0] + a[0][1] * a[1][0];
	b[0][1] = a[0][0] * a[0][1] + a[0][1] * a[1][1];
	b[1][0] = a[1][0] * a[0][0] + a[1][1] * a[1][0];
	b[1][1] = a[1][0] * a[0][1] + a[1][1] * a[1][1];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = b[i][j] % m;
		}
	}
	if (x % 2 == 1) {
	//	cout << 73 << endl;
		b[0][0] = a[0][0] * c[0][0] + a[0][1] * c[1][0];
		b[0][1] = a[0][0] * c[0][1] + a[0][1] * c[1][1];
		b[1][0] = a[1][0] * c[0][0] + a[1][1] * c[1][0];
		b[1][1] = a[1][0] * c[0][1] + a[1][1] * c[1][1];	
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				a[i][j] = b[i][j] % m;
			}
		}	
	}
}
long long po(long long x, long long y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= m;
	if (y % 2 == 1) {
		ans *= x;
		ans %= m;
	}
	return ans;
}
int main() {
	long long n, k;
	cin >> n >> k >> l >> m;
	for (int i = 0; i < 64; i++) {
		if (get(k, i) && i >= l) {
			cout << 0 << endl;
			return 0;
		}
	}
//	int x = __builtin_popcount(k);
/*	long long ans = po((po(2, n - 1) - 1), x);
	ans %= m;
	ans *= 1ll * po((po(2, n) - po(2, n - 1) + 1), l - x);
	ans %= m;*/
//	cout << (po(2, n - 1) - 1) << " " << po(2, n) - po(2, n - 1) + 1 + m << endl;
	c[0][0] = 1;
	c[0][1] = 1;
	c[1][0] = 1;
	a[0][0] = 1;
	a[1][1] = 1;
	cal(n + 1);
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 2; j++) {
//			cout << a[i][j] <<  " ";
//		}
//		cout << endl;
//	}
	long long ans = 1;
//	long long x = (a[0][0] + a[0][1]) % m;
//	cout << x << endl;
	for (int i = 0; i < l; i++) {
		if (get(k, i)) {
			ans *= po(2, n) - a[0][0] + m;
		}
		else {
			ans *= a[0][0];
		}
		ans %= m;
	}
	cout << ans % m << endl;
	return 0;
}