#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
const int N = 150005;
const double eps = 1e-9;
int n, m, cnt;
struct node{
	int t, p;
	friend bool operator < (const node &a, const node &b){
		return 1ll * a.t * b.p < 1ll * b.t * a.p;
	}
}a[N];
std :: vector<node> b[N];
std :: pair<int, std :: pair<double, double> > d[N];
long long T;
bool check(double c){
	long long t = 0;
	cnt = 0;
	for (register int i = 1; i <= m; ++i){
		long long nt = 0;
		for (node v : b[i]) nt += v.t;
		for (node v : b[i]){
			double l = (1 - c * (t + nt) / T) * v.p, r = (1 - c * (t + v.t) / T) * v.p;
			d[++cnt] = {v.p, {l, r}};
		}
		t += nt;
	}
	std :: sort(d + 1, d + 1 + n);
	double mx = 0;
	for (register int i = 1, j = 1; i <= n; i = j){
		while (j <= n && d[j].first == d[i].first) ++j;
		for (register int k = i; k < j; ++k)
			if (d[k].second.first < mx) return 0;
		for (register int k = i; k < j; ++k)
			mx = std :: max(mx, d[k].second.second);
	}
	return 1;
}
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i].p = read();
	for (register int i = 1; i <= n; ++i) T += a[i].t = read();
	std :: sort(a + 1, a + 1 + n);
	for (register int i = 1; i <= n; ++i)
		if (i == 1 || a[i - 1] < a[i]) b[++m].push_back(a[i]);
		else b[m].push_back(a[i]);
	double l = 0, r = 1, md;
	while (l <= r && r - l >= eps)
		if (check(md = (l + r) / 2)) l = md; else r = md;
	printf("%.10lf\n", l);
}