#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=209,iv=P+1>>1;
int f[N][N],ans[N][N],d[N],sz[N],fa[N];
basic_string<int>g[N];
void dfs(int x,int y){
	sz[x]=1,fa[x]=y;
	for(int i:g[x])if(i!=y)d[i]=d[x]+1,dfs(i,x),sz[x]+=sz[i];
}
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int main(){
	int n,i,j,k,u,w=0,o;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		memset(f,0,sizeof f);
		for(j=1;j<i;++j)f[0][j]=1,f[j][i+1]=0;
		for(j=1;j<i;++j)for(k=i-1;k>=j;--k)f[j][k]=(f[j-1][k]+f[j][k+1])*1ll*iv%P;
		for(j=1;j<i;++j)ans[i][j]=f[j][j];
		ans[i][0]=1;
	}
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),g[j]+=k,g[k]+=j;
	for(i=1;i<=n;++i){
		d[i]=0,dfs(i,0);
		for(j=1;j<i;++j){
			u=d[j],k=j,o=sz[j];
			while(1){
				k=fa[k];
				w=(w+(sz[k]-o)*1ll*ans[u][d[k]])%P;
				o=sz[k];
				if(k==i)break;
			}
		}
	}
	printf("%lld",w*1ll*qp(n,P-2)%P);
	return 0;
}