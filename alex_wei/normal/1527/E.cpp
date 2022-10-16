#include <bits/stdc++.h>
using namespace std;

const int N = 4e4 + 5;
int n, k, x, y, cur, pre[N], suf[N], buc[N], a[N], f[N], g[N];
void solve(int pl, int pr, int l, int r) {
	int m = l + r >> 1, lim = min(pr, m - 1), p;
	while(y < m) y++, cur += pre[y] < x ? 0 : y - pre[y];
	while(x > pl + 1) x--, cur += suf[x] > y ? 0 : suf[x] - x;
	while(y > m) cur -= pre[y] < x ? 0 : y - pre[y], y--;
	while(x < pl + 1) cur -= suf[x] > y ? 0 : suf[x] - x, x++;
	f[m] = g[pl] + cur, p = pl;
	for(int i = pl + 1; i <= lim; i++) {
		cur -= suf[x] > y ? 0 : suf[x] - x, x++;
		if(g[i] + cur < f[m]) f[m] = g[i] + cur, p = i;
	}
	if(l < m) solve(pl, p, l, m - 1);
	if(m < r) solve(p, pr, m + 1, r);
}
int main() {
	cin >> n >> k, memset(g, 0x3f, sizeof(g)), g[0] = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) pre[i] = buc[a[i]], buc[a[i]] = i;
	memset(buc, 0x3f, sizeof(buc));
	for(int i = n; i; i--) suf[i] = buc[a[i]], buc[a[i]] = i;
	for(int i = 1; i <= k; i++) x = 1, y = 0, cur = 0, solve(0, n - 1, 1, n), swap(f, g);
	cout << g[n] << endl;
	return 0;
}

// stupid mistake: x -> a[x]