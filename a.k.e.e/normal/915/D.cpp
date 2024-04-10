#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=505,MAXM=100005;

int n,m;
struct Node
{
	int v,id;
	Node *next;
}pool[MAXM],*h[MAXN];
int etot=0;
inline void addEdge(int u,int v,int id)
{
	Node *p=&pool[++etot];
	p->v=v;p->id=id;p->next=h[u];h[u]=p;
}

int ver[MAXN],edg[MAXN];
bool vis[MAXN];
bool findloop(int u,int id)
{
	vis[u]=1;
	for(Node *p=h[u];p;p=p->next)
	{
		if(p->v==id){ver[id]=u;edg[id]=p->id;return 1;}
		if(vis[p->v])continue;
		if(findloop(p->v,id)){ver[p->v]=u;edg[p->v]=p->id;return 1;}
	}
	return 0;
}

int ind[MAXN],q[MAXN];
bool topsort(int e)
{
	int front=1,rear=0;
	memset(ind,0,sizeof(ind));
	for(int i=1;i<=n;i++)
		for(Node *p=h[i];p;p=p->next)
			if(p->id!=e)++ind[p->v];
	for(int i=1;i<=n;i++)
		if(!ind[i])q[++rear]=i;
	while(front<=rear)
	{
		int u=q[front++];
		for(Node *p=h[u];p;p=p->next)
			if(p->id!=e)
			{
				--ind[p->v];
				if(!ind[p->v])q[++rear]=p->v;
			}
	}
	return rear==n;
}

int main()
{
    int u,v;
    scanf("%d%d",&n,&m); 
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&u,&v);
    	addEdge(u,v,i);
    }
    u=0;
    for(int i=1;i<=n;i++)
    {
    	memset(vis,0,sizeof(vis));
    	if(findloop(i,i)){u=i;break;}
    }
    if(!u)return 0*printf("YES\n");
    v=u;
    do
    {
    	int e=edg[v];
    	if(topsort(e))return 0*printf("YES\n");
    	v=ver[v];
    }while(v!=u);
    printf("NO\n");
    return 0;
}