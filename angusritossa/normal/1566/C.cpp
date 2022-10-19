#include <bits/stdc++.h>
using namespace std;
char str[2][100010];
int inp[2][100010];
int taken[100010], n;
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d %s %s", &n, str[0], str[1]);
		for (int i = 0; i < n; i++) {
			inp[0][i] = str[0][i]-'0';
			inp[1][i] = str[1][i]-'0';
		}
		fill_n(taken, n, false);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (inp[0][i]+inp[1][i] == 1) {
				ans += 2;
			} else if (inp[0][i]+inp[1][i] == 0) {
				ans++;
			} else if (i > 0 && inp[0][i-1]+inp[1][i-1] == 0 && !taken[i-1]) {
				ans++;
			} else if (i < n-1 && inp[0][i+1]+inp[1][i+1] == 0) {
				taken[i+1] = 1;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}