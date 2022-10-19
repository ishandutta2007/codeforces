#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n, k;
		scanf("%d%d", &n, &k);
		int poss = 0;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			poss += a;
		}
		if (poss) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}