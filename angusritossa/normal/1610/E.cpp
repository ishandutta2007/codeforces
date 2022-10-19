#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define MAXN 200010
int a[MAXN], m;
map<int, int> occ;
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n;
		occ.clear();
		scanf("%d", &n);
		m = n;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			occ[a[i]]++;
			if (occ[a[i]] > 1) {
				i--;
				n--;
			}
		}
		int ans = m;
		for (int i = 0; i < n; i++) {
			int am = occ[a[i]];
			int prev = 1;
			while (1) {
				int pos = distance(a, lower_bound(a, a+n, a[i]+prev));
				//printf("prev %d pos %d\n", prev, pos);
				if (pos == n) break;
				am++;
				prev = 2*(a[pos]-a[i]);
			}
			//printf("%d: %d\n", i, am);
			ans = min(ans, m-am);
		}
		printf("%d\n", ans);
	}
}