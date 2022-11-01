#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=5005;
vector<int> v[N];
vector<int> vis(N,0);
bool cycle=0;

void dfs1(int a)
{
    vis[a]=1;
    for(int to:v[a])
    {
        if(vis[to]==0) dfs1(to);
        else if(vis[to]==1) cycle=1;
    }
    vis[a]=2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> edges(m+1,{0,0});
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        edges[i]={a,b};
    }
    for(int i=1;i<=n;i++) if(vis[i]==0) dfs1(i);
    cout << cycle+1 << "\n";
    for(int i=1;i<=m;i++) cout << "21"[cycle==0||edges[i][0]<edges[i][1]] << " \n"[i==m];
    return 0;
}