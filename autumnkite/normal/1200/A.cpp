#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
char s[N];
int n, vis[10];
int main(){
	scanf("%d", &n), scanf("%s", s + 1);
	for (register int i = 0; i <= 9; ++i) vis[i] = 0;
	for (register int i = 1; i <= n; ++i)
		if (s[i] == 'L'){ for (register int j = 0; j <= 9; ++j) if (!vis[j]){ vis[j] = 1; break; } }
		else if (s[i] == 'R'){ for (register int j = 9; j >= 0; --j) if (!vis[j]){ vis[j] = 1; break; } }
		else vis[s[i] - '0'] = 0;
	for (register int i = 0; i <= 9; ++i) printf("%d", vis[i]); putchar('\n');
}