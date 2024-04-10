#include <iostream>
#include <vector>

#define M 100100

using namespace std;

int n,h[M],w[M],q[M],s,p[M];
vector<int> g[M];
bool u[M];
char ans[M];

void read(void){
    cin>>n;
    for (int i=1,x,y; i<n; ++i){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

bool zero(void){
    bool f=0;
    for (int i=1; i<=n; ++i)
    if (ans[i]<'A')
    u[i]=0,f=1;
    else
    u[i]=1;
    return f;
}

int dfs(int v){
    q[s++]=v;
    w[v]=1;
    u[v]=1;
    for (int i=0; i<(int)g[v].size(); ++i){
        int to=g[v][i];
        if (!u[to])
        w[v]+=dfs(to),
        p[to]=v;
    }
    return w[v];
}

void kill(void){
    int k=0;
    while (zero()){
        for (int i=1; i<=n; ++i)
        if (!u[i]){
            s=0;
            
            p[i]=i;
            dfs(i);
            
            int m=q[0];
            for (int j=0; j<s; ++j)
            if (w[q[j]]<w[m])
            m=q[j];
            
            for (int j=0; j<s; ++j)
            if (w[q[j]]<=s/2 && w[q[j]]>w[m])
            m=q[j];
            
            m=p[m];
            
            ans[m]='A'+k;
        }
        k++;
    }
    for (int i=1; i<=n; ++i)
    cout<<ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    read();
    kill();
    return 0;
}