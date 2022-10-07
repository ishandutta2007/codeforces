#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <map>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, k, a[N];
std :: map<int, int> M;
int main(){
	n = read(), k = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	std :: sort(a + 1, a + 1 + n);
	for (register int i = (1 + n) >> 1; i <= n; ++i) ++M[a[i]];
	while (1){
		auto it = M.begin(), nx = it;
		++nx;
		if (nx == M.end() || k < 1ll * (nx -> first - it -> first) * it -> second) break;
		else k -= (nx -> first - it -> first) * it -> second, nx -> second += it -> second, M.erase(it);
	}
	int ans = M.begin() -> first + k / M.begin() -> second;
	printf("%d\n", ans);
}