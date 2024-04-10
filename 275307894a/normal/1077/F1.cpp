#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,q[10039],head,tail,a[10039];
long long dp[5039][5039],ans;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	memset(dp,-0x3f,sizeof(dp));
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=k;i++) dp[1][i]=a[i];
	for(i=2;i<=m;i++){
		head=tail=0;memset(q,0,sizeof(q));
		for(j=1;j<=n;j++){
			while(head!=tail&&q[head+1]+k<j) head++;
			dp[i][j]=dp[i-1][q[head+1]]+a[j];
			while(head!=tail&&dp[i-1][q[tail]]<dp[i-1][j]) tail--;
			q[++tail]=j;
		//	printf("%d ",dp[i][j]);
		}
	//	printf("\n");
	}
	for(i=n-k+1;i<=n;i++) ans=max(ans,dp[m][i]);
	if(!ans) printf("-1\n");
	else printf("%lld\n",ans);
}