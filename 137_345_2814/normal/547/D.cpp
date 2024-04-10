#include<cstdio>
using namespace std;
#define N 200050
int las[N][2],head[N],cnt,cl[N],n,a,b;
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
void dfs(int u){for(int i=head[u];i;i=ed[i].next)if(cl[ed[i].t]==-1)cl[ed[i].t]=cl[u]^1,dfs(ed[i].t);}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;i++)cl[i]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(las[a][0])adde(las[a][0],i),las[a][0]=0;else las[a][0]=i;
		if(las[b][1])adde(las[b][1],i),las[b][1]=0;else las[b][1]=i;
	}
	for(int i=1;i<=n;i++)if(cl[i]==-1)cl[i]=0,dfs(i);
	for(int i=1;i<=n;i++)printf("%c",cl[i]?'r':'b');
}//