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
int T, n, sum;
int main(){
	T = read();
	while (T--){
		n = read(), sum = 0;
		for (register int i = 1; i <= n; ++i) sum += read();
		printf("%d\n", (sum - 1) / n + 1);
	}
}