#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, a[N], f[6][N];
char s[N];
int ty[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) a[i] = s[i] - 'a';
	for (int j = 0; j < 6; j++)
		for (int i = 1; i <= n; i++)
			f[j][i] = f[j][i - 1] + (a[i] % 3 != ty[j][i % 3]);
	while (m--) {
		int l, r; scanf("%d%d", &l, &r);
		int ans = n;
		for (int i = 0; i < 6; i++)
			ans = min(ans, f[i][r] - f[i][l - 1]);
		printf("%d\n", ans);
	}
	return 0;
}