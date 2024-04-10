#include <iostream>
#include <vector>

#define M 50505

using namespace std;

long n,r1,r2,p[M];
vector<long> g[M];
bool u[M];

void read(void){
    cin>>n>>r1>>r2;
    for (long i=1,a; i<=n; ++i){
        if (i==r1)
        continue;
        cin>>a;
        g[i].push_back(a);
        g[a].push_back(i);
    }
}

void dfs(long v){
    u[v]=1;
    for (long i=0; i<g[v].size(); ++i)
    if (!u[g[v][i]]){
        p[g[v][i]]=v;
        dfs(g[v][i]);
    }
}

int main()
{
    read();
    dfs(r2);
    for (long i=1; i<=n; ++i)
    if (i!=r2)
    cout<<p[i]<<" ";
    return 0;
}