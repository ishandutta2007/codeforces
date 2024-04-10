#include<bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long LL;
typedef std::pair<int,int> pi;

const int N=3005;

int n,size[N],pts1[N][N],pts2[N][N];
std::vector<int> e[N];
std::vector<pi> vec[N];
LL val[N][N],f[N][N];

void dfs(int x,int fa)
{
	size[x]=1;
	for (auto to:e[x])
	{
		if (to==fa) continue;
		dfs(to,x);
		size[x]+=size[to];
	}
}

void dfs2(int x,int fa,int bel,int d,int rt)
{
	vec[d].pb(mp(x,rt));
	val[x][rt]=(LL)size[x]*(n-size[bel]);
	pts1[x][rt]=fa;pts2[x][rt]=bel;
	for (auto to:e[x])
		if (to!=fa) dfs2(to,x,bel,d+1,rt);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[x].pb(y);e[y].pb(x);
	}
	for (int i=1;i<=n;i++)
	{
		dfs(i,0);
		for (auto to:e[i]) dfs2(to,i,to,1,i);
	}
	LL ans=0;
	for (int i=1;i<n;i++)
		for (auto p:vec[i])
		{
			int x=p.first,y=p.second;
			if (i==1) f[x][y]=val[x][y];
			else f[x][y]=std::max(f[pts1[x][y]][y],f[x][pts2[x][y]])+val[x][y];
			ans=std::max(ans,f[x][y]);
		}
	printf("%lld\n",ans);
	return 0;
}