#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
#define INF 0x3f3f3f3f3f3f3f3fll
int n, m, k, q, b[N], l[N], r[N];
std :: vector<int> p[N];
long long dp[N][4];
int abs(int x){
	return x >= 0 ? x : -x;
}
void update(long long &x, long long y){
	x = std :: min(x, y);
}
int main(){
	n = read(), m = read(), k = read(), q = read();
	for (register int i = 1; i <= n; ++i) l[i] = m + 1, r[i] = 0;
	l[1] = r[1] = 1, n = 0;
	for (register int i = 1; i <= k; ++i){
		int x = read(), y = read();
		n = std :: max(n, x), l[x] = std :: min(l[x], y), r[x] = std :: max(r[x], y);
	}
	for (register int i = 1; i <= q; ++i) b[i] = read();
	std :: sort(b + 1, b + 1 + q);
	p[0].push_back(1);
	for (register int i = 1; i <= n; ++i)
		if (!r[i]) p[i] = p[i - 1];
		else{
			int x = std :: upper_bound(b + 1, b + 1 + q, l[i]) - b - 1;
			if (x) p[i].push_back(b[x]);
			x = std :: lower_bound(b + 1, b + 1 + q, l[i]) - b;
			if (x <= q) p[i].push_back(b[x]);
			x = std :: upper_bound(b + 1, b + 1 + q, r[i]) - b - 1;
			if (x) p[i].push_back(b[x]);
			x = std :: lower_bound(b + 1, b + 1 + q, r[i]) - b;
			if (x <= q) p[i].push_back(b[x]);
			std :: sort(p[i].begin(), p[i].end());
			p[i].erase(std :: unique(p[i].begin(), p[i].end()), p[i].end());
		}
	p[n].clear(), p[n].push_back(l[n]);
	if (r[n] != l[n]) p[n].push_back(r[n]);
	dp[0][0] = 0;
	for (register int i = 1; i <= n; ++i)
		for (register int j = 0; j < p[i].size(); ++j){
			dp[i][j] = INF;
			for (register int k = 0; k < p[i - 1].size(); ++k){
				if (!r[i]){ update(dp[i][j], dp[i - 1][k] + 1 + abs(p[i][j] - p[i - 1][k])); continue; }
				if (p[i - 1][k] < l[i]) update(dp[i][j], dp[i - 1][k] + 1 + r[i] - p[i - 1][k] + abs(p[i][j] - r[i]));
				if (p[i - 1][k] > r[i]) update(dp[i][j], dp[i - 1][k] + 1 + p[i - 1][k] - l[i] + abs(p[i][j] - l[i]));
				if (l[i] <= p[i - 1][k] && p[i - 1][k] <= r[i])
					update(dp[i][j], dp[i - 1][k] + 1 + r[i] - p[i - 1][k] + r[i] - l[i] + abs(p[i][j] - l[i])),
					update(dp[i][j], dp[i - 1][k] + 1 + p[i - 1][k] - l[i] + r[i] - l[i] + abs(p[i][j] - r[i]));
			}
		}
	long long ans = INF;
	for (register int i = 0; i < p[n].size(); ++i) ans = std :: min(ans, dp[n][i]);
	printf("%lld\n", ans - 1);
}