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

vector <set <int>> gr;

pii find_most_distant(int v, int p) {
    pii ans = {0, v};
    for (int u : gr[v]) {
        if (u == p)
            continue;
        pii tmp = find_most_distant(u, v);
        if (tmp.fs > ans.fs)
            ans = tmp;
    } 
    //cout << v << ": " << ans.fs << " " << ans.sc << "\n";
    return {ans.fs + 1, ans.sc};
}

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

vector <int> h, first;
vector <pii> euler;

void dfs(int v, int p, int cur_h, const vector <set <int>>& gr) {
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

int dst(int v, int u, Segtree& a) {
    return h[v] + h[u] - 2 * h[lca(v, u, a)];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr.resize(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].insert(u), gr[u].insert(v);
    }
    int x = find_most_distant(0, -1).sc;
    int y = find_most_distant(x, -1).sc;
    //cout << x << " " << y << '\n';
    first = h = vector <int> (n);
    dfs(0, -1, 0, gr);
    Segtree tr(euler);
    vector <int> leaves;
    forn (i, 0, n) 
        if (sz(gr[i]) == 1 && i != x && i != y)
            leaves.pb(i);
    ll ans_val = 0;
    vector <vector <int>> ans;
    while (!leaves.empty()) {
        int v = leaves.back();
        leaves.pop_back();
        int tmp1 = dst(v, x, tr), tmp2 = dst(v, y, tr);
        if (tmp1 > tmp2) 
            ans.pb({v, x, v});
        else 
            ans.pb({v, y, v});
        //cout << tmp1 << " " << "\n";
        ans_val += max(tmp1, tmp2);
        if (sz(gr[*gr[v].begin()]) == 2)
            leaves.pb(*gr[v].begin());
        gr[*gr[v].begin()].erase(v);
        gr[v].erase(*gr[v].begin());
    } 
    leaves.pb(x);
    while (!leaves.empty()) {
        int v = leaves.back();
        leaves.pop_back();
        if (v == y)
            break;
        ans.pb({v, y, v});
        ans_val += dst(v, y, tr);
        if (sz(gr[*gr[v].begin()]) == 2)
            leaves.pb(*gr[v].begin());
        gr[*gr[v].begin()].erase(v);
        gr[v].erase(*gr[v].begin());
    } 
    cout << ans_val << "\n";
    for (auto i : ans)
        cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] + 1 << "\n";
    return 0;
}