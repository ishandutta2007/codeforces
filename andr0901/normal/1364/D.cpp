//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <vector <int>> gr;
vector <int> h, par;

int k;

const int INF = 1e9;

void dfs1(int v, int p = -1) {
    par[v] = p;
    if (p == -1)
        h[v] = 0;
    else
        h[v] = h[p] + 1;
    for (int u : gr[v]) {
        if (u == p)
            continue;
        if (h[u] == INF)
            dfs1(u, v);
    }
}

void dfs(int v, int p = -1) {
    vector <int> neighbours;
    for (int u : gr[v])
        if (u != p && h[u] < h[v])
            neighbours.pb(u);
    sort(rall(neighbours), [&](int a, int b) {
        return h[a] < h[b];
    });
    for (int u : neighbours) {
            int len = h[v] - h[u] + 1;
            if (len <= 2)
                continue;
            cerr << len << " " << v << " " << u << "\n";
            vector <int> cycle;
            int i = v;
            while (i != u) {
                cycle.pb(i);
                i = par[i];
            }
            cycle.pb(u);
            if (len > k) {
                cout << "1\n";
                int j = 0;
                forn (cnt, 0, (k + 1) / 2) {
                    cout << cycle[j] + 1 << " ";
                    j += 2;
                }
            } else {
                cout << "2\n" << sz(cycle) << "\n";
                for (int x : cycle)
                    cout << x + 1 << " ";
            }
            exit(0);
    }
    for (int u : gr[v])
        if (h[u] > h[v])
            dfs(u, v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m >> k;
    gr.resize(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    par.resize(n, -1), h.resize(n, INF);
    dfs1(0);
    dfs(0);
    vector <vector <int>> levels(2);
    forn (i, 0, n)
        levels[h[i] % 2].pb(i);
    cout << "1\n";
    forn (i, 0, 2) {
        if (levels[i].size() >= (k + 1) / 2) {
            forn (j, 0, (k + 1) / 2)
                cout << levels[i][j] + 1 << " ";
            return 0;
        }
    }
    return 0;
}