//
//  main.cpp
//  upgranet
//
//  Created by Dong Truong on 7/5/19.
//  Copyright  2019 Dong Truong. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define maxn 1000001

struct edge
{
    int64_t u,v,w;
};

int64_t n,m,d,d1,d2,par[maxn],cmin=1e9;edge a[maxn],b[maxn];

bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
void nhap()
{
    cin>>n>>m;
    for (int i=1;i<=m;++i)
        scanf("%lld%lld%lld",&b[i].u,&b[i].v,&b[i].w);
    b[1].w=1e9;d=b[1].u;d1=b[1].v;
    sort(b+1,b+m+1,cmp);
}
int64_t findroot(int64_t u)
{
    if (par[u]<=0) return u;
    return par[u]=findroot(par[u]);
}
void dunion(int64_t ru,int64_t rv)
{
    if (par[ru]<par[rv])
        par[rv]=ru;
    else
    {
        par[rv]=min(par[ru]-1,par[rv]);
        par[ru]=rv;
    }
}
void kruskal()
{
    for (int i=1;i<=m;++i)
    {
        int64_t u = b[i].u , v = b[i].v;
        int64_t ru = findroot(u) , rv = findroot(v);
        if (ru!=rv)
        {
            int64_t x=findroot(d),y=findroot(d1);
            if ( (ru==x && rv==y) || (ru==y && rv==x) )
                cmin=min(cmin,b[i].w);
            dunion(ru,rv);
        }
    }
    cout<<cmin;
}
int main(int argc, const char * argv[]) {
    // freopen("a.inp","r",stdin);
    nhap();
    kruskal();
    return 0;
}