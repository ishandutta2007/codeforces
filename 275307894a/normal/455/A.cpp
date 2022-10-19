#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,f[100039],maxn;
long long dp[100039],w[100039],ans;
int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&x),maxn=max(maxn,x),f[x]++;
	for(i=1;i<=maxn;i++)w[i]=(long long)i*f[i];
	dp[1]=w[1];dp[2]=w[2];
	ans=max(w[2],w[1]);
	for(i=3;i<=maxn;i++){
		dp[i]=max(dp[i-3],dp[i-2])+w[i];
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
}