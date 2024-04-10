#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
vector<vector<pair<int, int>>> g;
int sum = 0;
vector<int> used, cnt, w;
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
        for(int i = 0; i < n-1; ++i){
            int v, u;
            cin >> v >> u >> w[i];
            v--, u--;
            g[v].pb({u, i});
            g[u].pb({v, i});
        }
        sum = 0;
        dfs(0, n-1);
        multiset<pair<int, int>> s1;
        for(int i = 0; i < n-1; ++i)
            s1.insert({cnt[i]*w[i]-w[i]/2*cnt[i], i}), sum += w[i]*cnt[i];
        int ans = 0;
        while(sum > s){
            ans++;
            int r = s1.rbegin()->second;
            sum = sum-(cnt[r]*w[r]-w[r]/2*cnt[r]);
            w[r] /= 2;
            auto it = s1.end();
            it--;
            s1.erase(it);
            s1.insert({cnt[r]*w[r]-w[r]/2*cnt[r], r});
        }
        cout << ans << '\n';
    }
    return 0;
}