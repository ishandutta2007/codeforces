#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int val[210];
int main() {
	int n;
	scanf("%d", &n);
	// find the value of a[n]
	int lastVal = 1;
	for (lastVal = 1; lastVal < n; lastVal++) {
		printf("? ");
		for (int i = 1; i < n; i++) printf("%d ", lastVal+1);
		printf("1\n");
		fflush(stdout);
		int a;
		scanf("%d", &a);
		if (!a) break;
	}
	val[n] = lastVal;
	// we know the last value
	for (int v = 1; v <= n; v++) {
		if (v != lastVal) {
			int delta = v-lastVal;
			if (delta < 0) {
				// lastVal > v
				// put 1 on lastVal, -delta+1 on everything else
				printf("? ");
				for (int i = 1; i < n; i++) printf("%d ", -delta+1);
				printf("1\n");
				fflush(stdout);
				int a;
				scanf("%d", &a);
				assert(a);
				val[a] = v;
			} else {
				// put delta+1 on last, 1 on everything else
				printf("? ");
				for (int i = 1; i < n; i++) printf("%d ", 1);
				printf("%d\n", delta+1);
				fflush(stdout);
				int a;
				scanf("%d", &a);
				assert(a);
				val[a] = v;
			}
		}
	}
	printf("! ");
	for (int i = 1; i <= n; i++) printf("%d ", val[i]);
	printf("\n");
}