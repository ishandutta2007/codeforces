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
const int V=1000100;
int f[V][22];
int d[V];
int LCA(int x,int y)
{
    if(d[x]<d[y])swap(x,y);
    int df=d[x]-d[y],t=0;
    while(df)
    {
        if(df&1)x=f[x][t];
        df/=2;t++;
    }
    if(x==y)return x;
    for(int i=20;i>=0;i--)
    {
        if(f[x][i]!=f[y][i])
        x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}
int Q,x;
int main()
{
    while(~scanf("%d",&Q))
    {
        memset(f,-1,sizeof(f));
        d[1]=0;
        d[2]=d[3]=d[4]=1;
        f[2][0]=f[3][0]=f[4][0]=1;
        int u=2,v=3,mx=2;
        for(int i=0;i<Q;i++)
        {
            scanf("%d",&x);
            int tu=i*2+5,tv=i*2+6;
            d[tu]=d[tv]=d[x]+1;
            f[tu][0]=x;
            for(int j=1;j<=20;j++)
            if(f[tu][j-1]!=-1)f[tu][j]=f[f[tu][j-1]][j-1];
            for(int j=0;j<=20;j++)
            f[tv][j]=f[tu][j];
            int rt=LCA(tu,u);
            int tmp=d[tu]+d[u]-2*d[rt];
            if(tmp>mx)
            {
                mx=tmp;
                v=tu;
            }
            rt=LCA(tu,v);
            tmp=d[tu]+d[v]-2*d[rt];
            if(tmp>mx)
            {
                mx=tmp;
                u=tu;
            }
            printf("%d\n",mx);
        }
    }
}