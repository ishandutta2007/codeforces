#include<cstdio>
#include<algorithm>
using namespace std;
int n, pv = -1;
long long w[150000], Mx, res[150000], ss, ck = 0;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld", &w[i]);
		if (Mx < w[i])Mx = w[i];
		ss += w[i];
	}
	if (Mx == 0) {
		puts("YES");
		for (i = 0; i < n; i++)printf("%d ", 2);
		return 0;
	}
	for (i = 0; i < n; i++) {
		if (w[i] != Mx && w[(i + 1) % n] == Mx) {
			pv = (i + 1) % n;
		}
	}
	if (pv == -1) {
		puts("NO");
		return 0;
	}
	res[pv] = Mx;
	for (i = 0; i < n - 1; i++) {
		int tpv = pv;
		pv = (pv + n - 1) % n;
		if (w[pv] == 0 && !ck) {
			res[pv] = res[tpv] * 3;
			ck = 1;
		}
		else {
			res[pv] = res[tpv] + w[pv];
		}
	}
	puts("YES");
	for (i = 0; i < n; i++)printf("%lld ", res[i]);
}