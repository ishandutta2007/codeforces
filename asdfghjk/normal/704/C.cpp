#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005,md=1000000007;
int n,m,i,j,k,l,x,y,dzx,d[N],w[N],head[N],adj[N],nxt[N],w1[N],w2[N],f[N][2][2],g[N][2][2][2],ans0,ans1,Ans0,Ans1;
bool v[N],vis[N];
int Abs(int a)
{
	return a>0?a:-a;
}
void Add(int &x,int y)
{
	x=(x+y)%md;
}
void addedge(int u,int v,int a,int b)
{
	adj[++l]=v;
	nxt[l]=head[u];
	head[u]=l;
	w1[l]=a,w2[l]=b;
	adj[++l]=u;
	nxt[l]=head[v];
	head[v]=l;
	w1[l]=b,w2[l]=a;
	++d[u],++d[v];
}
void dfs(int x)
{
	dzx=x;
	v[x]=true;
	for(int y=head[x];y;y=nxt[y])
		if(!v[adj[y]])
		{
			vis[(y+1)/2]=true;
			for(int i=0;i<=1;++i)
				for(int j=0;j<=1;++j)
				{
					Add(f[adj[y]][0][j^(w[adj[y]]==0)^(w1[y]==i||w2[y]==0)],f[x][i][j]);
					Add(f[adj[y]][1][j^(w[adj[y]]==1)^(w1[y]==i||w2[y]==1)],f[x][i][j]);
				}
			dfs(adj[y]);
		}
}
void Dfs(int x)
{
	dzx=x;
	v[x]=true;
	for(int y=head[x];y;y=nxt[y])
		if(!v[adj[y]])
		{
			vis[(y+1)/2]=true;
			for(int i=0;i<=1;++i)
				for(int j=0;j<=1;++j)
					for(int k=0;k<=1;++k)
					{
						Add(g[adj[y]][i][0][k^(w[adj[y]]==0)^(w1[y]==j||w2[y]==0)],g[x][i][j][k]);
						Add(g[adj[y]][i][1][k^(w[adj[y]]==1)^(w1[y]==j||w2[y]==1)],g[x][i][j][k]);
					}
			Dfs(adj[y]);
		}
}
int main()
{
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;++i)
		w[i]=-1;
	for(i=1;i<=m;++i)
	{
		scanf("%d",&j);
		if(j==1)
		{
			scanf("%d",&j);
			if(j>0)
				w[j]=1;
			else
				w[-j]=0;
		}
		else
		{
			scanf("%d%d",&j,&k);
			addedge(Abs(j),Abs(k),j>0?1:0,k>0?1:0);
		}
	}
	ans0=1,ans1=0;
	for(i=1;i<=n;++i)
		if(d[i]<=1&&!v[i])
		{
			f[i][0][w[i]==0]=f[i][1][w[i]==1]=1;
			dfs(i);
			Ans0=(1ll*ans0*(f[dzx][0][0]+f[dzx][1][0])%md+1ll*ans1*(f[dzx][0][1]+f[dzx][1][1])%md)%md;
			Ans1=(1ll*ans0*(f[dzx][0][1]+f[dzx][1][1])%md+1ll*ans1*(f[dzx][0][0]+f[dzx][1][0])%md)%md;
			ans0=Ans0,ans1=Ans1;
		}
	for(i=1;i<=n;++i)
		if(!v[i])
		{
			g[i][0][0][w[i]==0]=g[i][1][1][w[i]==1]=1;
			Dfs(i);
			for(y=head[dzx];y;y=nxt[y])
				if(!vis[(y+1)/2])
					break;
			Ans0=Ans1=0;
			for(j=0;j<=1;++j)
				for(k=0;k<=1;++k)
					for(x=0;x<=1;++x)
					{
						if(x^(w1[y]==k||w2[y]==j))
						{
							Add(Ans1,1ll*ans0*g[dzx][j][k][x]%md);
							Add(Ans0,1ll*ans1*g[dzx][j][k][x]%md);
						}
						else
						{
							Add(Ans0,1ll*ans0*g[dzx][j][k][x]%md);
							Add(Ans1,1ll*ans1*g[dzx][j][k][x]%md);
						}
					}
			ans0=Ans0,ans1=Ans1;
		}
	printf("%d",ans1);
	return 0;
}