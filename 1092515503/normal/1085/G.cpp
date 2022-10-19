#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[2010][2010],f[2010][2010],res,D[2010];
struct BIT{
int bit[2010];
void ADD(int x,int y){while(x<=n)bit[x]+=y,x+=x&-x;}
int SUM(int x){int ret=0;while(x)ret+=bit[x],x-=x&-x;return ret;}
void CLR(){memset(bit,0,sizeof(bit));}
}t0,t1;
bool loc[2010],noc[2010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	f[0][0]=1;for(int i=1;i<=n;i++)f[i][0]=1ll*f[i-1][0]*i%mod;
	for(int i=1;i<=n;i++)f[i][1]=1ll*(i-1)*f[i-1][0]%mod;
	for(int i=2;i<=n;i++)for(int j=2;j<=i;j++)
		f[i][j]=(1ll*(j-1)*f[i-1][j-2]+1ll*(i-j)*f[i-1][j-1])%mod;
	D[0]=1;for(int i=1;i<=n;i++)D[i]=1ll*D[i-1]*f[n][n]%mod;
	for(int i=1;i<=n;i++)
		t0.ADD(a[1][i],1),res=(1ll*(a[1][i]-t0.SUM(a[1][i]))*f[n-i][0]%mod*D[n-1]+res)%mod;
//	printf("%d\n",res);
	t0.CLR();
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++)loc[j]=noc[j]=true,t1.ADD(j,1);
		int cnt=n;
		for(int j=1;j<=n;j++){
			if(noc[a[i-1][j]])cnt--,t1.ADD(a[i-1][j],-1);loc[a[i-1][j]]=false;
			t0.ADD(a[i][j],1);
			int num=a[i][j]-t0.SUM(a[i][j])-(noc[a[i-1][j]]&&a[i-1][j]<a[i][j]);
			int mun=t1.SUM(a[i][j]-1);
			res=((1ll*(num-mun)*f[n-j][cnt]+(cnt?1ll*mun*f[n-j][cnt-1]:0))%mod*D[n-i]+res)%mod;
//			printf("(%d,%d)%d\n",i,j,res);
			if(loc[a[i][j]])cnt--,t1.ADD(a[i][j],-1);noc[a[i][j]]=false;
		}
		t0.CLR(),t1.CLR();
	}
	printf("%d\n",res);
	return 0;
}