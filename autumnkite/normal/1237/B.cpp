#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
int n, a[N], b[N], ans, vis[N];
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = 1; i <= n; ++i) b[i] = read();
	for (register int i = 1, j = 1; i <= n; ++i)
		if (!vis[a[i]]){
			while (j <= n && a[i] != b[j]) vis[b[j]] = 1, ++j, ++ans;
			++j;
		}
	printf("%d\n", ans);
}