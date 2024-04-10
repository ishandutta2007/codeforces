#include <cstdio>
#include <algorithm>
#define N 400005
int n, k, d, dis1[N], dis2[N];
char a[N], b[N];
bool check(){
	if (n & 1) return 0;
	for (register int i = 2; i <= n; ++i)
		if (a[i] == a[i - 1]) return 0;
	return 1;
}
int main(){
	scanf("%d%d%s", &n, &k, a + 1);
	if (check()){
		if (k & 1) std :: reverse(a + 1, a + 1 + n);
		return printf("%s", a + 1), 0;
	}
	for (register int i = 1; i <= n; ++i) a[n + i] = a[i];
	for (register int i = n + 2; i < (n << 1); ++i)
		if (a[i - 1] != a[i] && a[i] != a[i + 1]) continue;
		else{ d = i - 1; break; }
	if (!d) d = (n << 1) - 1;
	for (register int i = d - n + 1; i <= d; ++i)
		if (a[i - 1] != a[i] && a[i] != a[i + 1]) dis1[i] = dis1[i - 1] + 1;
		else dis1[i] = 0;
	for (register int i = d; i > d - n; --i)
		if (a[i - 1] != a[i] && a[i] != a[i + 1]) dis2[i] = dis2[i + 1] + 1;
		else dis2[i] = 0;
	for (register int i = d - n + 1; i <= d; ++i)
		if (a[i - 1] != a[i] && a[i] != a[i + 1])
			if (k >= std :: min(dis1[i], dis2[i]))
				if (dis1[i] < dis2[i]) b[i] = a[i - dis1[i]];
				else b[i] = a[i + dis2[i]];
			else b[i] = a[i] == 'B' && (k & 1) || (a[i] == 'W' && (k & 1 ^ 1)) ? 'W' : 'B';
		else b[i] = a[i];
	for (register int i = 1; i <= d - n; ++i) putchar(b[i + n]);
	for (register int i = d - n + 1; i <= n; ++i) putchar(b[i]);
}