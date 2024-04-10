#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;
typedef pair<ll, int> pli;

const int M = 2017;
const int inf = 2e9;
const ll infl = 1e18;

int n;
ll a[M][M];
ll s[M];
ll f[M];
ll d[M];
ll mn = inf;
bool g[M];
vector<ll> G[M], W[M];

void read() {
    //cin >> n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; i + j < n; ++j) {
            int w;
            scanf("%d", &w);
            //cin >> w;
            int u = i, v = i + j;
            a[u][v] = a[v][u] = w;
            mn = min<ll>(mn, w);
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] -= mn;

    for (int i = 0; i < n; ++i)
        a[i][i] = 0;
}

void add(int u, int v, ll c) {
    G[u].push_back(v);
    G[v].push_back(u);

    W[v].push_back(c);
    W[u].push_back(c);
}


priority_queue<pli, vector<pli>, greater<pli>> q;
bool u[M];

void dickstra(int v) {
    fill(d, d + n, infl);
    d[v] = 0;
    q.emplace(0ll, v);

    while (!q.empty()) {
        auto p = q.top();
        q.pop();

        int v = p.second;
        if (u[v])
            continue;

        u[v] = true;

        for (int i = 0; i < (int) G[v].size(); ++i) {
            int to = G[v][i];
            ll w = W[v][i];
            if (d[to] > d[v] + w) {
                d[to] = d[v] + w;
                q.emplace(d[to], to);
            }
        }

    }
}

void kill() {
    fill(f, f + n, inf);
    fill(s, s + n, inf);

    for (int v = 0; v < n; ++v) {
        for (int u = 0; u < n; ++u) {
            if (u == v)
                continue;
            if (!a[v][u]) {
                g[v] = true;
                f[v] = 0;
            }
            s[v] = min(s[v], a[v][u]);
        }
    }

    for (int v = 0; v < n; ++v) 
        for (int u = 0; u < n; ++u)
            if (g[u])
                f[v] = min(f[v], a[v][u]);

    int T = n;
    for (int v = 0; v < n; ++v)
        if (g[v])
            add(v, T, 0);

    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
            add(u, v, a[u][v]);

    for (int u = 0; u < n; ++u)
        add(u, T, 2 * s[u]);

    ++n;
    dickstra(T);

    
    for (int v = 0; v < n - 1; ++v) {
        cout << d[v] + (n - 2) * mn << "\n";
    }
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  //ios_base::sync_with_stdio(false);

  read();
  kill();
}