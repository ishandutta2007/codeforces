#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#define mp std::make_pair

typedef long long LL;
typedef std::pair<int,int> pi;

const int N=100005;
const int MOD=1000000007;
const int inf=1e9;

int n,m,cnt,last[N],dig[N][10],len[N],sz,pos[N],dis[N],fa[N*10][20],ch[N*10][10],val[N*10],bel[N*10];
bool vis[N];
struct edge{int to,next,id;}e[N*2];
std::priority_queue<pi> que;

void addedge(int u,int v,int id)
{
	e[++cnt].to=v;e[cnt].id=id;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].id=id;e[cnt].next=last[v];last[v]=cnt;
}

void pre()
{
	for (int i=1;i<=m;i++)
	{
		int x=i;
		while (x) dig[i][++len[i]]=x%10,x/=10;
		std::reverse(dig[i]+1,dig[i]+len[i]+1);
	}
}

int newnode(int x,int d)
{
	fa[++sz][0]=x;bel[sz]=d;val[sz]=((LL)val[x]*10+(LL)d)%MOD;
	for (int i=1;i<=18;i++) fa[sz][i]=fa[fa[sz][i-1]][i-1];
	return sz;
}

int ins(int x,int id)
{
	for (int i=1;i<=len[id];i++)
	{
		int d=dig[id][i];
		if (!ch[x][d]) ch[x][d]=newnode(x,d);
		x=ch[x][d];
	}
	return x;
}

bool cmp(int x,int y)
{
	for (int i=18;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return bel[x]<bel[y];
}

void bfs()
{
	for (int i=2;i<=n;i++) dis[i]=inf;
	sz=pos[1]=1;que.push(mp(0,1));
	while (!que.empty())
	{
		int x=que.top().second;que.pop();
		while (vis[x]&&!que.empty()) x=que.top().second,que.pop();
		if (vis[x]) break;
		vis[x]=1;
		for (int i=last[x];i;i=e[i].next)
		{
			int id=e[i].id,p=ins(pos[x],id);
			if (dis[x]+len[id]<dis[e[i].to]||dis[x]+len[id]==dis[e[i].to]&&cmp(p,pos[e[i].to]))
			{
				dis[e[i].to]=dis[x]+len[id];
				pos[e[i].to]=p;
				que.push(mp(-dis[e[i].to],e[i].to));
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	pre();
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y,i);
	}
	bfs();
	for (int i=2;i<=n;i++) printf("%d\n",val[pos[i]]);
	return 0;
}