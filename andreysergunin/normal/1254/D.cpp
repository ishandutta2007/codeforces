#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
const int P = 998244353;
 
void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}
 
void mul(int &a, int b) {
    a = ll(a) * b % P; 
}
 
void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
}
 
int binPow(int a, int b) {
    int res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) {
            mul(res, a);
        }
        mul(a, a);
    }
    return res;
}
 
const int MAXN = 500500;
 
int n, q;
vector<int> g[MAXN];
int w[MAXN];
int res[MAXN];
int tin[MAXN];
int tout[MAXN];
 
int to_change[MAXN];
 
int timer = 0;
 
int dfs(int v, int p = -1) {
    tin[v] = timer++;
    w[v] = 1;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (g[v][i] == p) {
            swap(g[v][i], g[v].back());
            g[v].pop_back();
            break;
        }
    }
    for (int u : g[v]) {
        w[v] += dfs(u, v);
    }
    tout[v] = timer++;
    return w[v];
}
 
int get(int v, int u, int d) {
    if (v == u) {
        return 0;
    }
 
    if (!(tin[u] < tin[v] && tout[v] < tout[u])) {
        int cur = d;
        mul(cur, n - w[u]);
        return cur;
    }
 
    int lf = 0, rg = sz(g[u]);
    while (rg - lf > 1) {
        int mid = (lf + rg) / 2;
        if (tin[g[u][mid]] <= tin[v]) {
            lf = mid;
        } else {
            rg = mid;
        }
    }   
    int cur = d;
    mul(cur, w[g[u][lf]]);
    return cur;
}
 
 
void bfs() {
    queue<pii> q;
    q.push({0, 0});
 
    while (!q.empty()) {
        auto [v, x] = q.front();
        q.pop();
        add(res[v], x);
        for (int u : g[v]) {
            int y = to_change[v];
            mul(y, w[u] - n + w[v] + P);
            add(y, x);
            q.push({u, y});
        }
        int y = to_change[v];
        mul(y, n - w[v]);
        sub(res[v], y);
    }
}
 
void solve() {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int cur = n - w[i];
        mul(cur, to_change[i]);
        add(sum, cur);
    }
    for (int i = 0; i < n; ++i) {
        res[i] = sum; 
    }
    
    bfs();
}
 
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  
 
    cin >> n >> q;
 
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        // u = i + 2;
        // v = rnd() % (i + 1) + 1;
 
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dfs(0);
 
    int block = 1000;
 
    int sum = 0;
 
    vector<pii> queries;
    int rn = binPow(n, P - 2);
    int x = rn;
    mul(x, n);
 
    for (int t = 0; t < q; ++t) {
        int type;
        cin >> type;
        // type = rnd() % 2 + 1;
        // type = (t < block - 1 ? 1 : 2);
        // type = 1;
 
        if (type == 1) {
            int v, d;
            cin >> v >> d;
            // v = rnd() % n + 1;
            // d = 1;
 
            add(sum, d);
            --v; 
            queries.push_back({v, d});
        } else {
            int v;
            cin >> v;
            // v = rnd() % n + 1;
 
            --v;
            int cur = sum;
            mul(cur, n);
            sub(cur, res[v]);
 
            for (auto p : queries) {
                sub(cur, get(v, p.first, p.second));
            }
 
            mul(cur, rn);
            cout << cur << '\n';
        }
 
        if (sz(queries) == block) {
            for (auto p : queries) {
                add(to_change[p.first], p.second);
            }
            queries.clear();
            solve();
        }
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}