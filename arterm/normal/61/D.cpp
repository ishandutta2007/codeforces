#include <iostream>
#include <vector>

#define M 100100
#define pb push_back
#define long long long

using namespace std;

long n;
vector<long> d[M],g[M],w[M],dw[M],s(M,0),b(M,0);
vector<bool> u(M,0);

void dfs(long v){
    u[v]=1;
    for (long i=0; i<d[v].size(); ++i)
    if (!u[d[v][i]]){
        g[v].pb(d[v][i]);
        w[v].pb(dw[v][i]);
        dfs(d[v][i]);
    }
}

long calcs(long v){
    for (long i=0; i<g[v].size(); ++i)
    s[v]+=(2*w[v][i]+calcs(g[v][i]));
    return s[v];
}

long calcb(long v){
    long m=0;
    for (long i=0; i<g[v].size(); ++i)
    m=max(m,(s[g[v][i]]+w[v][i]-calcb(g[v][i])));
    return b[v]=s[v]-m;
}

void read(void){
    long a,b,we;
    cin>>n;
    for (long i=1; i<n; ++i){
        cin>>a>>b>>we;
        d[a].pb(b);
        dw[a].pb(we);
        d[b].pb(a);
        dw[b].pb(we);
    }
}

int main()
{
    read();
    dfs(1);
    calcs(1);
    cout<<calcb(1);
    return 0;
}