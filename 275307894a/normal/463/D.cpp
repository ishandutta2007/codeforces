#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,p[9][1039],dp[1039],b[1034][9],flag,ans;
int main(){
	register int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<m;i++){
		for(j=1;j<=n;j++)scanf("%d",&x),p[i][x]=j;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		for(j=1;j<m;j++) b[i][j]=p[j][x];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<i;j++){
			flag=0;
			for(k=1;k<m;k++) if(b[j][k]>b[i][k]){flag=1;break;}
			if(!flag)dp[i]=max(dp[i],dp[j]);
		}
		dp[i]++;
		//printf("%d\n",dp[i]);
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}