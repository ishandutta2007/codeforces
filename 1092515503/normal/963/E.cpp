#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int R,n,p[4],di[4]={0,-1,0,1},dj[4]={-1,0,1,0},P,d[60],q3;//L,U,R,D;
int g[110][110][110],f[110][110];
inline int&G(int i,int j,int k){return g[i+R+1][j+R+1][k+R];}
int main(){
	scanf("%d",&R),n=R<<1;
	for(int i=0;i<4;i++)scanf("%d",&p[i]),P+=p[i];
	P=ksm(P);
	for(int i=0;i<4;i++)p[i]=1ll*p[i]*P%mod;
	q3=ksm(p[3]);
	for(int i=0;i<=R;i++){
		while(i*i+d[i]*d[i]<=R*R)d[i]++;
		d[i]--;
	}
	for(int i=-R;i<=R;i++)G(i,-d[abs(i)],i)=1;
	for(int i=-R;i<=R;i++)for(int j=-R;j<=R;j++){
		if(i*i+j*j>R*R)continue;
		for(int k=-R;k<=R+1;k++){
			for(int t=0;t<3;t++)(G(j,i+1,k)+=1ll*p[t]*G(j+dj[t],i+di[t],k)%mod)%=mod;
			G(j,i+1,k)=1ll*q3*(G(j,i,k)+mod-G(j,i+1,k))%mod;
		}
		(G(j,i+1,R+1)+=mod-q3)%=mod;
//		printf("(%d,%d)->(%d,%d)\n",j,i,j,i+1);
//		for(int k=-R;k<=R+1;k++)printf("%d ",G(j,i+1,k));puts("");
	}
	for(int i=-R;i<=R;i++){
		for(int j=-R;j<=R;j++)f[i+R][j+R]=G(i,d[abs(i)]+1,j);
		f[i+R][n+1]=(mod-G(i,d[abs(i)]+1,R+1))%mod;
	}
//	for(int i=0;i<=n;i++,puts(""))for(int j=0;j<=n+1;j++)printf("%d ",f[i][j]);
	for(int i=0,j;i<=n;i++){
		for(j=i;j<=n;j++)if(f[j][i])break;
		if(i!=j)swap(f[i],f[j]);
		int inv=ksm(f[i][i]);
		for(j=i;j<=n+1;j++)f[i][j]=1ll*f[i][j]*inv%mod;
		for(j=0;j<=n;j++)if(j!=i){
			int lam=mod-f[j][i];
			for(int k=i;k<=n+1;k++)f[j][k]=(1ll*f[i][k]*lam+f[j][k])%mod;
		}
	}
	int res=G(0,0,R+1);
	for(int i=-R;i<=R;i++)res=(1ll*G(0,0,i)*f[i+R][n+1]+res)%mod;
	printf("%d\n",res);
	return 0;
}