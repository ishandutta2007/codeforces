#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

struct Segtree {
private:
    int n;
    vector <pii> tr;
    pii neutral_tr = {INT_MAX, 0};

    pii merge(pii a, pii b) {
        if (a.fs < b.fs)
            return a;
        else 
            return b;
    }

    void build(const vector <pii>& a) {
        forn (i, 0, n) 
            tr[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    Segtree(const vector <pii>& a) {
        n = sz(a);
        tr.resize(2 * n, neutral_tr);
        build(a);
    }

    pii get(int l, int r) {
        pii ans = neutral_tr;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2)
                ans = merge(ans, tr[l++]);
            if (r % 2)
                ans = merge(ans, tr[--r]);
        }
        return ans;
    }
};

vector <int> first, h;
vector <pii> euler;

void dfs(int v, int p, int cur_h, const vector <vector <int>>& gr) {
    if (p != -1)
        h[v] = h[p] + 1;
    first[v] = sz(euler);
    euler.eb(cur_h, v);
    for (int u : gr[v]) {
        if (u != p) {
            dfs(u, v, cur_h + 1, gr);
            euler.eb(cur_h, v);
        }
    }
}

int lca(int v, int u, Segtree& a) {
    if (first[v] > first[u])
        swap(v, u);
    return a.get(first[v], first[u] + 1).sc;
}

vector <vector <int>> gr;


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    gr.resize(n);
    forn (i, 1, n) {
        int v;
        cin >> v, v--;
        gr[i].pb(v), gr[v].pb(i);
    }
    first.resize(n), h.resize(n);
    dfs(0, -1, 0, gr);
    Segtree tr(euler);
    while (q --> 0) {
        int a, b, c;
        cin >> a >> b >> c, a--, b--, c--;
        int x = h[a] + h[b] - 2 * h[lca(a, b, tr)], y = h[b] + h[c] - 2 * h[lca(b, c, tr)], z = h[c] + h[a] - 2 * h[lca(c, a, tr)];
        cout << (x + y + z - 2 * min({x, y, z})) / 2 + 1 << "\n";
    }
    return 0;
}