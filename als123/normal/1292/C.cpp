#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=3005;
vector<LL> vec[N];
LL fa[N][N],tot[N][N];
void dfs (LL x,LL rt)
{
	tot[rt][x]=1;
	LL siz=vec[x].size();
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u];
		if (y==fa[rt][x]) continue;
		fa[rt][y]=x;
		dfs(y,rt);
		tot[rt][x]+=tot[rt][y];
	}
}
LL f[N][N];
void solve (LL x,LL y)
{
	if (x==y) return ;
	if (f[x][y]!=0) return ;
	solve(x,fa[x][y]);
	solve(y,fa[y][x]);
	f[x][y]=max(f[x][y],f[x][fa[x][y]]+tot[y][x]*tot[x][y]);
	f[x][y]=max(f[x][y],f[y][fa[y][x]]+tot[y][x]*tot[x][y]);
/*	printf("%lld %lld %lld\n",x,y,f[x][y]);
	printf("%lld %lld %lld %lld\n",fa[y][x],fa[x][y],tot[y][x],tot[x][y]);*/
}
int main()
{
	memset(f,0,sizeof(f));
	LL n;
	scanf("%lld",&n);
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (LL u=1;u<=n;u++) dfs(u,u);
	LL ans=0;
	for (LL u=1;u<=n;u++)
	for (LL i=u+1;i<=n;i++)
	{
		solve(u,i);
		ans=max(ans,f[u][i]);
	}
	printf("%lld\n",ans);
	return 0;
}