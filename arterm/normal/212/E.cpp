#include <iostream>
#include <vector>

#define N 5500

using namespace std;

long n,w[N];
vector<long> g[N],t[N];
bool u[N],m[2*N],d[2*N];

void read(void){
    cin>>n;
    for (long i=1,a,b; i<n; ++i){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void dfs(long v){
    u[v]=1;
    w[v]=1;
    for (long i=0,to; i<g[v].size(); ++i)
    if (!u[g[v][i]]){
        to=g[v][i];
        t[v].push_back(to);
        dfs(to);
        w[v]+=w[to];
    }
}

void ans(void){
    m[0]=1;
    for (long i=1; i<=n ;++i){

        for (long i=1; i<=n; ++i)
        m[i]=0;
        for (long j=0; j<t[i].size(); ++j)
        for (long k=n; k>=0; --k)
        m[k+w[t[i][j]]]|=m[k];
        for (long k=n; k>=0; --k)
        m[k+n-w[i]]|=m[k];

        for (long k=n; k>=0; --k)
        d[k]|=m[k];
    }
}

int main()
{
    long t=0;
    read();
    dfs(1);
    ans();
    for (long i=1; i<n-1; ++i)
    if (d[i])
    t++;
    cout<<t<<"\n";
    for (long i=1; i<n-1; ++i)
    if (d[i])
    cout<<i<<" "<<n-1-i<<"\n";
    return 0;
}