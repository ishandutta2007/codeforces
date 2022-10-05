#include<bits/stdc++.h>
using namespace std;
const int N=3009,M=1029,P=998244353;
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
void upd(int&x,int y){if(x+=y,x>=P)x-=P;}
int n,c,a[N];
namespace sub{
int f[N][M];
void work(){
	int i,j,k,l,o=(1<<c)-1;
	for(i=f[0][0]=1;i<=n;++i)
	for(l=1<<a[i]-1,j=n/c;~j;upd(f[j+1][0],f[j][o]),f[j][o]=0,--j)
	for(k=o-1;~k;--k)upd(f[j][k|l],f[j][k]);
	for(j=0;j<=n;printf("%d ",l),++j)for(k=0,l=j?0:P-1;k<o;++k)upd(l,f[j][k]);
}
}
int p[N],ip[N],ans[N],v[N][N],f[309][N],o[N],sum[N];
int main(){
	int*u,i,j,k,l;
	long long w;
	for(scanf("%d%d",&n,&c),i=1;i<=n;++i)scanf("%d",a+i);
	if(c<11)sub::work(),exit(0);
	for(i=f[0][0]=1;i<=n;++i)p[i]=(p[i-1]*2ll+1)%P,ip[i]=qp(p[i],P-2);
	for(i=1;i<=n;++i){
		for(memset(o,0,sizeof o),k=i,j=c;j&&k<=n;++k)if((++o[a[k]])==1)--j;
		if(j)break;
		for(j=l=1;j<=c;++j)l=l*1ll*p[o[j]]%P;
		for(v[i][k-1]=l,j=k;j<=n;++j)l=l*1ll*ip[o[a[j]]]%P*p[o[a[j]]+1]%P,v[i][j]=l*1ll*ip[++o[a[j]]]%P;
	}
	for(i=1;i<=n;++i)for(j=i;j<=n;++j)sum[i]=(sum[i]+v[i][j]*(p[n-j]+1ll))%P;
	for(i=1;i<=n;++i)for(j=1;;++j){
		for(w=k=0,u=f[j-1];k<i;++k)if(w+=u[k]*1ll*v[k+1][i],!(k&7))w%=P;
		if(f[j][i]=w%P,!w)break;
		ans[j]=(ans[j]+w*(p[n-i]+1ll-sum[i+1]))%P;
	}
	for(i=1,j=p[n];i<=n;++i)j=(j-ans[i])%P;
	for(printf("%d ",(j+P)%P),i=1;i<=n;++i)printf("%d ",(ans[i]+P)%P);
	return 0;
}