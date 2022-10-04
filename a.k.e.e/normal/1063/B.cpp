#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
const int MAXN=2005;

int n,m,sx,sy,L,R;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
char s[MAXN][MAXN];
int f[MAXN][MAXN];
inline int pt(int x,int y){return (x-1)*m+y;}
struct Node
{
	int v,c;
	Node *next;
}pool[MAXN*MAXN*4+1],*h[MAXN*MAXN];
int etot=0;
void addEdge(int u,int v,int c)
{
	Node *p=&pool[++etot];
	p->v=v;p->c=c;p->next=h[u];h[u]=p;
}

priority_queue<pii,vector<pii>,greater<pii> > pq;
int dis[MAXN*MAXN];
void dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	int src=pt(sx,sy);
	pq.push(mp(0,src));
	dis[src]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;pq.pop();
		for(Node *p=h[u];p;p=p->next)
			if(dis[p->v]>dis[u]+p->c)
			{
				dis[p->v]=dis[u]+p->c;
				pq.push(mp(dis[p->v],p->v));
			}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x,y;
    scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&L,&R);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='*')continue;
			for(int t=0;t<4;t++)
			{
				x=i+dir[t][0];y=j+dir[t][1];
				if(!x || !y || x>n || y>m || s[x][y]=='*')continue;
				addEdge(pt(i,j),pt(x,y),t==3);
			}
		}
	dijkstra();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//cout<<(dis[pt(i,j)]>=0x3f3f3f3f?-1:dis[pt(i,j)])<<" ";
			if(s[i][j]=='*')continue;
			x=dis[pt(i,j)];
			//printf("(%d,%d)",x,x+j-sy);
			if(x<=L && x+j-sy<=R)
				++ans;
		}
		//cout<<endl;
	}
	printf("%d\n",ans);
    return 0;
}