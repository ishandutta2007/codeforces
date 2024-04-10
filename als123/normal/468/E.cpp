#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
const int K=105;
const int MOD=1e9+7;
int n,k;
struct qq
{
	int x,y,z,last;
}e[N];int num,last[N];
int Fa[N];
int f[N];
int f1[K];
int ff[K];
int JC[N];
void init (int x,int y,int z)
{
	num++;
	e[num].x=x;e[num].y=y;e[num].z=z;
	e[num].last=last[x];
	last[x]=num;
}
int find_fa (int x)	{return Fa[x]==x?Fa[x]:Fa[x]=find_fa(Fa[x]);}
int mul (int x,int y)	{return (LL)x*y%MOD;}
int add (int x,int y)	{return (LL)(x+y)%MOD;}
bool vis[N];
bool in[N];
vector<int> vec,vec1;//
void dfs (int x)// 
{
	if (in[x]) return ;
	in[x]=true;
	if (x>n) vec.push_back(x);
	else vec1.push_back(x);
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		dfs(y);
	}
}
int bin[1<<18];
int g[2][1<<18];// 
int id[N];
int mymin (int x,int y)	{return x<y?x:y;}
bool solve1 (int x)// 
{
	//printf("YES\n");
	vis[x]=true;
	dfs(x);
	if (vec.size()<=17) swap(vec,vec1);
	if (vec1.size()>17)
	{
		vec.clear();vec1.clear();
		return false;
	}
	int siz=vec.size(),siz1=vec1.size();// 
	for (int u=0;u<siz1;u++)	id[vec1[u]]=u;//
	int now=0;
	g[0][0]=1;
	for (int i=1;i<(1<<siz1);i++) g[now][i]=0;
	for (int u=0;u<siz;u++)// 
	{
		int xx=vec[u];
		now^=1;for (int i=0;i<(1<<siz1);i++)	g[now][i]=g[now^1][i];
		for (int i=0;i<(1<<siz1);i++)
		{
			if (g[now^1][i]==0) continue;
			for (int o=last[xx];o!=-1;o=e[o].last)
			{
				int y=e[o].y;
				if ((i&(1<<id[y]))!=0) continue;//
				g[now][i|(1<<id[y])]=add(g[now][i|(1<<id[y])],mul(g[now^1][i],e[o].z-1));
			}
		}
	}
	for (int u=0;u<=siz1;u++) f1[u]=0;
	for (int u=0;u<(1<<siz1);u++)	f1[bin[u]]=add(f1[bin[u]],g[now][u]);
	for (int u=0;u<=k;u++)
	{
		ff[u]=0;
		for (int i=0;i<=mymin(siz1,u);i++)
			ff[u]=add(ff[u],mul(f1[i],f[u-i]));
	}
	for (int u=0;u<=k;u++) f[u]=ff[u];
	vec.clear();vec1.clear();
	//printf("NO\n");
	return true;
}
int dfn[N];
bool ok[N];// 
bool used[N];
void dfs1 (int x,int ff)// 
{
//	printf("now:%d %d\n",x,ff);
	dfn[x]=++num;ok[x]=false;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (dfn[y]==-1)	
		{
			used[u]=true;
			dfs1(y,x);
		}
		else 
		{
			if (ff!=y&&dfn[y]>dfn[x])	
			{
				vec.push_back(u);
			}
		}
	}
}
int siz;
int root;
int F[N][K][2];
int FF[K][2];
void dfs3 (int x)
{
	//return ;
	for (int u=0;u<=num;u++) F[x][u][0]=F[x][u][1]=0;
	F[x][0][0]=1;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		//printf("%d %d %d %d\n",x,y,dfn[x],dfn[y]);
		if (used[u]==false) continue;
		dfs3(y);
		for (int i=0;i<=num;i++) 
		{
			FF[i][0]=F[x][i][0],FF[i][1]=F[x][i][1];
			F[x][i][0]=F[x][i][1]=0;
		}
		for (int i=0;i<=num;i++)
			for (int j=0;j<=i;j++)
			{
				F[x][i][0]=add(F[x][i][0],mul(FF[j][0],add(F[y][i-j][0],F[y][i-j][1])));
				F[x][i][1]=add(F[x][i][1],mul(FF[j][1],add(F[y][i-j][0],F[y][i-j][1])));
			}
		if (ok[y]==false&&ok[x]==false)// 
		{
			for (int i=0;i<=num;i++)
			{
				if(FF[i][0]==0) continue;
				for (int j=0;j<=num;j++)
				{
					if (i+j>=num) continue;
					F[x][i+j+1][1]=add(F[x][i+j+1][1],mul(mul(FF[i][0],F[y][j][0]),(e[u].z-1)));
				}
			}
		}
		/*printf("YES:%d %d\n",x,y);
		for (int i=0;i<=num;i++) printf("%d %d\n",F[x][i][0],F[x][i][1]);*/
	}
}
void DP (int sum,int tot)
{
	dfs3(root);
	for (int u=0;u<=num;u++)	f1[u+tot]=add(f1[u+tot],mul(sum,add(F[root][u][0],F[root][u][1])));
}
void dfs2 (int x,int sum,int tot)// 
{
	//printf("%d %d\n",x,siz);
	if (x>siz)	{DP(sum,tot);return ;}
	int xx=vec[x-1];
	if (ok[e[xx].x]==false&&ok[e[xx].y]==false)
	{
		ok[e[xx].x]=true; ok[e[xx].y]=true;
		dfs2(x+1,mul(sum,(e[xx].z-1)),tot+1);
		ok[e[xx].x]=false;ok[e[xx].y]=false;
	}
	dfs2(x+1,sum,tot);
}
void solve2 (int x)// 
{
	num=0;
	vis[x]=true;
	root=x;
	dfs1(root,0);
	siz=vec.size();
	memset(f1,0,sizeof(f1));
	dfs2(1,1,0);
	memset(ff,0,sizeof(ff));
	for (int u=0;u<=k;u++)
		for (int i=0;i<=u;i++)
			ff[u]=add(ff[u],mul(f[u-i],f1[i]));
	for (int u=0;u<=k;u++) f[u]=ff[u];
	vec.clear();
	//system("pause");
}
int main()
{	
	memset(in,false,sizeof(in));
	bin[0]=0;
	for (int u=1;u<=(1<<17);u++)	bin[u]=bin[u>>1]+(u&1);
	num=1;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&k);
	memset(dfn,-1,sizeof(dfn));
	JC[0]=1;for (int u=1;u<=n;u++) JC[u]=mul(JC[u-1],u);
	for (int u=1;u<=2*n;u++) Fa[u]=u;
	for (int u=1;u<=2*n;u++) vis[u]=false;
	for (int u=1;u<=k;u++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		y=y+n;
		Fa[find_fa(x)]=find_fa(y);
		init(y,x,z);init(x,y,z);
	}
	f[0]=1;
	for (int u=1;u<=2*n;u++)
		if (vis[find_fa(u)]==false)
		{
			if (!solve1(find_fa(u))) 
				solve2(find_fa(u));
		}
	int ans=0;
	/*for (int u=0;u<=k;u++) printf("%d\n",f[u]);
	printf("\n");*/
	for (int u=0;u<=k;u++)	ans=add(ans,mul(JC[n-u],f[u]));
	printf("%d\n",ans);
	return 0;
}