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
void solve(){
	n = read();
	if (n == 2) printf("2\n");
	else printf("%d\n", n & 1);
}
int main(){
	int T = read();
	while (T--) solve();
}