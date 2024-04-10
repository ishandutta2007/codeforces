# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
const double INF = 2e9;
struct Node{
	double l, r;
	Node(double l = 0, double r = 0): l(l), r(r){}
} l[MAXN];
int n, q;
int sy, a, b;
ll s[MAXN];
bool cmpl(Node u, Node v){
	return u.l < v.l;
}
bool cmpr(Node u, Node v){
	return u.r < v.r;
}
int main(){
	scanf("%d%d%d", &sy, &a, &b);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		l[i] = Node(u, v);
		s[i] = s[i - 1] + (v - u);
	}
	l[n + 1] = Node(INF, INF);
	scanf("%d", &q);
	while (q--){
		int u, v;
		scanf("%d%d", &u, &v);
		double lx = (1.0 * v * a - 1.0 * sy * u) / (v - sy);
		double rx = (1.0 * v * b - 1.0 * sy * u) / (v - sy);
		int lp = lower_bound(l + 1, l + n + 1, Node(lx, lx), cmpl) - l - 1;
		int rp = upper_bound(l + 1, l + n + 1, Node(rx, rx), cmpr) - l;
		double ans = (lp == rp) ? (rx - lx) : (max(0.0, l[lp].r - lx) + max(0.0, rx - l[rp].l) + s[rp - 1] - s[lp]);
		ans = ans * (v - sy) / v;
		printf("%.10f\n", ans);
	}
	return 0;
}