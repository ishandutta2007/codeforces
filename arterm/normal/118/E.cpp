#include <iostream>
#include <vector>

#define M 100100

using namespace std;

long n,m,t=0, in[M], up[M], p[M];
vector<long> g[M];
bool flag=0,u[M],r=0;

void dfs(long v){
    long to;
    u[v]=1;
    in[v]=t;
    up[v]=t;
    t++;
    for (long i=0; i<g[v].size(); ++i){
        to=g[v][i];
        if (p[v]!=to)
        if (u[to]){
            up[v]=min(up[v],in[to]);
            if (r && in[to]<in[v])
            cout<<v<<" "<<to<<"\n";
        }
        else{
            p[to]=v;
            dfs(to);
            up[v]=min(up[v],up[to]);
            if (r)
            cout<<v<<" "<<to<<"\n";
        }
    }
    if (up[v]>in[p[v]])
    flag=1;
}

void read(void){
    cin>>n>>m;
    for (long i=0,a,b; i<m; ++i){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

int main()
{
    read();
    p[1]=1;
    dfs(1);
    if (flag)
    cout<<0;
    else{
        for (long i=1; i<=n; ++i)
        u[i]=0;
        t=0;
        r=1;
        dfs(1);
    }
    return 0;
}