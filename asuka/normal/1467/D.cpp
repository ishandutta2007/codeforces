#include<bits/stdc++.h>
#define int long long
#define N 5005
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
const int mod = 1e9+7;
int n,k,q,dp[N][N],a[N],c[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&q);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,1,n) dp[i][0] = 1;
	rep(j,1,k) rep(i,1,n) dp[i][j] = (dp[i-1][j-1]+dp[i+1][j-1])%mod;
	rep(i,1,n){
		rep(j,0,k) (c[i] += dp[i][j]*dp[i][k-j]) %= mod;
	}
	// rep(i,1,n) printf("%d ",c[i]); printf("\n");
	int ans = 0;
	rep(i,1,n) (ans += a[i]*c[i]) %= mod;
	while(q--){
		int p,v; scanf("%lld%lld",&p,&v);
		int d = (mod+v-a[p])%mod;
		(ans += d*c[p]) %= mod; a[p] = v;
		printf("%lld\n",ans);
	}
	return 0;
}