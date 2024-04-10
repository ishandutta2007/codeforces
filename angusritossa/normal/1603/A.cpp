#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int firstNonFactor(int a) {
	for (int i = 2; 1; i++) {
		if (a%i) {
			return i;
		}
	}
}
#define MAXN 100010
int a[MAXN];
int main() {
	int t;
	scanf("%d", &t);
	for (int _ = 0; _ < t; _++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int poss = 1;
		for (int i = 0; i < n; i++) {
			int f = firstNonFactor(a[i]);
			if (f > i+2) poss = 0;
		}
		if (poss) printf("YES\n");
		else printf("NO\n");
	}
}