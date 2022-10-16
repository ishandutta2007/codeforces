#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5 + 5;
vector<int> adj[MAX];
int n;
int c[MAX];
int num[MAX];
int parent[MAX];
int leaves[MAX];
ll S;
ll w[MAX];
ll sum[MAX];
ll cur = 0;

map<pair<int, int>, int> conv;
pair<int, int> cp(int u, int v){
    return make_pair(min(u, v), max(u, v));
}
void dfs_leaves(int src, int par){
    parent[src] = par;
    if(adj[src].size() == 1 && src != 0) num[src] = 1;
    for(int nxt: adj[src]){
        if(nxt == par) continue;
        sum[nxt] = sum[src] + w[conv[cp(nxt, src)]];
        dfs_leaves(nxt, src);
        num[src] += num[nxt];
    }
    if(par != -1){
        leaves[conv[cp(par, src)]] = num[src];
    }
    if(adj[src].size() == 1 && src != 0) cur += sum[src];
}
void solve_case(){
    cin >> n >> S;
    cur = 0;
    for(int i = 0; i < n; i++) {
        adj[i].clear();
        num[i] = 0;
        sum[i] = 0;
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v >> w[i] >> c[i];
        u--; v--; c[i]--;
        adj[u].push_back(v); adj[v].push_back(u);
        conv[cp(u, v)] = i;
    }
    dfs_leaves(0, -1);
    vector<ll> best[2];
    multiset<pair<ll, pair<ll, ll>>> s[2];
    for(int i = 0; i < n - 1; i++){
        s[c[i]].insert(make_pair((w[i] + 1) / 2 * leaves[i], make_pair(leaves[i], w[i])));
    }

    for(int t = 0; t < 2; t++){
        ll val = 0;
        best[t].push_back(val);
        while(s[t].size()){
            auto cur = *s[t].rbegin();
            s[t].erase(s[t].find(cur));
            ll add = cur.first;
            ll num_leaves = cur.second.first;
            ll weight = cur.second.second;
            val += add;
            best[t].push_back(val);
            if(weight / 2 > 0){
                weight /= 2;
                s[t].insert(make_pair((weight + 1) / 2 * num_leaves, make_pair(num_leaves, weight)));
            }
        }
    }
    int ans = 1e9;
    int j = 0;
    for(int i = (int) best[0].size() - 1; i >= 0; i--){
        while(j < (int) best[1].size() - 1 && cur - (best[0][i] + best[1][j]) > S){
            j++;
        }
        if(cur - (best[0][i] + best[1][j]) <= S){
            ans = min(ans, i + 2 * j);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve_case();
}