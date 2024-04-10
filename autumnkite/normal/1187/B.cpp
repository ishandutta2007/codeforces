#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 200005
int n, m, k;
char s[N], t[N];
int a[N][26], b[26];
bool check(int x){
	for (register int i = 0; i < 26; ++i)
		if (b[i] > a[x][i]) return 0;
	return 1;
}
int main(){
	scanf("%d%s", &n, s + 1);
	for (register int i = 1; i <= n; ++i){
		for (register int j = 0; j < 26; ++j) a[i][j] = a[i - 1][j];
		++a[i][s[i] - 'a'];
	}
	scanf("%d", &m);
	while (m--){
		scanf("%s", t + 1), k = strlen(t + 1);
		for (register int i = 0; i < 26; ++i) b[i] = 0;
		for (register int i = 1; i <= k; ++i) ++b[t[i] - 'a'];
		int l = 1, r = n, md, ans = 0;
		while (l <= r) if (check(md = (l + r) >> 1)) ans = md, r = md - 1; else l = md + 1;
		printf("%d\n", ans);
		for (register int i = 1; i <= k; ++i) t[i] = 0;
	}
}