#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, a[N], f[N], stk1[N], stk2[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	f[1] = 0;
	int tp1 = 0, tp2 = 0;
	stk1[++tp1] = 1;
	stk2[++tp2] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1];
		if (a[i - 1] < a[i]) {
			while (tp1 && a[stk1[tp1]] < a[i]) {
				f[i] = min(f[i], f[stk1[tp1]]);
				tp1--;
			}
			if (tp1) f[i] = min(f[i], f[stk1[tp1]]);
		} else if (a[i - 1] > a[i]) {
			while (tp2 && a[stk2[tp2]] > a[i]) {
				f[i] = min(f[i], f[stk2[tp2]]);
				tp2--;
			}
			if (tp2) f[i] = min(f[i], f[stk2[tp2]]);
		}
		while (tp1 && a[stk1[tp1]] <= a[i]) tp1--;
		stk1[++tp1] = i;
		while (tp2 && a[stk2[tp2]] >= a[i]) tp2--;
		stk2[++tp2] = i;
		f[i]++;
	}
	printf("%d\n", f[n]);
	return 0;
}