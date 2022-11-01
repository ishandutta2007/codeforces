#include <iostream>
#include <algorithm>
using namespace std;

const int N = 92;

long long f[N + 5];
long long dp0[N], dp1[N], dp2[N];
int a[N];

int main() {
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i < N; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
//	cout << f[N] << endl;
	int t;
	cin >> t;
	
	for (int ii = 0; ii < t; ii++) {
		long long n;
		cin >> n;
		fill(a, a + N, 0);
		for (int i = N - 1; i >= 0; i--) {
			if (n >= f[i]) {
				a[i] = 1;
				n -= f[i];
			}
		}
		fill(dp0, dp0 + N, 0);
		fill(dp1, dp1 + N, 0);
		fill(dp2, dp2 + N, 0);
		dp0[0] = 1;
		for (int i = 1; i < N; i++) {
			if (a[i]) {
				dp0[i] = dp0[i - 1] + dp2[i - 1];
				dp1[i] = dp2[i - 1];
				dp2[i] = 0;
			}
			else {
				dp0[i] = dp0[i - 1];
				dp1[i] = dp0[i - 1] + dp2[i - 1];
				dp2[i] = dp1[i - 1];
			}
		}
		cout << dp0[N - 1] << '\n';
	}
	return 0;
}