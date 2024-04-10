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
#define N 55
int n, m, a[N][N];
std :: vector< std :: pair<int, int> > p;
bool check(int i, int j){
	if (i < 1 || j < 1 || i >= n || j >= m) return 0;
	return a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1];
}
int main(){
	n = read(), m = read();
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			a[i][j] = read();
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			if (a[i][j]){
				if (check(i - 1, j - 1)){ p.emplace_back(std :: make_pair(i - 1, j - 1)); continue; }
				if (check(i - 1, j)){ p.emplace_back(std :: make_pair(i - 1, j)); continue; }
				if (check(i, j - 1)){ p.emplace_back(std :: make_pair(i, j - 1)); continue; }
				if (check(i, j)){ p.emplace_back(std :: make_pair(i, j)); continue; }
				return printf("-1\n"), 0;
			}
	std :: sort(p.begin(), p.end());
	p.erase(std :: unique(p.begin(), p.end()), p.end());
	printf("%d\n", (int)p.size());
	for (auto v : p) printf("%d %d\n", v.first, v.second);
}