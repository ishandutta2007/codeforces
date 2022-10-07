#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <set>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n, k, h, t, Q[200005];
std :: set<int> S;
int main(){
	n = read(), k = read(), h = 1, t = 0;
	for (register int i = 1; i <= n; ++i){
		int x = read();
		if (S.count(x)) continue;
		Q[++t] = x, S.insert(x);
		if (t - h + 1 > k) S.erase(Q[h]), ++h;
	}
	printf("%d\n", t - h + 1);
	for (register int i = t; i >= h; --i) printf("%d ", Q[i]);
}