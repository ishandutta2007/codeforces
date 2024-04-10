#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long s, w[101000], S[101000];
void Solve() {
	int i;
	scanf("%d%lld", &n,&s);
	int pv = 0;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		S[i] = S[i - 1] + w[i];
		if (S[i] <= s) {
			pv = i;
		}
	}
	if (pv == n || pv == n - 1) {
		puts("0");
		return;
	}
	int cnt = pv;
	long long Mx = 0;
	pv = 0;
	for (i = 1; i <= cnt+1; i++) {
		if (Mx < w[i]) {
			Mx = w[i];
			pv = i;
		}
	}
	long long sum = S[cnt+1] - Mx;
	int res = 0;
	for (i = cnt + 2; i <= n; i++) {
		sum += w[i];
		if (sum <= s) {
			res = pv;
		}
	}
	printf("%d\n", res);
}
int main() {
	int a, b, c, TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}