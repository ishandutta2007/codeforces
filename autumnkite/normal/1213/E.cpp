#include <cstdio>
#include <cstring>
#include <algorithm>
int n;
char s[5], t[5], c[5];
bool check(char a, char b){
	if (a == s[0] && b == s[1]) return 0;
	if (a == t[0] && b == t[1]) return 0;
	return 1;
}
int main(){
	scanf("%d%s%s", &n, s, t);
	c[0] = 'a', c[1] = 'b', c[2] = 'c';
	while (1){
		if (check(c[0], c[1]) && check(c[1], c[2])){
			if (n == 1) return printf("YES\n%s", c), 0;
			if (check(c[2], c[0])){
				puts("YES");
				for (register int i = 1; i <= n; ++i) printf("%s", c);
				return 0;
			}
			if (check(c[0], c[0]) && check(c[1], c[1]) && check(c[2], c[2])){
				puts("YES");
				for (register int i = 1; i <= n; ++i) putchar(c[0]);
				for (register int i = 1; i <= n; ++i) putchar(c[1]);
				for (register int i = 1; i <= n; ++i) putchar(c[2]);
				return 0;
			}
		}
		if (!std :: next_permutation(c, c + 3)) break;
	}
	puts("NO");
}