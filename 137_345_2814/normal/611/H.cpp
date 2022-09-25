#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define N 26
#define M 1206
char t[N];
int n,m,s[N][N],tp[N],e[M][2],fa[N],head[N],cnt,dis[N],cur[N],st[N],ct,is[N],v[N]={0,1,10,100,1000,10000,100000},v2[N]={0,1,10,100,1000,10000,100000};
struct edge{int t,next,v;}ed[M];
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],0};head[t]=cnt;}
bool bfs(int s,int t)
{
	queue<int> tp;tp.push(s);memset(dis,-1,sizeof(dis));dis[s]=0;memcpy(cur,head,sizeof(cur));
	while(!tp.empty())
	{
		int r=tp.front();tp.pop();
		for(int i=head[r];i;i=ed[i].next)
		if(ed[i].v&&dis[ed[i].t]==-1)
		{
			dis[ed[i].t]=dis[r]+1;tp.push(ed[i].t);
			if(ed[i].t==t)return 1;
		}
	}
	return 0;
}
int dfs(int u,int t,int f)
{
	if(!f||u==t)return f;
	int as=0,tp;
	for(int &i=cur[u];i;i=ed[i].next)
	if(ed[i].v&&dis[ed[i].t]==dis[u]+1&&(tp=dfs(ed[i].t,t,min(ed[i].v,f))))
	{
		ed[i].v-=tp;ed[i^1].v+=tp;
		f-=tp,as+=tp;
		if(!f)return as;
	}
	return as;
}
int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}
void doit(int a,int b,int l1,int l2)
{
	if(!s[l1][l2])l1^=l2^=l1^=l2,a^=b^=a^=b;
	printf("%d %d\n",a,b);s[l1][l2]--;
}
void dfs2(int d,int v1)
{
	if(d==m)
	{
		int su=0;
		for(int i=1;i<=m;i++)fa[i]=i;
		for(int i=1;i<m;i++)fa[finds(e[st[i]][0])]=finds(e[st[i]][1]);
		for(int i=2;i<=m;i++)if(finds(i)!=finds(1))return;
		for(int i=1;i<=ct+m+2;i++)head[i]=0;cnt=1;
		for(int i=1;i<=ct;i++)adde(ct+m+1,i,s[e[i][0]][e[i][1]]+s[e[i][1]][e[i][0]]-is[i]),adde(i,e[i][0]+ct,1e9),adde(i,e[i][1]+ct,1e9);
		for(int i=1;i<=m;i++)adde(i+ct,ct+m+2,tp[i]-1),su+=tp[i]-1;
		while(bfs(ct+m+1,ct+m+2))su-=dfs(ct+m+1,ct+m+2,1e9);
		if(su)return;
		for(int i=1;i<m;i++)doit(v[e[st[i]][0]],v[e[st[i]][1]],e[st[i]][0],e[st[i]][1]);
		for(int i=1;i<=m;i++)while(s[i][i])doit(v[i],++v2[i],i,i);
		for(int i=1;i<=m;i++)
		for(int j=head[ct+i];j;j=ed[j].next)
		if(ed[j].t!=ct+m+2)
		for(int k=1;k<=ed[j].v;k++)doit(++v2[i],v[e[ed[j].t][1]+e[ed[j].t][0]-i],i,e[ed[j].t][1]+e[ed[j].t][0]-i);
		exit(0);
	}
	for(int i=v1+1;i<=ct;i++)if(s[e[i][0]][e[i][1]]+s[e[i][1]][e[i][0]])st[d]=i,is[i]=1,dfs2(d+1,i),is[i]=0;
}
int main()
{
	scanf("%d",&n);
	int st=n;while(st)st/=10,m++;
	for(int i=1;i<n;i++)
	{
		int s1=0,s2=0;
		scanf("%s",t+1);s1=strlen(t+1);
		scanf("%s",t+1);s2=strlen(t+1);
		s[s1][s2]++;
	}
	for(int i=1;i<=n;i++)
	{
		int st=i,vl=0;
		while(st)st/=10,vl++;
		tp[vl]++;
	}
	for(int i=1;i<=m;i++)tp[i]-=s[i][i];
	for(int i=1;i<=m;i++)if(tp[i]<=0){printf("-1\n");return 0;}
	for(int i=1;i<=m;i++)
	for(int j=i+1;j<=m;j++)
	e[++ct][0]=i,e[ct][1]=j;
	dfs2(1,0);printf("-1\n");
}