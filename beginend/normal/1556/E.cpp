#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100005;
const int M = 20;

int n, q, m, a[N], bin[M];
class data {
	public:
		LL mx, lef, rig;
	
	data() {
		mx = lef = rig = 0;
	}
}f[N][M];

void merge(data &ans, data x, data y) {
	if (x.lef >= y.rig) {
		ans.lef = x.lef + y.lef - y.rig;
		ans.rig = x.rig;
		ans.mx = max(x.mx, y.mx + x.lef - y.rig);
	}
	else {
		ans.lef = y.lef;
		ans.rig = x.rig + y.rig - x.lef;
		ans.mx = max(x.mx + y.rig - x.lef, y.mx);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		a[i] = x - a[i];
	}
	m = 0;
	while (1 << (m + 1) <= n) m++;
	bin[0] = 1;
	for (int i = 1; i <= m; i++) bin[i] = bin[i - 1] * 2;
	for (int i = 1; i <= n; i++) {
		f[i][0].mx = abs(a[i]);
		if (a[i] > 0) f[i][0].lef = a[i];
		else f[i][0].rig = -a[i];
	}
	for (int j = 1; j <= m; j++)
		for (int i = 1; i + bin[j] - 1 <= n; i++) {
			merge(f[i][j], f[i][j - 1], f[i + bin[j - 1]][j - 1]);
		}
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		data ans;
		for (int i = m; i >= 0; i--)
			if (l + bin[i] - 1 <= r) {
				merge(ans, ans, f[l][i]);
				l += bin[i];
			}
		if (!ans.lef && !ans.rig) printf("%lld\n", ans.mx);
		else puts("-1");
	}
	return 0;
}