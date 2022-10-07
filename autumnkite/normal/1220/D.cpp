#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
long long read(){
	register long long x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n;
std :: vector<long long> val[60];
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i){
		long long x = read();
		int k = 0;
		while ((x & 1) == 0) x >>= 1, ++k;
		val[k].push_back(x);
	}
	int mx = -1;
	for (register int i = 0; i < 60; ++i)
		if (mx == -1 || val[i].size() > val[mx].size()) mx = i;
	printf("%d\n", n - val[mx].size());
	for (register int i = 0; i < 60; ++i)
		if (i != mx) for (long long v : val[i]) printf("%lld ", v << i);
}