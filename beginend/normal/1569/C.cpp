#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;
const int MOD = 998244353;

int n, a[N], jc[N], ny[N];

int main() {
	jc[0] = jc[1] = ny[0] = ny[1] = 1;
	for (int i = 2; i <= 200000; i++)
		jc[i] = (LL)jc[i - 1] * i % MOD, ny[i] = (LL)(MOD - MOD / i) * ny[MOD % i] % MOD;
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int mx1 = 0, mx2 = 0, s1 = 0, s2 = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] == mx1) s1++;
			else if (a[i] > mx1) {
				mx2 = mx1; s2 = s1;
				mx1 = a[i]; s1 = 1;
			}
			else if (a[i] == mx2) s2++;
			else if (a[i] > mx2) {
				mx2 = a[i]; s2 = 1;
			}
		}
		if (s1 > 1) printf("%d\n", jc[n]);
		else if (mx1 - mx2 > 1) printf("%d\n", 0);
		else printf("%d\n", (jc[n] + MOD - (LL)jc[n] * ny[s2 + 1] % MOD) % MOD);
	}
	return 0;
}