#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <vector <int>> gr;
vector <int> first;
vector <pii> h;

vector <int> height;

void dfs(int v, int cur = 0, int p = -1) {
    if (p != -1)
        height[v] = height[p] + 1;
    first[v] = h.size();
    h.eb(cur, v);
    for (int u : gr[v]) {
        if (u == p)
            continue;
        dfs(u, cur + 1, v);
        h.eb(cur, v);
    }
}

template <typename T>
class SparseTable {
private:
    int n, logn;

    vector <vector <T>> table;
    vector <int> lg;

public:
    SparseTable(const vector <T>& a = vector <T> ()) : n(a.size()) {
        lg.resize(n + 1);
        forn (i, 2, n + 1)
            lg[i] = lg[i / 2] + 1;
        logn = lg[n] + 1;

        table.resize(n, vector <T> (logn));
        forn (i, 0, n)
            table[i][0] = a[i];
        forn (j, 1, logn)
            for (int i = 0; i + (1 << j) < n; ++i)
                table[i][j] = min(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
    }

    //[l, r)
    T get(int l, int r) {
        int p = lg[r - l];
        return min(table[l][p], table[r - (1 << p)][p]);
    }
};

SparseTable <pii> t;

int lca(int v, int u) {
    if (first[v] > first[u])
        swap(v, u);
    return t.get(first[v], first[u] + 1).sc;
}

int dst(int v, int u) {
    return height[v] + height[u] - 2 * height[lca(v, u)];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr.resize(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].pb(u), gr[u].pb(v);
    }
    first.resize(n);
    height.resize(n);
    dfs(0);
    t = SparseTable <pii> (h);
    int q;
    cin >> q;
    while (q --> 0) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k, x--, y--, a--, b--;
        int t = dst(a, b);
        if (k >= t && k % 2 == t % 2) {
            cout << "YES\n";
            continue;
        }
        t = dst(a, x) + 
            1 +
            dst(y, b);
        if (k >= t && k % 2 == t % 2) {
            cout << "YES\n";
            continue;
        }
        t = dst(a, y) + 
            1 +
            dst(x, b);
        if (k >= t && k % 2 == t % 2) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}