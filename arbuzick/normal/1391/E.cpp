#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
vector<vector<int>> d, g;
vector<int> used;
vector<int> path;
void dfs(int v, int d1){
    used[v] = 1;
    d[d1].pb(v);
    for(auto u: g[v])
        if(!used[u])
            dfs(u, d1+1);
}
void get_ans(int v){
    used[v] = 0;
    if(path.size()*2 < g.size())
        path.pb(v);
    for(auto u: g[v])
        if(used[u])
            get_ans(u);
    if(path.size()*2 < g.size())
        path.pop_back();
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        d.assign(n+1, vector<int>(0));
        g.assign(n, vector<int>(0));
        used.assign(n, 0);
        path.clear();
        for(int i = 0; i < m; ++i){
            int v, u;
            cin >> v >> u;
            v--, u--;
            g[u].pb(v), g[v].pb(u);
        }
        for(int i = 0; i < n; ++i)
            if(!used[i])
                dfs(i, 0);
        int k = 0;
        for(int i = 0; i < n+1; ++i)
            if(d[i].size() > 0)
                k = i;
        if(k*2 >= n){
            cout << "PATH\n";
            for(int i = 0; i < n; ++i)
                if(used[i])
                    get_ans(i);
            cout << path.size() << '\n';
            for(int i = 0; i < path.size(); ++i)
                cout << path[i]+1 << ' ';
            cout <<'\n';
        }else{
            vector<pair<int, int>> ans;
            for(int i = 0; i < n+1; ++i){
                for(int j = 0; j+1 < d[i].size(); j += 2)
                    ans.pb({d[i][j], d[i][j+1]});
            }
            cout << "PAIRING\n";
            cout << ans.size() << '\n';
            for(int i = 0; i < ans.size(); ++i)
                cout << ans[i].first+1 << ' ' << ans[i].second+1 << '\n';
        }
    }
    return 0;
}