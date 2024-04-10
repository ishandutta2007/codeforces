#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=1005;

int n;
int G[MAXN][MAXN],dep[MAXN],pa[MAXN];
void dfs(int u)
{
	for(int i=1;i<=n;++i)
		if(G[u][i] && i!=pa[u])
		{
			pa[i]=u;
			dep[i]=dep[u]+1;
			dfs(i);
		}
}
void reply(int u)
{
	printf("! %d\n",u);
	fflush(stdout);
	exit(0);
}
int getdia(int u)
{
	memset(dep,0,sizeof(dep));
	dep[u]=1,pa[u]=0;
	dfs(u);
	int x=1;
	for(int i=1;i<=n;++i)
		if(dep[i]>dep[x])x=i;
	dep[x]=1,pa[x]=0;
	dfs(x);
	int y=1;
	for(int i=1;i<=n;++i)
		if(dep[i]>dep[y])y=i;
	if(x==y)reply(x);
	printf("? %d %d\n",x,y);fflush(stdout);
	readint(u);
	if(u==x || u==y)reply(u);
	pa[u]=0;
	dfs(u);
	for(;pa[x]!=u;x=pa[x]);
	for(;pa[y]!=u;y=pa[y]);
	G[u][x]=G[x][u]=G[u][y]=G[y][u]=0;
	return u;
}

int main()
{
	#ifndef ONLINE_JUDGE
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int u,v;
	readint(n);
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v);
		G[u][v]=G[v][u]=1;
	}
	u=1;
	while(1)u=getdia(u);
	return 0;
}