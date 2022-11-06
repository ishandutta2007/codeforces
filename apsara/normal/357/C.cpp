#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
typedef long long LL;

const int V=300100;
int r[V],ret[V];
int find(int x)
{
    if(x!=r[x])r[x]=find(r[x]);
    return r[x];
}
int n,m,L,R,x;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n+1;i++)r[i]=i;
        memset(ret,0,sizeof(ret));
        while(m--)
        {
            scanf("%d%d%d",&L,&R,&x);
            int u;
            u=find(L);
            while(1)
            {
                if(u>=x)break;
                ret[u]=x;
                r[u]=u+1;
                u=find(u);
            }
            u=find(x+1);
            while(1)
            {
                if(u>R)break;
                ret[u]=x;
                r[u]=u+1;
                u=find(u);
            }
        }
        for(int i=1;i<=n;i++)
        printf("%d ",ret[i]);puts("");
    }
    return 0;
}