#include<bits/stdc++.h>
#define ll long long
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
using namespace std;
void cmin(int &x, int y) {if(x > y) x = y;}
namespace Poly {
	const int L = 100015;
	const double PI = acos(-1.0);
	struct cp {
		double x, y;
		cp operator + (const cp &rhs) const {return (cp) {x + rhs.x, y + rhs.y};}
		cp operator - (const cp &rhs) const {return (cp) {x - rhs.x, y - rhs.y};}
		cp operator * (const cp &rhs) const {return (cp) {x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x};}
		cp operator / (const double &o) const {return (cp) {x / o, y / o};}
		cp operator * (const double &o) const {return (cp) {x * o, y * o};}
	} A[L], B[L], C[L];
	int rev[L], lim;
	void init(int n, int m) {
		lim = 1; 
		int w = 0;
		while (lim <= n + m - 2) lim <<= 1, w++;
		rev[0] = 0;
		rep(i, 1, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (w - 1));
		rep(i, 0, lim - 1) A[i] = B[i] = (cp) {0.0, 0.0};
	}
	void FFT(cp a[], int flag) {
		rep(i, 0, lim - 1) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int i = 1; i < lim; i <<= 1) {
			cp wn = (cp) {cos(PI / i), flag * sin(PI / i)};
			for (int j = 0; j < lim; j += (i << 1)) {
				cp w = (cp) {1.0, 0.0};
				for (int k = 0; k < i; ++k, w = w * wn) {
					cp x = a[j + k], y = w * a[j + k + i];
					a[j + k] = x + y;
					a[j + k + i] = x - y;
				}
			}
		}
		if (flag < 0) rep(i, 0, lim - 1) a[i] = a[i] / lim;
	}
}
using namespace Poly;
const int N = 55, M = 105, T = 20015;
int n, m, t, x, dis[N][N], U[M], V[M], W[M], p[M][T];
double dp[N][T << 1], sum[M][T << 1];
void Floyd() {
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) cmin(dis[i][j], dis[i][k] + dis[k][j]);
}
void solve(int l, int r) {
	if(l > t) return;
	if(l == r) {
		rep(i, 1, m) dp[U[i]][l] = min(dp[U[i]][l], sum[i][l] + W[i]);
		return;
	}
	int mid = (l + r) >> 1;
	solve(mid + 1, r);
	/* 
		dp[*][mid + 1, r] & p[1, r - l] -> dp[*][l, mid]
		[mid + 1, r] -> [0, l1 - 1], i -> i - mid - 1
		[1, l2] -> [l2 - 1, 0], j -> l2 - j
		mid = mid + 1 - 1 -> 0 + l2 - 1 = l2 - 1
		i - j -> (i - mid - 1) + (l2 - j) = i - j + l2 - mid - 1
	*/ 
	int l1 = r - mid, l2 = min(t, r - l);
	rep(e, 1, m) {
		int v = V[e];
		init(l2, l1);
		rep(i, 1, l2) A[l2 - i].x = (double) p[e][i] / 100000.0;
		rep(i, mid + 1, r) B[i - mid - 1].x = dp[v][i];
		FFT(A, 1);
		FFT(B, 1);
		rep(i, 0, lim - 1) C[i] = A[i] * B[i];
		FFT(C, -1);
		rep(i, l, mid) if(i + l2 - mid - 1 >= 0) sum[e][i] += C[i + l2 - mid - 1].x;
	}
	solve(l, mid);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d%d", &n, &m, &t, &x);
	memset(dis, 0x3f, sizeof dis);
	rep(i, 1, n) dis[i][i] = 0;
	rep(i, 1, n) rep(j, 0, t * 2) dp[i][j] = 1e20;
	rep(i, 1, m) {
		scanf("%d%d%d", &U[i], &V[i], &W[i]);
		rep(j, 1, t) scanf("%d", &p[i][j]);
		cmin(dis[U[i]][V[i]], W[i]);
	}
	Floyd();
	rep(i, 1, n) rep(j, t + 1, t * 2) dp[i][j] = (double) (dis[i][n] + x); 
	rep(j, 0, t) dp[n][j] = 0;
	solve(0, 2 * t);
	printf("%.10lf\n", dp[1][0]);
	return 0;
}