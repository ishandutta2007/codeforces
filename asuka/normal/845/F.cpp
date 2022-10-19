#include<bits/stdc++.h>
#define ll long long
#define N 261
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
const int mod = 1e9 + 7;
int n, m, dp[2][(1 << 15)][2][2];
char o[N][N], oo[N][N];
void inc(int &x, int y) {
	x = (x + y >= mod) ? (x + y - mod) : (x + y);
}
int main(){
	// freopen("guard.in","r",stdin);
	// freopen("guard.out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", o[i] + 1);
	if(m > n) {
		rep(i, 1, n) rep(j, 1, m) oo[j][i] = o[i][j];
		swap(n, m);
		rep(i, 1, n) rep(j, 1, m) o[i][j] = oo[i][j];
	}
	int f = 0, g = 1;
	dp[f][0][0][0] = 1;
	rep(i, 1, n) rep(j, 1, m) {
		memset(dp[g], 0, sizeof dp[g]);
		rep(s, 0, (1 << m) - 1) rep(p, 0, 1) rep(q, 0, 1) {
			if(o[i][j] == 'x') {
				inc(dp[g][s & ~(1 << (j - 1))][0][q], dp[f][s][p][q]);
			} else {
				// not choose
				int qq = q + !((s >> (j - 1) & 1) || p);
				if(qq <= 1) inc(dp[g][s][p & (j != m)][qq], dp[f][s][p][q]);
				inc(dp[g][s | (1 << (j - 1))][j != m][q], dp[f][s][p][q]);
			}
		}
		// memcpy(f, g, sizeof f);
		swap(f, g);
	}
	int ans = 0;
	rep(s, 0, (1 << m) - 1) rep(p, 0, 1) rep(q, 0, 1) {
		inc(ans, dp[f][s][p][q]);
		// if(f[s][p][q]) printf("%d %d %d %d\n", s, p, q, f[s][p][q]);
	}
	printf("%d\n", ans);
	return 0;
}