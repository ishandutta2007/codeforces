#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

int n, m;
int a[N];

int main() {
	scanf("%d%*d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	int p = 1;
	scanf("%d", &m);
	for (int i = 1, x; i <= m; i++) {
		scanf("%d", &x);
		while (p <= n && a[p] < x)
			p++;
		if (p == 1 || p > n) {
			puts("1.570796326794897");
			continue;
		}
		if (a[p - 1] + 1 == x && a[p] == x) {
			puts("3.141592653589793");
			continue;
		}
		if (a[p - 1] + 1 == x || a[p] == x) {
			puts("1.570796326794897");
			continue;
		}
		if (a[p - 1] + 2 == x && a[p] - 1 == x) {
			puts("1.570796326794897");
			continue;
		}
//		double theta = 1.0 / min(x - a[p - 1] - 1, a[p] - x);
		int L = min(x - a[p - 1] - 1, a[p] - x);
		int lim = L * 3, dis = 1400000000;
		int pr = p;
		for (int i = p - 1, d, _d; i && (d = x - a[i] - 1) <= lim; i--) {
			while (pr < n && (a[pr + 1] - x <= d))
				pr++;
			_d = a[pr] - x;
			if (_d == d || _d == d - 1) {
				dis = d;
				break;
			}
		}
		int pl = p - 1;
		for (int i = p, d, _d; i <= n && (d = a[i] - x) <= lim && d <= dis; i++) {
			while (pl > 1 && (x - a[pl - 1] - 1 <= d))
				pl--;
			_d = x - a[pl] - 1;
			if (_d == d || _d == d - 1) {
				dis = d;
				break;
			}
		} 
		double theta = 1.0 / L;
		if (dis < 1400000000) {
			assert(dis > 1);
			double x = 1.0 / dis;
			theta = max(theta, 2 * x / (1 - x * x));
		}
		theta = atan(theta);
		printf("%.15lf\n", theta);
	}
	return 0;
}