#include <iostream>
#include <vector>

#define M 200100
#define pb push_back
#define INF 1000000

using namespace std;


long n,up[M],down[M],gl=0;
vector<long> g[M];
vector<bool> dir[M];
bool u[M];

void read(void){
    cin>>n;
    for (long i=1,a,b; i<n; ++i){
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
        dir[a].pb(1);
        dir[b].pb(0);
    }
}

void dfs(long v){
    u[v]=1;
    for (long i=0,to,d; i<g[v].size(); ++i){
        to=g[v][i];
        d=dir[v][i];

        if (!u[to]){
            if (d){
                gl++;
                down[to]++;
            }
            else
            up[to]++;

            up[to]+=up[v];
            down[to]+=down[v];
            dfs(to);
        }

    }
}


int main()
{
    read();
    dfs(1);
    long m=INF;


    for (long i=1; i<=n; ++i)
    m=min((n-1-gl+down[i]-up[i]),m);
    cout<<m<<"\n";

    for (long i=1; i<=n; ++i)
    if (n-1-gl+down[i]-up[i]==m)
    cout<<i<<" ";

    return 0;
}