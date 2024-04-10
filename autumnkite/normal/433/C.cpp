#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
using std :: vector;
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
int n, m, a[N];
long long ans, sum, s1[N], s2[N];
vector<int> v[N];
int abs(int a){
	return a > 0 ? a : -a;
}
int main(){
	m = read(), n = read();
	for (register int i = 1; i <= n; ++i)
		a[i] = read(), i > 1 ? sum += abs(a[i] - a[i - 1]) : 0;
	for (register int i = 1; i <= n; ++i){
		if (a[i - 1] != a[i] && i > 1)
			v[a[i]].push_back(a[i - 1]), s1[a[i]] += abs(a[i] - a[i - 1]);
		if (a[i + 1] != a[i] && i < n)
			v[a[i]].push_back(a[i + 1]), s1[a[i]] += abs(a[i] - a[i + 1]);
	}
	for (register int i = 0; i <= m; ++i)
		if (v[i].size()){
			std :: sort(v[i].begin(), v[i].end());
			int mid = v[i][(v[i].size() - 1) >> 1];
			for (register int j = 0; j < v[i].size(); ++j)
				s2[i] += abs(mid - v[i][j]);
		}
	ans = sum;
	for (register int i = 0; i <= m; ++i)
		ans = std :: min(ans, sum - s1[i] + s2[i]);
	printf("%lld", ans);
}