#include<bits/stdc++.h>
#define ll long long
#define N 2015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define eps 1e-8
using namespace std;
int n, a, b;
double p[N], q[N], f[N][N];
int g[N][N];
bool cmp(double x, double y) { // x < y ?
	return x - y < -eps;
}
bool chk(double &x, double y) {
	if(cmp(x, y)) return x = y, 1;
	return 0;
}
void solve(double k) {
	rep(i, 1, n) rep(j, 0, a) f[i][j] = 0.0;
	rep(i, 1, n) rep(j, 0, a) g[i][j] = 0;
	rep(i, 1, n) {
		rep(j, 0, a) {
			f[i][j] = f[i - 1][j];
			g[i][j] = g[i - 1][j];
			if(j > 0) {
				if(chk(f[i][j] , f[i - 1][j - 1] + p[i])) {
					g[i][j] = g[i - 1][j - 1];
				}
				if(chk(f[i][j], f[i - 1][j - 1] + (1.0 - (1.0 - p[i]) * (1.0 - q[i])) + k)) {
					g[i][j] = g[i - 1][j - 1] + 1;
				}
			}
			if(chk(f[i][j], f[i - 1][j] + q[i] + k)){
				g[i][j] = g[i - 1][j] + 1;
			}
			// printf("%d %d %lf %d\n", i, j, f[i][j], g[i][j]);
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &a, &b);
	rep(i, 1, n) scanf("%lf", &p[i]);
	rep(i, 1, n) scanf("%lf", &q[i]);
	double l = -1.0 * n, r = 0.0, ans = 0.0;
	while(r - l > eps) {
		double mid = (l + r) * 0.5;
		// printf("MID: %.10lf\n", mid);
		solve(mid);
		// printf("RES: %d %lf\n", g[n][a], f[n][a]);
		if(g[n][a] <= b) ans = f[n][a] - mid * b, l = mid;
		else r = mid;
	}
	printf("%.10lf\n", ans);
	return 0;
}