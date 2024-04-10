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
int l, r;
bool check(int x){
	bool a[10];
	memset(a, 0, sizeof a);
	for (; x; x /= 10) if (a[x % 10]) return 0; else a[x % 10] = 1;
	return 1;
}
int main(){
	l = read(), r = read();
	for (register int i = l; i <= r; ++i) if (check(i)) return printf("%d\n", i), 0;
	printf("-1\n");
}