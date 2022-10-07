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
int n, ansi, ansid[N];
long long m, ans[N << 1], Ans;
struct node{
	long long v;
	int id;
	bool operator < (const node &rhs) const {
		return v < rhs.v;
	}
}a[N], b[N * 3];
long long abs(long long a){
	return a > 0 ? a : -a;
}
void add(int l, int r, long long v){
	ans[l] += v, ans[r] -= v;
}
int main(){
	m = read(), n = read();
	for (register int i = 0; i < n; ++i) a[i].v = read(), a[i].id = i;
	for (register int i = 0; i < n; ++i) b[i].v = read(), b[i].id = i;
	std :: sort(a, a + n), std :: sort(b, b + n);
	for (register int i = 0; i < n; ++i) a[i].v += m;
	for (register int i = 0; i < (n << 1); ++i) b[i + n] = b[i], b[i + n].v += m;
	for (register int i = 0; i < n; ++i) ans[0] += a[i].v;
	for (register int i = 0; i < n; ++i){
		int j = std :: lower_bound(b, b + 3 * n, a[i]) - b;
		if (j > i && j <= i + (n << 1)) ans[j - i] -= 2 * a[i].v;
	}
	for (register int j = 0; j < 3 * n; ++j){
		if (j < n){ add(0, j + 1, -b[j].v); continue; }
		if (j >= (n << 1)){ add(j - n + 1, (n << 1) + 1, b[j].v); continue; }
		int i = std :: upper_bound(a, a + n, b[j]) - a;
		add(j - i + 1, j + 1, b[j].v), add(j - n + 1, j - i + 1, -b[j].v);
	}
	Ans = ans[0], ansi = 0;
	for (register int i = 1; i <= (n << 1); ++i){
		ans[i] += ans[i - 1];
		if (ans[i] < Ans) Ans = ans[i], ansi = i;
	}
	for (register int i = 0; i < n; ++i)
		ansid[a[i].id] = b[(i + ansi) % n].id;
	printf("%lld\n", Ans);
	for (register int i = 0; i < n; ++i) printf("%d ", ansid[i] + 1);
}