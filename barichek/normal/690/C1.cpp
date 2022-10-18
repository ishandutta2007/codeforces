#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long long ans, n, m, used[10010];
vector <int> t[10010];

void dfs(int prev, int x)
{
    if (used[x]) {ans=100; return;}
    used[x]++;
    for (int i=0; i<t[x].size(); i++)
        if (t[x][i]!=prev) dfs(x,t[x][i]);
}

int main()
{
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        t[a].pb(b);
        t[b].pb(a);
    }
    if (m!=n-1) { cout<<"no"; return 0;}
    dfs(0,1);
    for (int i=1; i<=n; i++)
        if (used[i]!=1) ans=100;
    if (ans==100) cout<<"no"; else cout<<"yes";
    return 0;
}