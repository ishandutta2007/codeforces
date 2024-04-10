#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int M = 5e5 + 5;

int T, n, m;
boolean d[M], sec[M];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		memset(d + 1, false, n * 3);
		int cnt = 0;
		for (int i = 1, u, v; i <= m; i++){
			scanf("%d%d", &u, &v);
			if (!d[u] && !d[v]) {
				d[u] = d[v] = sec[i] = true;
				cnt++;
			} else {
				sec[i] = false;
			}
		}
		if (cnt >= n) {
			puts("Matching");
			for (int i = 1, fin = 0; fin < n; i++) {
				if (sec[i]) {
					printf("%d ", i);
					fin++;
				}
			}
		} else {
			puts("IndSet");
			for (int i = 1, fin = 0; fin < n; i++) {
				if (!d[i]) {
					printf("%d ", i);
					fin++;
				}
			}
		}
		putchar('\n');
	}
	return 0;
}