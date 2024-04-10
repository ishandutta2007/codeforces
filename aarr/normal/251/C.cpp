#include <iostream>
using namespace std;

const int N = 370 * 1000;

int bmm(int x, int y) {
	if (y == 0) {
		return x;
	}
	return bmm(y, x % y);
}

int dp1[N], dp2[N];
int main() {
	long long a, b;
	int k;
	cin >> b >> a >> k;
	long long n = 1;
	for (int i = 2; i <= k; i++) {
		n = n * i / bmm(n, i);
	}
//	fill(dp1 + 1, dp1 + n, N);
	fill(dp2, dp2 + n + 1, N);
	for (int i = 1; i <= n; i++) {
		dp1[i] = dp1[i - 1] + 1;
		for (int j = 2; j <= k; j++) {
			dp1[i] = min(dp1[i], dp1[i - i % j] + 1);
		}
	}
//	cout << n << endl;
	dp2[a % n] = 0;
	for (int i = a % n + 1; i <= n; i++) {
		dp2[i] = dp2[i - 1] + 1;
		for (int j = 2; j <= k; j++) {
			dp2[i] = min(dp2[i], dp2[i - i % j] + 1);
		}		
	}
//	for (int i = 0; i <= n; i++) {
//		cout << "73 " << i << " " << dp1[i] << " " << dp2[i] << endl;
//	}
	long long x = (b - 1) / n - (a - 1) / n;
	if (x == 0) {
		cout << dp2[b % n];
	}
	else {
		if (b % n == 0) {
			x++;
		}
		cout << 1ll * (x - 1) * dp1[n] + dp2[n] + dp1[b % n];
	}
	return 0;
}