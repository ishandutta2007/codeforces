#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int c[110],p[110],n,m=1,C[110][110],fac[110],g[110][110];
bool vis[110];
int sta[2010][110],f[2010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++)(g[i][1]+=1ll*C[i][j]*fac[j]%mod*fac[n-1-j]%mod)%=mod;
		for(int j=2;j<=n;j++)g[i][j]=1ll*g[i][j-1]*g[i][1]%mod;
	}
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)if(!vis[i]){
		int s=0;
		for(int j=i;!vis[j];j=p[j])s++,vis[j]=true;
		c[s]++;
	}
	for(int i=1;i<=n;i++)m*=c[i]+1;
	for(int i=0;i<m;i++)for(int j=i,k=1;k<=n;k++)sta[i][k]=j%(c[k]+1),j/=c[k]+1;
//	for(int i=0;i<m;i++,puts(""))for(int j=1;j<=n;j++)printf("%d ",sta[i][j]); 
	f[0]=1;for(int i=1;i<m;i++)for(int j=1;j<=i;j++){
		int si=0,sj=0,o=0,num=f[i-j];
		for(int k=1;k<=n;k++){
			num=1ll*num*C[sta[i][k]][sta[j][k]]%mod;
			si+=sta[i][k]*k,sj+=sta[j][k]*k,o+=sta[j][k];
		}
		if(!num)continue;
//		printf("%d->%d:%d,%d:%d\n",j,i,sj,si,g[si-sj][sj]);
		num=1ll*num*g[si-sj][sj]%mod;
		if(!(o&1))num=mod-num;
		(f[i]+=num)%=mod;
	}
	printf("%d\n",f[m-1]);
	return 0;
}