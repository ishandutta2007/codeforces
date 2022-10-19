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
const int N = 5015;
int n, k, p[N], pos[N], f[N][N], dp[N][1 << 8];

void cmin(int &x, int y) {
	(x > y) && (x = y);
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &p[i]), pos[p[i]] = i;

	rep(i, 1, n) {
		rep(j, 1, i - 1) f[i][p[j]]++;
		per(j, 1, n) f[i][j] += f[i][j + 1];
	}

	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;

	rep(i, 0, n - 1) rep(j, 0, (1 << k) - 1) {
		if (dp[i][j] == inf) continue;
		int mx = i + __builtin_popcount(j), mn = mx + 1;

		rep(x, 0, k - 1) if (j >> x & 1) {
			int u = mx - x - 1, v = pos[u], c = f[v][mx + 1];
			mn = u;
			rep(y, 0, k - 1) if (j >> y & 1)
				c += pos[mx - y - 1] < v;
			cmin(dp[i + 1][j ^ (1 << x)], dp[i][j] + c);
		}

		int nj = j;

		rep(x, mx + 1, mx + k + 1) {
			if (x > n || x > mn + k) break;
			int v = pos[x], c = f[v][mx + 1];
			nj <<= 1;
			if (x > mx + 1) nj |= 1;
			rep(y, 0, k - 1) if (j >> y & 1)
				c += pos[mx - y - 1] < v;
			cmin(dp[i + 1][nj], dp[i][j] + c);
		}
	}

	printf("%d\n", dp[n][0]);
	return 0;
}