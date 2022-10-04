#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=150005;
#define next xtqakioi
int n,fa[MAXN],tail[MAXN];
int getfa(int v){return v==fa[v]?v:fa[v]=getfa(fa[v]);}
int next[MAXN];

int main()
{
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)fa[i]=tail[i]=i;
    for(int i=1;i<n;i++)
    {
    	scanf("%d%d",&u,&v);
    	u=getfa(u);v=getfa(v);
    	next[tail[u]]=v;
    	tail[u]=tail[v];
    	fa[v]=u;
    }
    for(int i=1;i<=n;i++)
    	if(fa[i]==i){u=i;break;}
    for(;u;u=next[u])
    	printf("%d ",u);
    return 0;
}