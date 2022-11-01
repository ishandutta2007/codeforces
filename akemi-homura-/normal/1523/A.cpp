#include <bits/stdc++.h>
using namespace std;
int n, m, dis1[1005], dis2[1005];
char s[1005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d %s", &n, &m, s + 1);
		for (int i = 1; i <= n; i++) dis1[i] = dis2[i] = INT_MAX;
		for (int i = 1, lst = 0; i <= n; i++) {
			if (s[i] == '1') {
				lst = i;
			}
			if (lst) dis1[i] = i - lst;
		}
		for (int i = n, lst = 0; i >= 1; i--) {
			if (s[i] == '1') {
				lst = i;
			}
			if (lst) dis2[i] = lst - i;
		}
		for (int i = 1; i <= n; i++) if (min(dis1[i], dis2[i]) <= m && dis1[i] != dis2[i]) s[i] = '1';
		puts(s + 1);
	}
	return 0;
}