#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int a[N], b[N];
vector<int> g[N];
vector<int> v;

void dfs(int k, int par, int lvl, int odd, int even)
{
    if(lvl%2)
    {
        if(a[k]^odd != b[k])
        {
            odd^=1;
            ans++;
            v.push_back(k);
        }
    }
    else
    {
        if(a[k]^even != b[k])
        {
            even^=1;
            ans++;
            v.push_back(k);
        }
    }
    for(auto it:g[k])
    {
        if(it==par)
            continue;
        dfs(it, k, lvl+1, odd, even);
    }
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    dfs(1, 1, 1, 0, 0);
    cout<<ans<<endl;
    for(auto it:v)
        cout<<it<<endl;
    return 0;
}