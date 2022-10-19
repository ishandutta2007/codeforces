#include <iostream>
#include <vector>

#define M 2012

using namespace std;

long n;
vector<bool> u(M,0),s(M,0);
vector<long> g[M];

void read(void){
    long x,y;
    cin>>n;
    for (long i=0;i<n; ++i){
        cin>>x>>y;
        y+=1000;
        s[x]=1;
        s[y]=1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void dfs(long v){
    u[v]=1;
    for (long i=0; i<g[v].size(); ++i)
    if (!u[g[v][i]])
    dfs(g[v][i]);
}

int main()
{
    long ans=0;
    read();
    for (long i=1; i<M; ++i)
    if (s[i] && !u[i]){
        ans++;
        dfs(i);
    }
    cout<<ans-1;
    return 0;
}