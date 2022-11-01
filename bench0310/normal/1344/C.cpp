#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    vector<int> vr[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        vr[b].push_back(a);
    }
    bool cycle=0;
    vector<int> vis(n+1,0);
    function<void(int)> dfs=[&](int a)
    {
        vis[a]=1;
        for(int to:v[a])
        {
            if(vis[to]==0) dfs(to);
            else if(vis[to]==1) cycle=1;
        }
        vis[a]=2;
    };
    for(int i=1;i<=n;i++) if(vis[i]==0) dfs(i);
    if(cycle==1)
    {
        cout << "-1\n";
        return 0;
    }
    vector<bool> bad(n+1,0);
    vector<bool> in(n+1,0);
    vector<bool> out(n+1,0);
    function<void(int)> go_out=[&](int a)
    {
        if(out[a]==1) return;
        out[a]=1;
        bad[a]=1;
        for(int to:v[a]) go_out(to);
    };
    function<void(int)> go_in=[&](int a)
    {
        if(in[a]==1) return;
        in[a]=1;
        bad[a]=1;
        for(int to:vr[a]) go_in(to);
    };
    string res(n+1,'E');
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(bad[i]==0)
        {
            c++;
            res[i]='A';
        }
        go_out(i);
        go_in(i);
    }
    cout << c << "\n";
    cout << res.substr(1) << "\n";
    return 0;
}