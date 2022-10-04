#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=200005;

int n,dep[MAXN],size[MAXN];
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

ll ans=0;
void dfs(int u,int pa)
{
    size[u]=1;
    for(Node *p=h[u];p;p=p->next)
    {
        if(p->v==pa)continue;
        dep[p->v]=dep[u]+1;
        dfs(p->v,u);
        size[u]+=size[p->v];
    }
    ans+=(ll)size[u]*(n-size[u]);
}

int main()
{
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
    	scanf("%d%d",&u,&v);
    	addEdge(u,v);
    	addEdge(v,u);
    }
    dfs(1,-1);
    ll c=0;
    for(int i=1;i<=n;i++)
    	c+=(dep[i]&1);
    c=c*(n-c);
    cout<<ans/2+c-c/2<<endl;
    return 0;
}