#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN=100005,MAXK=105;

int n,s,m;
struct Node
{
	int v;
	Node *next;
}pool[MAXN<<1],*h[MAXN];
int etot=0;
void addEdge(int u,int v)
{
	Node *p=&pool[++etot];
	p->v=v;p->next=h[u];h[u]=p;
}

vector<int> go[MAXK];
int dis[MAXN][MAXK];
bool vis[MAXN];
int q[MAXN],front,rear;
void bfs(int T)
{
	front=1,rear=0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<go[T].size();i++)
		vis[q[++rear]=go[T][i]]=true;
	int u;
	while(front<=rear)
	{
		u=q[front++];
		for(Node *p=h[u];p;p=p->next)
			if(!vis[p->v])
			{
				dis[p->v][T]=dis[u][T]+1;
				q[++rear]=p->v;
				vis[p->v]=true;
			}
	}
}

int main()
{
	#ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int E,u,v,ans;
    scanf("%d%d%d%d",&n,&E,&m,&s);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&u);
    	go[u].push_back(i);
    }
    while(E--)
    {
    	scanf("%d%d",&u,&v);
    	addEdge(u,v);
    	addEdge(v,u);
    }
    for(int i=1;i<=m;i++)
    	bfs(i);
    /*for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    		printf("%d ",dis[i][j]);
    	putchar('\n');
    }*/
    for(int i=1;i<=n;i++)
    {
    	ans=0;
    	sort(dis[i]+1,dis[i]+m+1);
    	for(int j=1;j<=s;j++)
    		ans+=dis[i][j];
    	printf("%d\n",ans);
    }
    return 0;
}