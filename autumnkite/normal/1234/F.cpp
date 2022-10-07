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
int n;
char s[1000005];
int f[1 << 20];
int main(){
	scanf("%s", s + 1), n = strlen(s + 1);
	for (register int i = 1; i <= n; ++i){
		int S = 0;
		for (register int j = i; j <= n && j < i + 20; ++j)
			if (S >> (s[j] - 'a') & 1) break; else S |= 1 << (s[j] - 'a'), f[S] = j - i + 1;
	}
	for (register int i = 0; i < 20; ++i)
		for (register int j = 0; j < (1 << 20); ++j)
			if (j >> i & 1) f[j] = std :: max(f[j], f[j ^ (1 << i)]);
	int ans = 0;
	for (register int i = 0; i < (1 << 20); ++i)
		ans = std :: max(ans, f[i] + f[((1 << 20) - 1) ^ i]);
	printf("%d\n", ans);
}