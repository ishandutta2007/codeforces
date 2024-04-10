#include <bits/stdc++.h>
const int N = 505;
int n, k, a[N], b[N], l[N], tot, ans = 0;
// int tmp[N], _ans = 0;
void qry() {
	printf("? ");
	for (int i = 1; i <= k; i++)
		printf("%d ", a[i]);
	puts(""); fflush(stdout);
	int x; scanf("%d", &x); ans ^= x;
	/*
	int x = 0;
	for (int i = 1; i <= k; i++) x ^= tmp[a[i]];
	ans ^= x;
	*/
}
int main() {
	scanf("%d%d", &n, &k);
/*
	srand(time(0));
	for (int i = 1; i <= n; i++) tmp[i] = rand() % (int)(1e9 + 1), _ans ^= tmp[i];
*/
	int cnt;
	for (cnt = 1; cnt <= 500; cnt++) {
		int delta = k * cnt - n;
		if (delta < 0 || (delta & 1)) continue;
		int t = (delta / 2 + n - 1) / n;
		if (t * 2 + 1 > cnt) continue;
		// build b
		delta += n;
		// printf("%d %d\n", cnt, (t - 1) * 2 + 1);
		for (int i = 1; i <= n; i++) {
			if (((t - 1) * 2 + 1) * (n - i + 1) != delta) b[i] = t * 2 + 1;
			else b[i] = (t - 1) * 2 + 1;
			delta -= b[i];
		}
		break;
	}
	// for (int i = 1; i <= n; i++) printf("%d ", b[i]);
	if (cnt > 500) { puts("-1"); fflush(stdout); return 0; }
	for (int i = 1; i <= cnt; i++) {
		tot = 0;
		for (int j = 1; j <= n; j++)
			if (b[j]) l[++tot] = j;
		std::sort(l + 1, l + tot + 1, [&](int x, int y) { return b[x] > b[y]; });
		for (int j = 1; j <= k; j++)
			a[j] = l[j], b[l[j]]--;
		qry();
	}
	printf("! %d\n", ans); fflush(stdout);
	// printf("[%d]\n", _ans);
	return 0;
}