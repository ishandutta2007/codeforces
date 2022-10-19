#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 100010
int n;
int a[MAXN], b[MAXN];
int main() {
	int t;
	scanf("%d", &t);
	for (int _ = 0; _ < t; _++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
		}
		sort(a, a+n);
		sort(b, b+n);
		int poss = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i] || a[i] < b[i]-1) poss = 0;
		}
		if (poss) printf("YES\n");
		else printf("NO\n");
	}
}