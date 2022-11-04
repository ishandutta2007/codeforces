#include <bits/stdc++.h>
using namespace std;
int n, a[1005], vis[1005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			vis[i] = 0;
		}
		int pref = -1;
		for (int i = 1; i <= n; i++) {
			int fr = 0;
			for (int j = 1; j <= n; j++) if (!vis[j]) {
				if (!fr || ((pref == -1) ? (a[j] > a[fr]) : (__gcd(pref, a[j]) > __gcd(pref, a[fr])))) {
					fr = j;
				}
			}
			vis[fr] = 1;
			if (pref == -1) pref = a[fr];
			else pref = __gcd(pref, a[fr]);
			printf("%d%c", a[fr], " \n"[i == n]);
		}
	}
	return 0;
}