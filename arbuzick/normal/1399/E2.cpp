#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
vector<vector<pair<int, int>>> g;
vector<int> used, cnt, w, c;
int dfs(int v, int r){
    used[v] = 1;
    if(v != 0 && g[v].size() == 1)
        cnt[r] = 1;
    for(auto [u, i]: g[v])
        if(!used[u])
            dfs(u, i), cnt[r] += cnt[i];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        g.assign(n, vector<pair<int ,int>>(0));
        used.assign(n, 0);
        cnt.assign(n, 0);
        w.assign(n, 0);
        c.assign(n, 0);
        for(int i = 0; i < n-1; ++i){
            int v, u;
            cin >> v >> u >> w[i] >> c[i];
            v--, u--;
            g[v].pb({u, i});
            g[u].pb({v, i});
        }
        dfs(0, n-1);
        vector<multiset<pair<int, int>>> s1(3);
        vector<vector<int>> sum(3);
        sum[1].pb(0);
        sum[2].pb(0);
        for(int i = 0; i < n-1; ++i)
            s1[c[i]].insert({cnt[i]*w[i]-w[i]/2*cnt[i], i}), sum[c[i]][0] += cnt[i]*w[i];
        for(int i = 1; i < 3; ++i){
            while(!s1[i].empty()){
                int r = s1[i].rbegin()->second;
                sum[i].pb(sum[i].back()-(cnt[r]*w[r]-w[r]/2*cnt[r]));
                w[r] /= 2;
                auto it = s1[i].end();
                it--;
                s1[i].erase(it);
                if(w[r] > 0)
                    s1[i].insert({cnt[r]*w[r]-w[r]/2*cnt[r], r});
            }
        }
        int ans = sum[1].size()+sum[2].size()*2;
        int ind = sum[2].size()-1;
        for(int i = 0; i < sum[1].size(); ++i){
            while(ind > 0 && sum[1][i]+sum[2][ind-1] <= s)
                ind--;
            if(sum[1][i]+sum[2][ind] <= s)
                ans = min(ans, i+ind*2);
        }
        cout << ans << '\n';
    }
    return 0;
}