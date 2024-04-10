#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, B = 555;
int n, m, x[N], y[N], d[N], ad[N], buc[B][B];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
	for(int i = 1, cur = 0; i <= m; i++) {
		int op, k, s, ans = 0; scanf("%d %d", &op, &k);
		s = x[k] + y[k], op == 1 ? cur++ : cur--;
		if(s < B) {
			if(op == 1) for(int j = 0; j < x[k]; j++) buc[((ad[k] = i) + j) % s][s] += op == 1 ? 1 : -1;
			else for(int j = 0; j < x[k]; j++) buc[(ad[k] + j) % s][s] += op == 1 ? 1 : -1;
		} else if(op == 1) for(int j = ad[k] = i; j <= m; j += s) d[j]++, d[min(j + x[k], m + 1)]--;
		else for(int j = ad[k]; j <= m; j += s) d[max(i, j)]--, d[max(i, min(j + x[k], m + 1))]++;
		for(int j = 2; j < B; j++) ans += buc[i % j][j];
		cout << cur - ans - (d[i] += d[i - 1]) << "\n";
	} return 0;
}