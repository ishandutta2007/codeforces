#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 300005
int n, s, sl;
char a[N];
int main(){
	scanf("%d%s", &n, a);
	if (a[0] == ')' || a[n - 1] == '(') return printf(":("), 0;
	a[0] = '(', a[n - 1] = ')', n -= 2;
	if (n & 1) return printf(":("), 0;
	for (register int i = 1; i <= n; ++i) sl += a[i] == '(';
	for (register int i = 1; i <= n; ++i)
		if (sl < (n >> 1) && a[i] == '?') ++sl, a[i] = '(';
	if (sl < (n >> 1)) return printf(":("), 0;
	for (register int i = 1; i <= n; ++i) if (a[i] == '?') a[i] = ')';
	s = 0;
	for (register int i = 1; i <= n; ++i){
		if (s < 0) return printf(":("), 0;
		if (a[i] == '(') ++s;
		if (a[i] == ')') --s;
	}
	if (s) return printf(":("), 0;
	return printf("%s", a), 0;
}