#include <iostream>
#include <vector>

#define M 100100
#define pb push_back

using namespace std;

long n,m;
vector<long> g[M],d[M],f(M);
vector<bool> u(M,0),c(M,0),t(M,0);

void read(void){
    long a,b;
    cin>>n>>m;
    for(long i=1; i<=n; ++i)
    cin>>f[i];
    for (long i=0; i<m; ++i){
        cin>>a>>b;
        g[a].pb(b);
        d[b].pb(a);
    }
}

void dfs(long v){
    c[v]=1;
    u[v]=1;
    for (long i=0; i<g[v].size(); ++i)
    if (!u[g[v][i]])
    dfs(g[v][i]);
}

void dfs1(long v){
    t[v]=1;
    u[v]=1;
    if (f[v]!=1)
    for (long i=0; i<d[v].size(); ++i)
    if (!u[d[v][i]])
    dfs1(d[v][i]);
}

int main()
{
    read();
    for (long i=1; i<=n; ++i)
    if (f[i]==1 && !c[i])
    dfs(i);
    fill(u.begin(), u.end(), 0);
    for (long i=1; i<=n; ++i)
    if (f[i]==2 && !t[i])
    dfs1(i);
    for (long i=1; i<=n; ++i)
    if (c[i] && t[i])
    cout<<1<<"\n";
    else
    cout<<0<<"\n";
    return 0;
}