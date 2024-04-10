#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int t;
int main() {
	scanf("%d", &t);
	for (int _ = 0; _ < t; _++) {
		int n, z;
		scanf("%d%d", &n, &z);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			ans = max(ans, (a|z));
		}
		printf("%d\n", ans);
	}
}