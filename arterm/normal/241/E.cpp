#include <iostream>
#include <vector>
#include <time.h>

#define INF 100000000
#define M 10050
#define N 1010

using namespace std;

long a[M],b[M],w[M],d[N],n,m;
bool p[2][N];
vector<long> g[2][N];

void read(void){
    cin>>n>>m;

    for (long x,y,i=0; i<m; ++i){
        cin>>x>>y;
        g[0][x].push_back(y);
        g[1][y].push_back(x);
        a[2*i]=y;
        b[2*i]=x;
        w[2*i]=-1;
        a[2*i+1]=x;
        b[2*i+1]=y;
        w[2*i+1]=2;
    }
    m*=2;
}

void dfs(long v, long t){
    p[t][v]=1;
    for (long i=0; i<g[t][v].size(); ++i)
    if (!p[t][g[t][v][i]])
    dfs(g[t][v][i],t);
}

bool cs(long v){
    return p[0][v]&&p[1][v];
}


void ford(void){
    d[1]=0;
    for (long i=2; i<=n; ++i)
    d[i]=INF;
    for (long i=0; i<n; ++i)
    for (long j=0; j<m; ++j)
    if (cs(b[j]) && cs(a[j]))
    d[b[j]]=min(d[b[j]],(d[a[j]]+w[j]));
}

void write(void){
    for (long j=0; j<m; ++j)
    if (cs(b[j]) && cs(a[j]) && d[b[j]]>d[a[j]]+w[j]){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    for (long j=0; j<m; j+=2)
    if (d[a[j]]==d[b[j]]+1)
    cout<<"1\n";
    else
    cout<<"2\n";
}

int main()
{
    read();
    dfs(1,0);
    dfs(n,1);
    ford();
    write();
    return 0;
}