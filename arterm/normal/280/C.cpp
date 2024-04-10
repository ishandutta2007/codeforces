#include <iostream>
#include <vector>

#define M 100100

using namespace std;

double ans=0;
vector<int> g[M];
int n;
bool u[M];

void read(void){
    cin>>n;
    for (int i=1,x,y;i<n; ++i){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void dfs(int v, int d){
    ans=ans+1.0/d;
    u[v]=1;
    for (int i=0,to; i<g[v].size(); ++i){
        to=g[v][i];
        if (!u[to])
        dfs(to,d+1);
    }
}

int main()
{
    cout.precision(10);
    cout<<fixed;
    read();
    dfs(1,1);
    cout<<ans;
    return 0;
}