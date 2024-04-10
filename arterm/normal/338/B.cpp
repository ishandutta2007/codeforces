#include <iostream>
#include <vector>

#define M 100100

using namespace std;

vector<int> g[M],t[M],x[M];
int n,m,d,f[M],s,h[M],w[M];
bool u[M],e[M];

void read(void){
    cin>>n>>m>>d;
    for (int i=0; i<m; ++i){
        cin>>s;
        e[s]=1;
    }
    for (int i=1,a,b; i<n; ++i){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
}

void dfs(int v,int d){
    h[v]=d;
    u[v]=1;
    f[v]=-1000000;
    if (e[v])
    f[v]=0;
    
    for (int i=0; i<(int)g[v].size(); ++i){
        int to=g[v][i];
        if (!u[to]){
            t[v].push_back(to);
            dfs(to,d+1);
            f[v]=max(f[v],f[to]+1);
        }
    }
}

void adfs(int v, int d){
    int m1=-1000000,m2=-1000000,x1;
    
    for (int i=0; i<(int)t[v].size(); ++i){
        int to=t[v][i];
        if (m1<f[to])
        m1=f[to],x1=to;
    }
    
    for (int i=0; i<(int)t[v].size(); ++i){
        int to=t[v][i];
        if (to!=x1)
        m2=max(f[to],m2);
    }
    
    m1++,m2++;
    
    for (int i=0; i<(int)t[v].size(); ++i){
        int to=t[v][i];
        if (to!=x1)
        adfs(to,max(d,m1)+1);
        else
        adfs(to,max(d,m2)+1);
    }
    
    w[v]=max(f[v],d);
}

int main()
{
    read();
    dfs(s,0);
    
    adfs(s,-1000000);
    
    int ans=0;
    for (int i=1; i<=n; ++i)
    if (h[i]<=d && w[i]<=d)
    ans++;
    
    
    cout<<ans<<"\n";
    return 0;
}