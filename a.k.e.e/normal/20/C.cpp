#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define mp make_pair
const int MAXN=100005;
const ll INF=0x3f3f3f3f3f3f3f3fll;

int n,m;
struct Node
{
	int v,c;
	Node *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
void addEdge(int u,int v,int c)
{
	Node *p=&pool[++etot];
	p->v=v;p->c=c;p->next=h[u];h[u]=p;
}
ll dis[MAXN];
int pre[MAXN];
priority_queue<pli,vector<pli>,greater<pli> > pq;
void dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	pq.push(mp(0ll,1));
	while(!pq.empty())
	{
		int u=pq.top().second;pq.pop();
		for(Node *p=h[u];p;p=p->next)
			if(dis[p->v]>dis[u]+p->c)
			{
				dis[p->v]=dis[u]+p->c;
				pre[p->v]=u;
				pq.push(mp(dis[p->v],p->v));
			}
	}
}
int x[MAXN];
int main()
{
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    int u,v,c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d%d",&u,&v,&c);
    	addEdge(u,v,c);
    	addEdge(v,u,c);
    }
    dijkstra();
    if(dis[n]>=INF)return 0*printf("-1\n");
    int cnt=0;
    for(int i=n;i>=1;i=pre[i],++cnt)x[cnt]=i;
    for(int i=cnt-1;i>=0;i--)printf("%d ",x[i]);
    printf("\n");
    return 0;
}