#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1600087, logN = 19, K = 111, M = 1000006, C = 500;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <vector <int>> adj(n);
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v, --u, --v;
            adj[u].pb(v), adj[v].pb(u);
        }
        vector <int> col(n, -1), tag(n), dep(n);
        int badcnt = 0, flip = 0;
        function <void(int, int)> dfs1 = [&](int v, int pa) {
            dep[v] = ~pa ? dep[pa] + 1 : 0;
            col[v] = ~pa ? col[pa] ^ 1 : 0;
            for (int u : adj[v]) if (u != pa) {
                if (col[u] == -1) {
                    dfs1(u, v);
                } else if (dep[u] < dep[v]) {
                    if (col[u] == col[v])
                        tag[u]--, tag[v]++, badcnt++, flip = (col[u] == 0);
                    else
                        tag[u]++, tag[v]--;
                }
            }
        };
        dfs1(0, -1);
        if (badcnt == 0) {
            cout << "YES\n";
            for (int i : col)
                cout << i;
            cout << '\n';
        } else if (badcnt == 1) {
            cout << "YES\n";
            for (int i : col)
                cout << (i ^ flip);
            cout << '\n';
        } else {
            vector <bool> vis(n, false);
            vector <int> in(n), out(n);
            int _t = 0;
            function <void(int, int)> dfs2 = [&](int v, int pa) {
                vis[v] = true, in[v] = _t++;
                for (int u : adj[v]) if (u != pa) {
                    if (!vis[u])
                        dfs2(u, v), tag[v] += tag[u];
                }
                out[v] = _t++;
            };
            dfs2(0, -1);
            int found = -1;
            for (int i = 1; i < n; ++i) if (tag[i] == badcnt) {
                found = i;
                break;
            }
            auto anc = [&](int u, int v) {
                return in[u] <= in[v] && out[u] >= out[v];
            };
            if (found != -1) {
                cout << "YES\n";
                flip = col[found] == 1;
                for (int i = 0; i < n; ++i)
                    cout << (col[i] ^ flip ^ anc(found, i));
                cout << '\n';
            } else {
                cout << "NO\n";
            }
        }
    }
}