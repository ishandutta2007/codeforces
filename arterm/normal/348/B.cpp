#include <iostream>
#include <vector>
#include <algorithm>

#define M 100100
#define long long long
#define INF 1000000000000000ll

using namespace std;

long n,a[M],b[M],t[M],sum=0;
vector<int> g[M],p[M];
bool u[M];

long gcd(long x, long y){
    while (x){
        y%=x;
        swap(x,y);
    }
    return y;
}

long lcm(long x, long y){
    if (max(x,y)>=INF)
        return INF;
    long t=x/gcd(x,y);
    if (INF/y<t)
        return INF;
    return t*y;
}

void read(void){
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i],sum+=a[i];
    for (int i=1,x,y; i<n; ++i){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void dfs(int v){
    u[v]=1;
    for (int i=0; i<(int)g[v].size(); ++i){
        int to=g[v][i];
        if (u[to])
            continue;

        dfs(to);
        p[v].push_back(to);
    }
}


void kill(int v){
    long e=1,ans=INF;
    if (p[v].empty()){
        b[v]=a[v];
        t[v]=1;
        return;
    }
    for (int i=0; i<p[v].size(); ++i){
        int to=p[v][i];
        kill(to);
        e=lcm(e,t[to]);
    }
    for (int i=0; i<p[v].size(); ++i){
        int to=p[v][i];
        ans=min(ans,b[to]/e);
    }
    b[v]=(ans*p[v].size())*e;
    if (INF/e<p[v].size())
        t[v]=INF;
    else
        t[v]=e*p[v].size();
}

int main(){
    ios_base::sync_with_stdio(0);
    read();
    dfs(1);
    kill(1);
    cout<<sum-b[1]<<"\n";
    return 0;
}