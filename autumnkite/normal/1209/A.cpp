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
int n, a[N], b[N];
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	int s = 0, ans = 0;
	while (s < n){
		int mn = 1e9;
		for (register int i = 1; i <= n; ++i)
			if (!b[i]) mn = std :: min(mn, a[i]);
		for (register int i = 1; i <= n; ++i)
			if (!b[i] && a[i] % mn == 0) b[i] = 1, ++s;
		++ans;
	}
	printf("%d\n", ans);
}