#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const double eps = 1e-8;
int n, a, b;
double p[N], q[N];
struct dat {
	double ans;
	int x;
	dat operator + (dat r) {return {ans + r.ans, x + r.x};}
	bool operator < (const dat r) const {return fabs(ans - r.ans) > eps ? ans < r.ans : x < r.x;}
} f[N][N];
int main() {
	// freopen("1.in", "r", stdin);
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) cin >> q[i];
	double l = 0, r = 1, m;
	while(l + eps < r) {
		m = (l + r) / 2;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= a; j++) {
				f[i][j] = f[i - 1][j];
				f[i][j] = max(f[i][j], f[i - 1][j] + (dat) {q[i] - m, 1});
				if(j) {
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + (dat) {p[i], 0});
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + (dat) {p[i] + q[i] - p[i] * q[i] - m, 1});
				}
			}
		if(f[n][a].x == b) break;
		f[n][a].x < b ? r = m : l = m;
	}
	printf("%.6lf\n", f[n][a].ans + b * m);
	return 0;
}

/*
2022/4/30
start thinking at ??:??

.jpg.
wqs  wqs .

start coding at 22:22
finish debugging at 22:36
*/