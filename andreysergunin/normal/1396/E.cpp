#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = double; 
// using ld = __float128;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;
 
    int tests = 1;
    // cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

const int MAXN = 100100;
vector<int> g[MAXN];
int w[MAXN];

int dfs(int v, int p = -1) {
    w[v] = 1;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        w[v] += dfs(u, v);
    }
    return w[v];
};

int c0[MAXN], c1[MAXN];
int col = 0;

int pairMin(int v, int p = -1) {
    int x = v;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        int y = pairMin(u, v);
        if (x != -1 && y != -1) {
            c0[x] = col++;
            c0[y] = col++;
            x = y = -1;
        }
        x = max(x, y);
    }
    return x;
}

void get(int v, int p, vector<int> &arr) {
    arr.push_back(v);
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        get(u, v, arr);
    }
}

void pairMax(int n) {
    col = 0;
    int cen = -1;
    for (int v = 0; v < n; ++v) {
        if (2 * w[v] >= n) {
            bool ok = true;
            for (int u : g[v]) {
                if (w[u] < w[v]) {
                    ok &= 2 * w[u] <= n;
                }
            }
            if (ok) {
                cen = v;
            }
        }
    }
    vector<vector<int>> s;
    for (int u : g[cen]) {
        s.push_back({});
        get(u, cen, s.back());
    }
    s.push_back({cen});

    set<pii> setik;
    for (int i = 0; i < sz(s); ++i) {
        setik.insert({-sz(s[i]), i});
    }

    while (!setik.empty()) {
        assert(sz(setik) > 1);

        auto v = vector{setik.begin(), ++setik.begin()};

        for (auto it : v) {
            int i = it->second;
            c1[s[i].back()] = col++;
            s[i].pop_back();
            setik.erase(it);
            if (sz(s[i]) > 0) {
                setik.insert({-sz(s[i]), i});
            }
        }
    }
}

const int MAXL = 17;

int up[MAXN][MAXL];
int tin[MAXN], tout[MAXN];
int timer = 0;
int d[MAXN];

void dfsShifts(int v, int p = -1, int depth = 0) {
    tin[v] = timer++;
    d[v] = depth;
    up[v][0] = (p == -1 ? v : p);
    for (int l = 1; l < MAXL; ++l) {
        up[v][l] = up[up[v][l - 1]][l - 1];
    }
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        dfsShifts(u, v, depth + 1);
    }
    tout[v] = timer++;
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
    // cerr << u << " " << v << " ";
    if (anc(v, u)) {
        // cerr << "!" << v << endl;
        return v;
    }
    for (int l = MAXL - 1; l >= 0; --l) {
        if (!anc(up[v][l], u)) {
            v = up[v][l];
        }
    }
    // cerr << up[v][0] << endl;
    return up[v][0];
}

int dst(int v, int u) {
    return d[v] + d[u] - 2 * d[lca(u, v)];
}

int mat[MAXN][2];

ll swp(int v, int u) { 
    // if (c0[u] / 2 == c0[v] / 2) {
    //     swap(c0[u], c0[v]);
    //     mat[c0[u] / 2][c0[u] & 1] = u;
    //     mat[c0[v] / 2][c0[v] & 1] = v;
    //     return 0;
    // }

    ll delta = 0;
    delta -= dst(mat[c0[u] / 2][0], mat[c0[u] / 2][1]);
    delta -= dst(mat[c0[v] / 2][0], mat[c0[v] / 2][1]);
    
    // cerr << mat[c0[u] / 2][0] + 1 << " " << mat[c0[u] / 2][1] + 1 << endl;
    // cerr << mat[c0[v] / 2][0] + 1 << " " << mat[c0[v] / 2][1] + 1 << endl;
    // cerr << delta << endl;

    swap(c0[u], c0[v]);
    mat[c0[u] / 2][c0[u] & 1] = u;
    mat[c0[v] / 2][c0[v] & 1] = v;

    delta += dst(mat[c0[u] / 2][0], mat[c0[u] / 2][1]);
    delta += dst(mat[c0[v] / 2][0], mat[c0[v] / 2][1]);

    // cerr << mat[c0[u] / 2][0] + 1 << " " << mat[c0[u] / 2][1] + 1 << endl;
    // cerr << mat[c0[v] / 2][0] + 1 << " " << mat[c0[v] / 2][1] + 1 << endl;
    // cerr << delta << endl << endl;

    return delta;
}

bool getPath(int v, int w, vector<int> &path, int p = -1) {
    if (v == w) {
        path.push_back(v);
        return true;
    }
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        if (getPath(u, w, path, v)) {
            path.push_back(v);
            return true;
        }
    }
    return false;
}

void solve() {      
    int n;;
    ll k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    ll minn = 0, maxx = 0;

    for (int i = 1; i < n; ++i) {
        minn += w[i] & 1;
        maxx += min(w[i], n - w[i]);
    }

    if (k < minn || maxx < k || ((maxx - k) & 1)) {
        cout << "NO" << endl;
        return;
    } 
    cout << "YES" << endl;

    pairMin(0);
    pairMax(n);

    // for (int i = 0; i < n; ++i) {
    //     cerr << c0[i];
    // }
    // cerr << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << c1[i];
    // }
    // cerr << endl;


    ll cur = minn;

    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        q[c1[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        mat[c0[i] / 2][c0[i] & 1] = i;
    }

    pii last = {-1, -1};
    
    dfsShifts(0);

    bool flag = true;

    for (int i = 0; i < n; ++i) {
        while (c0[i] != c1[i]) {
            int a = i, b = q[c0[i]];
            ll add = swp(a, b);
            // cerr << a << " " << b << " " << add << endl;
            if (cur + add > k)  {
                swp(a, b);
                last = {a, b};
                flag = false;
                break;
            } else {
                cur += add;
            }
        }
        if (!flag) {
            break;
        }
    }

    if (last != pii{-1, -1}) {
        auto [u, v] = last;
        vector<int> path;
        getPath(v, u, path);
        reverse(all(path));

        for (int i = 0; i < sz(path) - 1; ++i) {
            if (cur != k) {
                cur += swp(path[i], path[i + 1]);
            }
        }
        for (int i = sz(path) - 3; i >= 0; --i) {
            if (cur != k) {
                cur += swp(path[i], path[i + 1]);
            }
        }
    }

    for (int i = 0; i < n / 2; ++i) {
        cout << mat[i][0] + 1 << " " << mat[i][1] + 1 << endl;
    }
}