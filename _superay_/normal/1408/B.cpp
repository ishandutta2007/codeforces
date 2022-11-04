#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, k, a[N], b[N], vis[N];
inline bool check() {
	for (int i = 1; i <= n; i++) if (a[i]) return false;
	return true;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int cnt = 0;
		while (!check()) {
			cnt++;
			for (int i = 0; i <= 100; i++) vis[i] = 0;
			int li = 0, va = 0;
			for (int i = 1; i <= n; i++) {
				if (!vis[a[i]]) {
					li++;
					vis[a[i]] = 1;
					va = a[i];
				}
				if (li == k) break;
			}
			for (int i = 1; i <= n; i++) if (a[i] <= va) b[i] = 0; else b[i] = a[i];
			int flag = 0;
			for (int i = 1; i <= n; i++) if (a[i] != b[i]) { flag = 1; break; }
			if (!flag) { cnt = -1; break; }
			for (int i = 1; i <= n; i++) a[i] = b[i];
		}
		printf("%d\n", cnt);
	}
	return 0;
}