#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
long long read(){
	register long long x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, a[N];
long long s[N];
struct Fenwick_Tree{
	long long c[N];
	void add(int x, int y){
		for (; x <= n; x += x & -x) c[x] += y;
	}
	long long query(int x){
		long long s = 0;
		for (; x; x -= x & -x) s += c[x];
		return s;
	}
	int find(long long s){
		int x = 0;
		for (register int i = 18; ~i; --i)
			if (x + (1 << i) <= n && s - c[x + (1 << i)] >= 0)
				x += 1 << i, s -= c[x];
		return x;
	}
}T;
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) s[i] = read(), T.add(i, i);
	for (register int i = n; i; --i) a[i] = T.find(s[i]) + 1, T.add(a[i], -a[i]);
	for (register int i = 1; i <= n; ++i) printf("%d ", a[i]);
}