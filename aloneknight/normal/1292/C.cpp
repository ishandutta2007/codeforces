#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3005;
int n,sz[N][N],fa[N][N];ll ans,f[N][N];
vector<int>g[N];
void dfs(int x,int o){sz[o][x]=1;for(int y:g[x])if(y!=fa[o][x])fa[o][y]=x,dfs(y,o),sz[o][x]+=sz[o][y];}
ll gt(int x,int y)
{
	if(f[x][y]!=-1)return f[x][y];else if(x==y)return 0;
	return f[x][y]=max(gt(fa[y][x],y),gt(x,fa[x][y]))+1ll*sz[x][y]*sz[y][x];
}
int main()
{
	scanf("%d",&n);memset(f,-1,sizeof(f));
	for(int i=1,u,v;i<n;i++){scanf("%d%d",&u,&v);g[u].push_back(v);g[v].push_back(u);}
	for(int i=1;i<=n;i++)dfs(i,i);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans=max(ans,gt(i,j));
	printf("%lld\n",ans);return 0;
}