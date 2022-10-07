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
int T, a, b, c, t;
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &a, &b, &c);
		if (b + c - a < 0) t = 0; else t = (b + c - a) / 2 + 1;
		if (t > c) printf("0\n");
		else printf("%d\n", c - t + 1);
	}
}