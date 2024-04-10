#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 998244353;

int bpow(int x, int n) {
    return n > 0 ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int u[m], v[m];
    vector<pair<int, int>> g[2 * n];
    vector<int> G[n][2];
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        g[2 * u[i]].push_back({0, 2 * v[i]});
        g[2 * v[i] + 1].push_back({0, 2 * u[i] + 1});
        g[2 * v[i]].push_back({1, 2 * u[i] + 1});
        g[2 * u[i] + 1].push_back({1, 2 * v[i]});
        G[u[i]][0].push_back(v[i]);
        G[v[i]][1].push_back(u[i]);
    }
    struct dst {
        int rev, d;
        bool operator <(dst b) const {
            return make_pair(rev, d) < make_pair(b.rev, b.d);
        };
    };
    vector<dst> dist(2 * n, {1000000000, 0});
    dist[0] = {0, 0};
    set<pair<dst, int>> que = {{dist[0], 0}};
    while(!que.empty()) {
        int v = begin(que)->second;
        que.erase(begin(que));
        for(auto it: g[v]) {
            int c, u;
            tie(c, u) = it;
            dst nc = dist[v];
            nc.rev += c;
            nc.d++;
            if(nc < dist[u]) {
                que.erase({dist[u], u});
                dist[u] = nc;
                que.insert({dist[u], u});
            }
        }
    }
    auto cmp = [&](dst a, dst b) {
        if(a.rev < 30 && b.rev < 30) {
            return (1 << a.rev) + a.d - 1 < (1 << b.rev) + b.d - 1;
        } else {
            return make_pair(a.rev, a.d) < make_pair(b.rev, b.d);
        }
    };
    auto ans = min(dist[2 * (n - 1)], dist[2 * (n - 1) + 1], cmp);
    int dist2[n][22];
    memset(dist2, 0x3F, sizeof dist2);
    dist2[0][0] = 0;
    deque<pair<int, int>> que2 = {{0, 0}};
    while(!que2.empty()) {
        int c, v;
        tie(v, c) = que2.front();
        que2.pop_front();
        if(c + 1 < 22) {
            for(auto u: G[v][!(c % 2)]) {
                if(dist2[v][c] + 1 < dist2[u][c + 1]) {
                    dist2[u][c + 1] = dist2[v][c] + 1;
                    que2.emplace_back(u, c + 1);
                }
            }
        }
        for(auto u: G[v][(c % 2)]) {
            if(dist2[v][c] + 1 < dist2[u][c]) {
                dist2[u][c] = dist2[v][c] + 1;
                que2.emplace_back(u, c);
            }
        }
    }
    for(int z = 0; z < 22; z++) {
        if(dist2[n - 1][z] < 1e9 && cmp({z, dist2[n - 1][z]}, ans)) {
            ans = {z, dist2[n - 1][z]};
        }
    }
    cout << (bpow(2, ans.rev) + ans.d + mod - 1) % mod << endl;
}