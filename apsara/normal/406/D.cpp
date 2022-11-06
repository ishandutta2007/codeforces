#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
LL x[V],y[V];
int f[V][22],r[V],d[V];
int LCA(int u,int v)
{
    if(d[u]<d[v])swap(u,v);
    int ds=d[u]-d[v],t=0;
    while(ds)
    {
        if(ds&1)u=f[u][t];
        t++;ds/=2;
    }
    if(u==v)return u;
    for(int i=20;i>=0;i--)
    if(f[u][i]!=f[v][i])
    u=f[u][i],v=f[v][i];
    return f[u][0];
}
int n,Q,u,v;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(f,-1,sizeof(f));
        for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
        r[n]=n;d[n]=0;
        for(int i=n-1;i>0;i--)
        {
            r[i]=i+1;
            while(1)
            {
                int j=r[i];
                int k=r[j];
                if(k==-1)break;
                if((y[j]-y[i])*(x[k]-x[j])<(y[k]-y[j])*(x[j]-x[i]))
                {
                    r[i]=k;
                }
                else break;
            }
            d[i]=d[r[i]]+1;
            f[i][0]=r[i];
            //printf("%d %d %d\n",i,d[i],r[i]);
            for(int j=1;j<=20;j++)
            f[i][j]=f[f[i][j-1]][j-1];
        }
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d%d",&u,&v);
            printf("%d\n",LCA(u,v));
        }
    }
}