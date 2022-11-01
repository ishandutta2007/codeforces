#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int N = 305, M = 100 * 1000 + 5;
const long double inf = 1e99;


long double chsn[M], chsm[M];
long double fac[M];

long double chs(int x, int y) {
	if (y > x) {
		return 0;
	}
	return fac[x] - fac[y] - fac[x - y];
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	chsn[0] = log(1);
	chsm[0] = log(1);
	for (int i = 1; i <= m; i++) {
		chsn[i] = chsn[i - 1] + log(n - i + 1) - log(i);
		chsm[i] = chsm[i - 1] + log(m - i + 1) - log(i);
		fac[i] = fac[i - 1] + log(i);
	}
	cout << fixed << setprecision(10);
//	cout << exp(chsn[2]);
	long double ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (k - (i + j) * n + i * j < 0) {
				continue;
			}
		//	cout << "73 " << i << " " << j << " " << exp(chsn[i] + chsn[j] + chs(m - (i + j) * n + i * j, k - (i + j) * n + i * j) - chsm[k]) << endl//;
			ans += exp(chsn[i] + chsn[j] + chs(m - (i + j) * n + i * j, k - (i + j) * n + i * j) - chsm[k]);
		//	cout << "48" << " " << exp(chsn[i]) << " " << exp(chsn[j]) << " " << exp(chs(m - (i + j) * n + i * j, k - (i + j) * n + i * j)) << " " << exp(chsm[k]) << endl;
			if (ans > inf) {
				cout << inf;
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}