#include <cstdio>
#include <cctype>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x; 
}
std :: pair<int, int> a[105];
int n, sum, ans, k, c[105];
int main(){
	scanf("%d", &n);
	for (register int i = 0; i < n; ++i)
		sum += a[i].first = read(), a[i].second = i + 1;
	std :: sort(a + 1, a + n), c[k = 1] = 1, ans = a[0].first;
	for (register int i = 1; i < n; ++i)
		if (a[i].first <= a[0].first / 2) c[++k] = a[i].second, ans += a[i].first;
	if (ans <= sum / 2) return printf("0"), 0;
	printf("%d\n", k);
	for (register int i = 1; i <= k; ++i) printf("%d ", c[i]);
}