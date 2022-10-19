#include <iostream>
#include <vector>

#define M 100100
#define long long long

using namespace std;

vector<long> g[M],t[M];
long n,f[M],p[M],m[M];
bool u[M];

void read(void){
    cin>>n;
    for (long i=1,x,y; i<n; ++i){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (long i=1; i<=n; ++i)
    cin>>f[i];
}

void dfs1(long v){
    u[v]=1;
    for (long i=0; i<g[v].size(); ++i){
        long to=g[v][i];
        if (!u[to]){
            dfs1(to);
            t[v].push_back(to);
        }
    }
}

void dfs(long v){
    long ma=0,pa=0,ch;
    for (long i=0; i<t[v].size(); ++i){
        long to=t[v][i];
        dfs(to);
        ma=max(ma,m[to]);
        pa=max(pa,p[to]);
    }

    ch=pa-ma;
    f[v]+=ch;

    if (f[v]<0)
    pa-=f[v];
    else
    ma+=f[v];

    m[v]=ma;
    p[v]=pa;
}

int main()
{
    read();
    dfs1(1);
    dfs(1);
    cout<<m[1]+p[1]<<"\n";
    return 0;
}