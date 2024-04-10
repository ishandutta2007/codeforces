#include<bits/stdc++.h>
using namespace std;

int T;
int n, a[1000015], f[1000015][2][2], from[1000015][2][2];

void Output(int x, int y) {
	int p = y >> 1, q = y & 1;
	if(x > 1) Output(x - 1, from[x][p][q]);
	printf("%d ", q == 0 ? -a[x] : a[x]);
}

void Solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) for(int p : {0, 1}) for(int q : {0, 1}) f[i][p][q] = n + 1;
	for(int q : {0, 1}) f[1][0][q] = - (n + 1);
	for(int i = 1; i < n; ++i) {
		for(int p : {0, 1}) for(int q : {0, 1}) for(int nq : {0, 1}) {
			int x = q == 0 ? -a[i] : a[i], y = f[i][p][q], z = nq == 0 ? -a[i + 1] : a[i + 1];
			if(y > n) continue;
			auto check = [&](int op, int oq, int v) {
				if(f[i + 1][op][oq] > v) f[i + 1][op][oq] = v, from[i + 1][op][oq] = p << 1 | q;
			};
			if(p) swap(x, y);
			if(z >= x) check(0, nq, y);
			else if(z >= y) check(1, nq, x);
		}
	}
	int res = -1;
	for(int p : {0, 1}) for(int q : {0, 1}) if(f[n][p][q] <= n) res = p << 1 | q;
	if(~res) {
		printf("YES\n");
		Output(n, res);
		printf("\n");
	} else printf("NO\n");
}

int main() {
	for(scanf("%d", &T); T; T--) Solve();
}