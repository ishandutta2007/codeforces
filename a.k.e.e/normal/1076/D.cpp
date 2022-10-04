#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;
#define mp make_pair
const int MAXN=300005;
const ll INF=1ll<<60;

int n,k;
struct Node
{
    int v,x;
	ll c;
    Node *next;
}pool[MAXN<<2|1],*h[MAXN];
int etot=0;
inline void addEdge(Node *h[],int u,int v,ll c,int x)
{
    Node *p=&pool[++etot];
    p->v=v;p->c=c;p->x=x;p->next=h[u];h[u]=p;
}

priority_queue<pii,vector<pii>,greater<pii> > pq;
ll dis[MAXN];
int pre[MAXN],ans[MAXN],cnt;
void dijkstra(int src)
{
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[src]=0;
    pq.push(mp(0,src));
    while(!pq.empty())
    {
        pii pr=pq.top();pq.pop();
        int u=pr.second;
        if(pr.first>dis[u])continue;
        if(u>1)ans[++cnt]=pre[u];
        for(Node *p=h[u];p;p=p->next)
            if(dis[p->v]>dis[u]+p->c)
            {
                dis[p->v]=dis[u]+p->c;
                pre[p->v]=p->x;
                pq.push(mp(dis[p->v],p->v));
            }
    }
}
int main()
{
    int E,u,v,c;
    scanf("%d%d%d",&n,&E,&k);
    for(int i=1;i<=E;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        addEdge(h,u,v,c,i);
        addEdge(h,v,u,c,i);
    }
    dijkstra(1);
    printf("%d\n",min(cnt,k));
    for(int i=1;i<=cnt && i<=k;i++)
    	printf("%d ",ans[i]);
    return 0;
}