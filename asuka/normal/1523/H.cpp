#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 20015;
int n, q, f[15][31][N], g[15][31][N], dp[N][31], ans[N], nans[N], a[N], L[N], R[N], K[N], mx[31][15][N], Log[N];

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, q) scanf("%d%d%d", &L[i], &R[i], &K[i]), fill(dp[i], dp[i] + K[i] + 1, L[i]);
	rep(i, 1, n) rep(j, 0, 30) g[0][j][i] = f[0][j][i] = min(n, i + a[i] + j);
	rep(i, 2, n) Log[i] = Log[i >> 1] + 1;

	auto build = [&](int d[15][31][N], int j) {
		rep(x, 0, 30) {
			rep(i, 1, n) mx[x][0][i] = d[j][x][i];

			rep(k, 1, 14) {
				rep(i, 1, n) {
					if (i + (1 << k) - 1 > n) break;
					mx[x][k][i] = max(mx[x][k - 1][i], mx[x][k - 1][i + (1 << (k - 1))]);
				}
			}
		}
	};

	auto ask = [](int d[15][N], int l, int r) {
		int k = Log[r - l + 1];
		return max(d[k][l], d[k][r - (1 << k) + 1]);
	};

	rep(j, 1, 14) {
		build(f, j - 1);

		rep(x, 0, 30) rep(y, 0, x) {
			rep(i, 1, n) f[j][x][i] = max(f[j][x][i], ask(mx[x - y], i, f[j - 1][y][i]));
		}

		if (j - 1) {
			rep(x, 0, 30) rep(y, 0, x) {
				rep(i, 1, n) g[j - 1][x][i] = max(g[j - 1][x][i], ask(mx[x - y], i, g[j - 2][y][i]));
			}
		}
	}

	per(j, 0, 14) {
		if (j) build(g, j - 1);

		rep(i, 1, q) {
			nans[i] = 0;
			rep(x, 0, K[i]) nans[i] = max(nans[i], j ? ask(mx[K[i] - x], L[i], dp[i][x]) : dp[i][x]); 
		}

		build(f, j);

		rep(i, 1, q) {
			if (nans[i] < R[i]) {
				ans[i] |= 1 << j;
				per(x, 0, K[i]) {
					per(y, 0, x) {
						dp[i][x] = max(dp[i][x], ask(mx[x - y], L[i], dp[i][y]));
					}
				}
			}
		}
	}

	rep(i, 1, q) printf("%d\n", ans[i]);
	return 0;
}