#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;


struct G {
    map<ll, int> id_gen;

    int get_id(int x, int y, int z) {
        ll h = (ll(x) <<32) | (ll(y) <<1) | z;
        assert(z <= 1);

        auto it = id_gen.find(h);
        if (it != id_gen.end())
            return it->second;
        int sz = id_gen.size();
        return id_gen[h] = sz;
    }

    vector<set<int>> adj;
    vector<int> color;

    int add_edge(int x1, int y1, int z1, int x2, int y2, int z2) {
        int id1 = get_id(x1, y1, z1);
        int id2 = get_id(x2, y2, z2);
        if (max(id1, id2) >= (int) adj.size()) {
            adj.resize(max(id1, id2) + 1);
        }
        adj[id1].insert(id2);
        adj[id2].insert(id1);
    }

    bool dfs(const int u) {
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                if (!dfs(v))
                    return false;
            } else if (color[v] == color[u]) {
                return false;
            }
        }
        return true;
    }

    bool is_bip() {
        color.resize(adj.size(), -1);
        for(int i = 0; i < adj.size(); ++i)
            if(color[i] == -1) {
                color[i] = 0;
                if(!dfs(i))
                    return false;
            }
        return true;
    }
};


const int MxN = (int) 5e5 + 9;

vector<int> adj[MxN + 9];
int group[MxN + 9];
bool is_bip[MxN + 9];
int color[MxN + 9];
int cc_id[MxN + 9];

void dfs(const int u) {
    for (int v : adj[u]) {
        if (group[v] != group[u])
            continue;
        if (color[v] == -1) {
            color[v] = color[u] ^ 1;
            cc_id[v] = cc_id[u];
            dfs(v);
        } else if (color[v] == color[u]) {
            is_bip[group[u]] = false;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    memset(color, -1, sizeof color);
    fill(is_bip, is_bip + MxN, true);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> group[i];

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
        if (color[i] == -1) {
            color[i] = 0;
            cc_id[i] = i;
            dfs(i);
        }


    map<pair<int, int>, G> mp;
    for (int u = 1; u <= n; ++u)
        for (int v : adj[u]) {
            if (!is_bip[group[u]] || !is_bip[group[v]] || group[u] == group[v])
                continue;
            auto p = pair<int, int>{min(group[u], group[v]), max(group[u], group[v])};
            auto it = mp.find(p);
            if (it == mp.end()) {
                mp[p] = G();
                it = mp.find(p);
            }
            assert(cc_id[u] > 0 && cc_id[v] > 0);
            it->second.add_edge(cc_id[u], group[u], color[u], cc_id[v], group[v], color[v]);
            it->second.add_edge(cc_id[u], group[u], color[u], cc_id[u], group[u], !color[u]);
            it->second.add_edge(cc_id[v], group[v], color[v], cc_id[v], group[v], !color[v]);
        }


    const ll num_bip_grps = count(is_bip + 1, is_bip + 1 + k, true);
    ll cnt_invalid_pairs = 0;
    for (auto &&e : mp) {
        cnt_invalid_pairs += !e.second.is_bip();
    }

    DBG(num_bip_grps)
    DBG(cnt_invalid_pairs)
    ll ans = num_bip_grps * (num_bip_grps - 1LL) / 2 - cnt_invalid_pairs;
    cout << ans;

    return 0;
}