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
#define N 105
int n, a[N], b[N], sum, ans;
char s[N];
int main(){
	n = read();
	scanf("%s", s + 1);
	for (register int i = 1; i <= n; ++i) a[i] = read(), b[i] = read(), sum += s[i] == '1';
	ans = sum;
	for (register int i = 1; i <= 1000000; ++i){
		for (register int j = 1; j <= n; ++j)
			if (i >= b[j] && (i - b[j]) % a[j] == 0) sum -= s[j] == '1', s[j] ^= 1, sum += s[j] == '1';
		ans = std :: max(ans, sum);
	}
	printf("%d\n", ans);
}