#include <cstdio>
#include <cctype>
#include <algorithm>
long long read(){
	register long long x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1000005
int n, q;
long long a[N];
struct Heap{
	long long h[N];
	int sz;
	void clear(){ sz = 0; }
	bool empty(){ return !sz; }
	void push(long long a){ h[++sz] = a, std :: push_heap(h + 1, h + 1 + sz); }
	long long pop(){ return std :: pop_heap(h + 1, h + 1 + sz), h[sz--]; }
	long long top(){ return h[1]; }
}H;
int main(){
	n = read(), q = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = n; i; --i){
		while (!H.empty() && a[i] > 0) a[i] += H.pop();
		if (a[i] < 0) H.push(a[i]);
	}
	int cnt = 0;
	while (!H.empty()) a[++cnt] = -H.pop();
	for (register int i = 1; i <= cnt; ++i) a[i] += a[i - 1];
	while (q--){
		long long x = read();
		int p = std :: upper_bound(a + 1, a + 1 + cnt, x) - a - 1;
		printf("%d\n", cnt - p);
	}
}