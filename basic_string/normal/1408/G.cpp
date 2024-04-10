#include<bits/stdc++.h>
using namespace std;
const int N=1503,P=998244353;
int x[N*N],y[N*N],f[N],g[N][N],h[N],p[N],s[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void mg(int x,int y){
	memset(p,0,N*4);
	for(int i=1;i<=s[x];++i)for(int j=1;j<=s[y];++j)p[i+j]=(p[i+j]+g[x][i]*1ll*g[y][j])%P;
	memcpy(g[x],p,N*4),s[x]+=s[y],h[x]+=h[y],f[y]=x;
}
int main(){
	int n,m,i,j,k;
	scanf("%d",&n),m=n*(n-1)/2;
	for(i=1;i<=n;++i)f[i]=i,g[i][1]=s[i]=1;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(scanf("%d",&k),i<j)x[k]=i,y[k]=j;
	for(i=1;i<=m;++i){
		j=gf(x[i]);
		if(j!=gf(y[i]))mg(j,f[y[i]]);
		if(++h[j],h[j]==s[j]*(s[j]-1)/2)(++g[j][1])%=P;
	}
	for(i=1,j=gf(1);i<=n;++i)printf("%d ",g[j][i]);
	return 0;
}