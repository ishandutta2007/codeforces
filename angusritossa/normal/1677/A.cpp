#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int numBefore[5010][5010], numAfter[5010][5010], p[5010];
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
			numAfter[n+1][i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				numBefore[i][j] = numBefore[i-1][j];
				if (p[i] <= j) numBefore[i][j]++;
			}
		}
		for (int i = n; i >= 1; i--) {
			for (int j = 1; j <= n; j++) {
				numAfter[i][j] = numAfter[i+1][j];
				if (p[i] <= j) numAfter[i][j]++;
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i+1; j <= n; j++) {
				int am = numBefore[i-1][p[j]] * numAfter[j+1][p[i]];
				ans += am;
			}
		}
		printf("%lld\n", ans);
	}
}