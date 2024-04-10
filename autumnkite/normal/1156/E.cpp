#include <cstdio>
#include <algorithm>
#define N 200005
int n, a[N], p[N], l[N], r[N], top, sta[N], ans;
bool in(int x, int l, int r){
	return l <= p[x] && p[x] <= r;
}
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i), p[a[i]] = i;
	for (register int i = 1; i <= n; ++i){
		while (top > 0 && a[i] > a[sta[top]]) --top;
		l[i] = sta[top] + 1;
		sta[++top] = i;
	}
	sta[top = 0] = n + 1;
	for (register int i = n; i; --i){
		while (top > 0 && a[i] > a[sta[top]]) --top;
		r[i] = sta[top] - 1;
		sta[++top] = i;
	}
	for (register int i = 1; i <= n; ++i){
		int l1 = l[i], r1 = i - 1, l2 = i + 1, r2 = r[i];
		if (r1 - l1 > r2 - l2) std :: swap(l1, l2), std :: swap(r1, r2);
		for (register int j = l1; j <= r1; ++j)
			if (in(a[i] - a[j], l2, r2)) ++ans;
	}
	printf("%d\n", ans);
}