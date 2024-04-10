#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n, m, k, c[100005];
long long p, a[100005], h[100005], l = 0, r, mid, ans;
struct node{
	int day, id;
	bool operator < (const node &b) const {
		return day > b.day;
	}
};
struct Heap{
	node h[200005];
	int sz;
	void clear(){ sz = 0; }
	bool empty(){ return !sz; }
	void push(node x){ h[++sz] = x, std :: push_heap(h + 1, h + 1 + sz); }
	node pop(){ return std :: pop_heap(h + 1, h + 1 + sz), h[sz--]; }
	node top(){ return h[1]; }
}H;
bool check(long long x){
	H.clear(), memset(c, 0, sizeof c);
	for (register int i = 1; i <= n; ++i)
		if (x - a[i] * m < h[i]) H.push((node){x / a[i], i});
	for (register int i = 1; !H.empty() && i <= m; ++i)
		for (register int j = 1; !H.empty() && j <= k; ++j){
			node u = H.pop();
			if (u.day < i) return 0;
			++c[u.id];
			if (x + c[u.id] * p - a[u.id] * m < h[u.id])
				H.push((node){(x + c[u.id] * p) / a[u.id], u.id});
		}
	return H.empty();
}
int main(){
	n = read(), m = read(), k = read(), p = read();
	for (register int i = 1; i <= n; ++i)
		h[i] = read(), a[i] = read(), r = std :: max(r, h[i] + a[i] * m);
	while (l <= r) check(mid = l + r >> 1) ? ans = mid, r = mid - 1 : l = mid + 1;
	printf("%lld", ans);
}