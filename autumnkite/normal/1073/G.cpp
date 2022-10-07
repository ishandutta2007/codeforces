#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <map>
int read(){
	register int x = 0, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) ;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return x;
}
#define N 200005
int n, q, a[N], sa[N], rk[N], ht[N], cnt[N], tx[N], ty[N];
void Radix_Sort(int *x, int *y, int *sa, int n, int m){
	for (register int i = 0; i < m; ++i) cnt[i] = 0;
	for (register int i = 0; i < n; ++i) ++cnt[x[i]];
	for (register int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
	for (register int i = n - 1; ~i; --i) sa[--cnt[x[y[i]]]] = y[i];
}
bool cmp(int *a, int x, int y, int l){
	return a[x] == a[y] && a[x + l] == a[y + l];
}
void build_SA(int *a, int *sa, int n, int m){
	a[n++] = 0;
	int *x = tx, *y = ty;
	for (register int i = 0; i < n; ++i) x[i] = a[i], y[i] = i;
	Radix_Sort(x, y, sa, n, m);
	for (register int j = 1, p = 0; p < n; j <<= 1, m = p){
		p = 0;
		for (register int i = n - j; i < n; ++i) y[p++] = i;
		for (register int i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		Radix_Sort(x, y, sa, n, m);
		std :: swap(x, y), p = 1, x[sa[0]] = 0;
		for (register int i = 1; i < n; ++i) 
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
	}
	--n;
	for (register int i = 0; i < n; ++i) sa[i] = sa[i + 1];
}
void get_height(int *a, int *sa, int *rk, int *ht, int n){
	for (register int i = 0; i < n; ++i) rk[sa[i]] = i;
	for (register int i = 0, k = 0, j; i < n; ht[rk[i]] = k, ++i)
		if (rk[i]) for (k ? --k : 0, j = sa[rk[i] - 1]; a[i + k] == a[j + k]; ++k);
	ht[0] = 0;
}
int lg[N], st[N][20];
void build_ST(){
	lg[1] = 0;
	for (register int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
	for (register int i = 0; i < n; ++i) st[i][0] = ht[i];
	for (register int j = 1; j <= lg[n]; ++j)
		for (register int i = 0; (i + (1 << j) - 1) < n; ++i)
			st[i][j] = std :: min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int query(int x, int y){ // (x, y] or (y, x]
	if (x == y) return n - sa[x];
	if (x > y) std :: swap(x, y);
	int t = lg[y - x];
	return std :: min(st[x + 1][t], st[y - (1 << t) + 1][t]);
}
struct node{
	int x, k;
	bool operator < (const node &res) const {
		return x < res.x || x == res.x && k < res.k;
	}
}p[N << 1];
int main(){
//	freopen("data.txt", "r", stdin);
	n = read(), q = read();
	for (register int i = 0; i < n; a[i] = a[i] - 96, ++i) while (!islower(a[i] = getchar())) ;
	build_SA(a, sa, n, 27), get_height(a, sa, rk, ht, n), build_ST();
//	for (register int i = 0; i < n; ++i) printf("%d ", sa[i]); putchar('\n');
//	for (register int i = 0; i < n; ++i) printf("%d ", rk[i]); putchar('\n');
//	for (register int i = 0; i < n; ++i) printf("%d ", ht[i]); putchar('\n');
	while (q--){
		int r = read(), c = read(), t = 0;
		for (register int i = 1; i <= r; ++i) p[++t] = (node){rk[read() - 1], 0};
		for (register int i = 1; i <= c; ++i) p[++t] = (node){rk[read() - 1], 1};
		std :: sort(p + 1, p + 1 + t);
		long long ans = 0;
		for (register int k = 0; k < 2; ++k){
			long long sum = 0;
			std :: map<int, int> M;
			for (register int i = 1; i <= t; ++i){
				if (p[i].k) ans += sum;
				else ++M[n - sa[p[i].x]], sum += n - sa[p[i].x];
				if (i < t){
					int len = query(p[i].x, p[i + 1].x);
					while (!M.empty()){
						std :: map<int, int> :: iterator it = --M.end();
						if (it -> first <= len) break;
						sum -= 1ll * it -> first * it -> second;
						M[len] += it -> second, sum += 1ll * len * it -> second;
						M.erase(it);
					}
				}
			}
			if (!k) std :: reverse(p + 1, p + 1 + t);
		}
		printf("%lld\n", ans);
	}
}