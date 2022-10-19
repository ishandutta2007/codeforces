#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,z,q[200039],head,tail,ans,tot,pus,now,last;
long long dp[2][200039],sum[200039],t[200039],y;
inline double cj(int x,int y,int z){return (1.0*sum[y]+dp[x][y]-sum[z]-dp[x][z])/(y-z);}
int main(){
//	freopen("1.in","r",stdin);
	register int  i,j;
	scanf("%d%d%d",&n,&m,&k);
	if(k>=m) {printf("0\n");return 0;}
	for(i=2;i<=n;i++) scanf("%lld",&sum[i]),sum[i]+=sum[i-1];
	for(i=1;i<=m;i++){
		scanf("%d%lld",&x,&y);
		t[i]=y-sum[x];
	}
	sort(t+1,t+m+1);
	for(i=1;i<=m;i++) sum[i]=sum[i-1]+t[i];
	//for(i=1;i<=n;i++) dp[0][i]=1e15;
	for(i=1;i<=m;i++) dp[1][i]=t[i]*i-sum[i];
	for(i=2;i<=k;i++){
		now=i&1;last=now^1;
		head=tail=1;q[head]=0;
		for(j=1;j<=m;j++){
			while(head<tail&&cj(last,q[head],q[head+1])<=t[j]) head++;
			dp[now][j]=dp[last][q[head]]+t[j]*(j-q[head])-(sum[j]-sum[q[head]]);
		//	printf("%lld ",dp[now][j]);
			while(head<tail&&cj(last,j,q[tail-1])<cj(last,q[tail-1],q[tail]))tail--;
			q[++tail]=j;
		}
	//	printf("\n");
	}
	printf("%lld\n",dp[k&1][m]);
}