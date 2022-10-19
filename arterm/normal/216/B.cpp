#include <iostream>
#include <vector>

#define pb push_back
#define M 200

using namespace std;

long ans=0;
vector<long> g[M],e(M,1);
vector<bool> u(M,0),c(M,0);

void dfs(long x){
    long to;
    bool fl=0;
    u[x]=1;
    for (long i=0; i<g[x].size(); ++i)
    if (!u[g[x][i]]){
        to=g[x][i];
        c[to]=1;
        e[to]=e[x]+1;
        dfs(to);
        fl=1;
    }
    if (!fl && c[x])
    if (g[x].size()==2)
    if (e[x]%2==1)
    ans++;
}

int main()
{
    long n,m,a,b;

    cin>>n>>m;
    for (long i=0; i<m; ++i){
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for (long i=1; i<=n; ++i)
    if (!u[i])
    dfs(i);

    if ((n-ans)%2==1)
    ans++;

    cout<<ans;

    return 0;
}