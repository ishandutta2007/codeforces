#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,m;
struct Node
{
	int v;
	Node *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
void addEdge(int u,int v)
{
	Node *p=&pool[++etot];
	p->v=v;p->next=h[u];h[u]=p;
}

int ans[MAXN];
priority_queue<int,vector<int>,greater<int> > q;
bool vis[MAXN];

int main()
{
    int u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&u,&v);
    	addEdge(u,v);addEdge(v,u);
    }
    q.push(1);
    vis[1]=1;
    for(int i=1;i<=n;i++)
    {
    	u=q.top();q.pop();
    	ans[i]=u;
    	for(Node *p=h[u];p;p=p->next)
    	{
    		if(vis[p->v])continue;
    		vis[p->v]=1;
    		q.push(p->v);
    	}
    }
    for(int i=1;i<=n;i++)
    	printf("%d ",ans[i]);
    return 0;
}