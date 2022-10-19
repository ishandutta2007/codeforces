#include <iostream>
#include <vector>

#define M 100100

using namespace std;

vector<long> g[M];
long n,m,c[M],t[M];
bool u[M],e[M];

void read(void){
    cin>>n>>m;
    for (long i=1; i<=n; ++i){
        cin>>c[i];
        e[c[i]]=1;
    }

    for (long a,b,i=1; i<=m; ++i){
        cin>>a>>b;
        a=c[a];
        b=c[b];
        g[a].push_back(b);
        g[b].push_back(a);
    }

}

void solve(long x){
    long a=0;
    for (long i=0; i<g[x].size(); ++i)
    u[g[x][i]]=1;
    for (long i=0; i<g[x].size(); ++i)
    if (u[g[x][i]]){
        u[g[x][i]]=0;
        if (g[x][i]!=x)
        ++a;
    }
    t[x]=a;
}

void find(void){
    long d=-1,f=0;
    for (long i=1; i<M; ++i)
    if (e[i]){
        solve(i);
        if (t[i]>d){
            d=t[i];
            f=i;
        }
    }
    cout<<f;
}


int main()
{
    read();
    find();
    return 0;
}