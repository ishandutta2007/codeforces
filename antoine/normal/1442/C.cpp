#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;
const int mod = 998244353;
const int K = 20;

int n;
vector<int> adj1[MxN + 9];
vector<int> adj2[MxN + 9];

namespace NS1 {
    const int MxDist = (1 << K) + n;
    int dist[MxN + 9][K + 1];

    int f() {
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= K; ++j)
                dist[i][j] = MxDist + 1;

        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
        pq.emplace(dist[1][0] = 0, pii{1, 0});

        while (!pq.empty()) {
            const ll du = pq.top().first;
            const int u = pq.top().second.first;
            const int k = pq.top().second.second;
            // cerr << u << ' ' << k << ' ' << du << endl;
            if (u == n)
                return du;
            pq.pop();
            if (du != dist[u][k])
                continue;
            auto &&adj = k & 1 ? adj2 : adj1;

            for (const int v : adj[u]) {
                // DBG(v);
                if (dist[v][k] > dist[u][k] + 1 && dist[u][k] + 1 <= MxDist) {
                    dist[v][k] = dist[u][k] + 1;
                    pq.emplace(dist[v][k], pii{v, k});
                }
            }
            const int w = 1 << k;
            if (k < K && dist[u][k + 1] > dist[u][k] + w && dist[u][k] + w <= MxDist) {
                dist[u][k + 1] = dist[u][k] + w;
                pq.emplace(dist[u][k + 1], pii{u, k + 1});
            }
        }
        return -1;
    }
}

ll modPow(ll n, ll k) {
    ll res = 1;
    for (n %= mod; k; k >>= 1) {
        if (k & 1)
            res = res * n % mod;
        n = n * n % mod;
    }
    return res;
}

namespace NS2 {
    const ll MxDist = (ll) 1e18;
    ll dist[MxN + 9][2];

    int f() {
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= 1; ++j)
                dist[i][j] = MxDist + 1;

        priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<>> pq;
        pq.emplace(dist[1][0] = 0, pii{1, 0});

        while (!pq.empty()) {
            const ll du = pq.top().first;
            const int u = pq.top().second.first;
            const int k = pq.top().second.second;
            if (u == n) {
                ll ans = modPow(2, du / n) - 1 + du % n;
                return (ans % mod + mod) % mod;
            }
            pq.pop();
            if (du != dist[u][k])
                continue;
            auto &&adj = k & 1 ? adj2 : adj1;

            for (const int v : adj[u]) {
                if (dist[v][k] > dist[u][k] + 1 && dist[u][k] + 1 <= MxDist) {
                    dist[v][k] = dist[u][k] + 1;
                    pq.emplace(dist[v][k], pii{v, k});
                }
            }
            const int w = n;
            if (dist[u][k ^ 1] > dist[u][k] + w && dist[u][k] + w <= MxDist) {
                dist[u][k ^ 1] = dist[u][k] + w;
                pq.emplace(dist[u][k ^ 1], pii{u, k ^ 1});
            }
        }
        assert(false);
        return -1;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    int ans = NS1::f();
    if (ans != -1) {
        DBG("NS1");
        cout << ans;
        return 0;
    }
    DBG("NS2");
    ans = NS2::f();
    cout << ans;
    return 0;
}