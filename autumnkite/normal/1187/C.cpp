#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 1005
int n, m, cnt, bo[N], s[N];
struct node{
	int l, r;
}a[N];
int main(){
	scanf("%d%d", &n, &m);
	for (register int i = 1, t, l, r; i <= m; ++i){
		scanf("%d%d%d", &t, &l, &r);
		if (t) for (register int j = l + 1; j <= r; ++j) bo[j] = 1;
		else a[++cnt] = (node){l, r};
	}
	s[1] = 1;
	for (register int i = 2; i <= n; ++i) if (bo[i]) s[i] = s[i - 1] + 1; else s[i] = s[i - 1] - 1;
	int mn = 0x3f3f3f3f;
	for (register int i = 1; i <= n; ++i) mn = std :: min(mn, s[i]);
	for (register int i = 1; i <= n; ++i) s[i] = s[i] - mn + 1;
	for (register int i = 1; i <= cnt; ++i){
		bool flag = 0;
		for (register int j = a[i].l + 1; j <= a[i].r; ++j) if (s[j] < s[j - 1]){ flag = 1; break; }
		if (!flag) return printf("NO"), 0;
	}
	printf("YES\n");
	for (register int i = 1; i <= n; ++i) printf("%d ", s[i]);
}