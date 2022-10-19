#include<bits/stdc++.h>
#define ll long long
#define N 2005
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
int T, n, k, a[N], dp[N][N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		rep(i, 1, n)
			scanf("%d", &a[i]);
		rep(i, 0, n) rep(j, 0, n) dp[i][j] = 0;
		rep(i, 1, n) rep(j, 0, i - 1) {
			dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] == (i - j)));
		}
		int ans = inf;
		rep(j, 0, n) if(dp[n][j] >= k) ans = min(ans, j);
		if(ans == inf) puts("-1");
		else printf("%d\n", ans);
	}
	return 0;
}