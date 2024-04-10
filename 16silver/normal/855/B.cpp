#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[100000],m[2][100000],M[2][100000];
int main() {
	int n, i;
	long long p, q, r, tmp, ans = 0;
	scanf("%d%lld%lld%lld", &n, &p, &q, &r);
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);
	tmp = a[0];
	for (i = 0; i < n; i++) {
		if (tmp > a[i]) tmp = a[i];
		m[0][i] = tmp;
	}
	tmp = a[0];
	for (i = 0; i < n; i++) {
		if (tmp < a[i]) tmp = a[i];
		M[0][i] = tmp;
	}
	tmp = a[n - 1];
	for (i = n - 1; i >= 0; i--) {
		if (tmp > a[i]) tmp = a[i];
		m[1][i] = tmp;
	}
	tmp = a[n - 1];
	for (i = n - 1; i >= 0; i--) {
		if (tmp < a[i]) tmp = a[i];
		M[1][i] = tmp;
	}
	for (i = 0; i < n; i++) {
		tmp = a[i] * q;
		if (p > 0) tmp += M[0][i] * p;
		else tmp += m[0][i] * p;
		if (r > 0) tmp += M[1][i] * r;
		else tmp += m[1][i] * r;
		if (i == 0) ans = tmp;
		else if (tmp > ans) ans = tmp;
	}
	printf("%lld", ans);
}