#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int a[200010], at[200010];
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			at[a[i]] = i;
		}
		for (int i = n-1; i >= 1; i--) {
			printf("%d ", at[i]);
		}
		printf("1\n");
	}
}