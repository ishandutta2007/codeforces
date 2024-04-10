#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=300005,INF=1<<30;

int n;
char s[MAXN];

struct Node
{
	int v;
	Node *next;
}pool[MAXN<<1|1],*h[MAXN];
int tot=0;
void addEdge(int u,int v)
{
	Node *p=&pool[++tot];
	p->v=v;p->next=h[u];h[u]=p;
}

int q[MAXN],ind[MAXN];
bool topsort()
{
	int u,front=1,rear=0;
	memset(ind,0,sizeof(ind));
	for(int i=1;i<=n;i++)
		for(Node *p=h[i];p;p=p->next)
			ind[p->v]++;
	for(int i=1;i<=n;i++)
		if(!ind[i])
			q[++rear]=i;
	while(front<=rear)
	{
		u=q[front++];
		for(Node *p=h[u];p;p=p->next)
		{
			ind[p->v]--;
			if(!ind[p->v])
				q[++rear]=p->v;
		}
	}
	return rear==n;
}

int d[MAXN];

int dp(int u,char c)
{
	if(d[u]>=0)return d[u];
	d[u]=0;
	for(Node *p=h[u];p;p=p->next)
		d[u]=max(d[u],dp(p->v,c));
	if(s[u]==c)d[u]++;
	return d[u];
}

int main()
{
	#ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int E,u,v;
    scanf("%d%d%s",&n,&E,s+1);
    while(E--)
    {
    	scanf("%d%d",&u,&v);
    	addEdge(u,v);
    }
    if(!topsort())
    {
    	printf("-1\n");
    	return 0;
    }
    int ans=0;
    for(int ch=0;ch<26;ch++)
    {
    	memset(d,-1,sizeof(d));
    	for(int i=1;i<=n;i++)
    		ans=max(ans,dp(i,ch+'a'));
	}
	printf("%d\n",ans);
    return 0;
}