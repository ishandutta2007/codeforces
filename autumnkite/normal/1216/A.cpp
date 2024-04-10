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
int n, s[2], ans;
char a[200005];
int main(){
	scanf("%d%s", &n, a + 1);
	for (register int i = 1; i <= n; ++i){
		++s[a[i] - 'a'];
		if (!(i & 1) && s[0] != s[1])
			if (a[i] == 'a') a[i] = 'b', --s[0], ++s[1], ++ans;
			else a[i] = 'a', --s[1], ++s[0], ++ans;
	}
	printf("%d\n", ans);
	printf("%s", a + 1);
}