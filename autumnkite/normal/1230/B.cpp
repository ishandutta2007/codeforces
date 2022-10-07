#include <cstdio>
#include <cstring>
int n, k;
char s[200005], ch;
int main(){
	scanf("%d%d%s", &n, &k, s + 1);
	for (register int i = 1; i <= n && k; ++i)
		k -= (ch = (i == 1 && n > 1) ^ '0') != s[i], s[i] = ch;
	printf("%s", s + 1);
}