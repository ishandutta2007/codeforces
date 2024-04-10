#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n, m, ans;
int st[N], ed[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		st[i] = m + 1;
	for (int i = 1, x; i <= m; i++) {
		scanf("%d", &x);
		st[x] = min(st[x], i);
		ed[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int d = -1; d <= 1; d++) {
			int j = i + d;
			if (j < 1 || j > n)
				continue;
			ans += st[i] > ed[j];
		}
	}
	printf("%d\n", ans);
	return 0;
}