#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 1e5 + 3;
const int ways[] = {0, 0, 1, 3, 6, 10, 15, 21, 28, 36, 45};

int n;
char s[N];
ll ans, f[N][11];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1, c; i <= n; i++) {
		c = s[i] - '0';
		(c) && (f[i][c]++);
		for (int r = c + 1; r < 11; r++) {
			f[i][(ways[r] + c + 10) % 11] += f[i - 1][r];
		}
		for (int j = 0; j < 11; j++) {
			ans += f[i][j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}