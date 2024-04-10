#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5, D = 105;
const int mod = 1000 * 1000 * 1000 + 7;

int a[D + 5];
long long dp[2 * D];
struct matrix {
	long long m[D][D];
};
matrix zarb(matrix a, matrix b) {
//	cout << 38 << endl;
	matrix c;
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < D; j++) {
		//	cout << "73 " << i << " " << j << endl;
			c.m[i][j] = 0;
			for (int k = 0; k < D; k++) {
				c.m[i][j] += 1ll * a.m[i][k] * b.m[k][j];
				c.m[i][j] %= mod;
			}
		}
	}
	return c;
}
matrix po(matrix a, int y) {
//	cout << "48 " << y << endl;
	if (y == 1)
		return a;
//	cout << "49 " << y << endl;
	matrix b = po(a, y / 2);
//	cout << "50 " << y << endl;
	matrix c = zarb(b, b);
	if (y % 2 == 1) {
		matrix d = zarb(c, a);
		return d;
	}
	return c;
}
int main() {
	int n, x;
	cin >> n;
	cin >> x;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = D - 2; i > 0; i--) {
		a[i + 1] -= a[i];
	}
	a[1]++;
//	for (int i = 1; i < D; i++) {
	//	cout << i << " " << a[i] << endl;
//	}
	dp[0] = 1;
	for (int i = 1; i < 2 * D; i++) {
		for (int j = 1; j < D && i - j >= 0; j++) {
			dp[i] += 1ll * dp[i - j] * a[j];
			dp[i] += 1000ll * mod;
			dp[i] %= mod;
		//	cout << i << " " << j << " " << dp[i] << endl;
		}
	//	cout << dp[i] << endl;
	}
//	cout << dp[x] << endl;
	if (x < 2 * D) {
		cout << dp[x];
		return 0;
	}
	matrix b, c;
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < D; j++) {
			b.m[i][j] = dp[i + j];
		}
	}
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < D; j++) {
			c.m[i][j] = 0;
		}
	}
	for (int i = 1; i < D; i++) {
		c.m[i][i - 1] = 1;
	}
	for (int i = 0; i < D; i++) {
		c.m[i][D - 1] = a[D - i];
	}
	matrix d = po(c, x - 2 * D + 2);
	matrix e = zarb(b, d);
	cout << e.m[D - 1][D - 1];
	return 0;
}