#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
bool valid[33][166][166];
bool enl[166][166];
bool can[166];
int n,m;
void upd(int x,int y,int dep=0)
{
	if(valid[dep][x][y])return;
	valid[dep][x][y]=1;
	if(dep==30)return;
	register int i;
	for(i=1;i<=n;i++)
	{
		if(valid[dep][y][i])
			upd(x,i,dep+1);
		if(valid[dep][i][x])
			upd(i,y,dep+1);
	}
		
}
bool tmp[166];
void buffer(bool*x,int lev)
{
	register int i,ii;
	for(i=1;i<=n;i++)tmp[i]=0;
	for(i=1;i<=n;i++)
		if(x[i])
			for(ii=1;ii<=n;ii++)
				if(valid[lev][i][ii])tmp[ii]=1;
	for(i=1;i<=n;i++)x[i]=tmp[i];
}
void trans(bool*x,int tim)
{
	register int i;
	for(i=30;~i;i--)
		if(tim&(1<<i))buffer(x,i);
}
int dis[166];
#include<queue>
std::queue<int>q;
int bfs(int f)
{
	register int i;
	for(i=1;i<=n;i++)dis[i]=2e9;
	dis[f]=0,q.push(f);
	while(q.size())
	{
		int t=q.front();q.pop();
		for(i=1;i<=n;i++)
			if(enl[t][i])
				if(dis[i]>1.9e9)
					dis[i]=dis[t]+1,q.push(i);	
	}return dis[n];
}
int solve(int t)
{
	int ret=2e9;
	register int i;
	for(i=1;i<=n;i++)
		if(can[i])
		{
			int rm=bfs(i);
			
			if(rm<ret)ret=rm;
		}
	if(ret<1.9e9)ret+=t;
	return ret;
}
struct pii
{
	int x,y,d;
}p[11111];
bool operator<(cpnst pii x,cpnst pii y)
{return x.d<y.d;}
#include<algorithm>
int main()
{
	scanf("%d%d",&n,&m);
	register int i;
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].d);
	std::sort(p+1,p+m+1);
	int ans=2e9;
	can[1]=1;
	for(i=1;i<=m;i++)
	{
		trans(can,p[i].d-p[i-1].d);
		enl[p[i].x][p[i].y]=1,upd(p[i].x,p[i].y);
		int t=solve(p[i].d);
		if(t<ans)ans=t;
	}(ans>1.9e9)?puts("Impossible"):printf("%d\n",ans);
}
/*
Just go for it.
*/