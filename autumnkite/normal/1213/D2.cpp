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
#define N 200005
int n, k, m, ans;
std :: vector<int> a[N];
int main(){
	n = read(), k = read(), ans = 1e9;
	for (register int i = 1, x; i <= n; ++i){
		x = read(), m = std :: max(m, x);
		int cnt = 0;
		while (x) a[x].push_back(cnt), x >>= 1, ++cnt;
	}
	for (register int i = 1; i <= m; ++i)
		if (a[i].size() >= k){
			std :: sort(a[i].begin(), a[i].end());
			int sum = 0;
			for (register int j = 0; j < k; ++j) sum += a[i][j];
			ans = std :: min(ans, sum);
		}
	printf("%d\n", ans);
}