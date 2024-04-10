#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 100010
int bad[MAXN];
int t, n;
int main() {
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d", &n);
		fill_n(bad, n+1, false);
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			bad[b] = true;
		}
		int root = 0;
		for (int i = 1; i <= n; i++) {
			if (!bad[i]) root = i;
		}
		for (int i = 1; i <= n; i++) {
			if (i != root) {
				printf("%d %d\n", root, i);
			}
		}
	}
}