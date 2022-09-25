#include<cstdio>
#include<cstring>
using namespace std;
#define N 70000
struct edge{int t,next,as,id,vis;}ed[N*4];
int cnt,head[N],n,m,a,b,ct,as[N],in[N],las,ans;
void adde(int f,int t)
{
	ed[++cnt]=(edge){t,head[f],0,++ct,0};head[f]=cnt;
	ed[++cnt]=(edge){f,head[t],1,ct,0};head[t]=cnt;
}
void dfs(int u)
{
	for(int i=head[u];i;i=ed[i].next)
	if(!ed[i].vis)
	{
		ed[i].vis=ed[i^1].vis=1;
		as[ed[i].id]=ed[i].as;
		dfs(ed[i].t);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		cnt=1;ct=las=ans=0;
		memset(head,0,sizeof(head));
		memset(in,0,sizeof(in));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		scanf("%d%d",&a,&b),adde(a,b),in[a]++,in[b]++;
		for(int i=1;i<=n;i++)
		if(in[i]&1)
		{
			if(las)adde(i,las),las=0;
			else las=i;
		}
		else ans++;
		for(int i=2;i<=cnt;i++)
		if(ed[i].vis==0)
		dfs(ed[i].t);
		printf("%d\n",ans);
		for(int i=2;i<=m*2;i+=2)
		{
			if(as[ed[i].id]==1)
			printf("%d %d\n",ed[i].t,ed[i^1].t);
			else
			printf("%d %d\n",ed[i^1].t,ed[i].t);
		}
	}
}