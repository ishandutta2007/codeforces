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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 500005, logN = 20, K = 48763;

vector <pii> adj[N];
int to[N], in[N], out[N], dep[N], par[N], _t;
vector <int> idx[N];

void dfs(int v, int pa) {
    in[v] = _t++, par[v] = pa;
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    for (auto [u, c] : adj[v]) if (u != pa) {
        to[u] = c;
        idx[c].pb(u);
        dfs(u, v);
    }
    out[v] = _t++;
}

int main () {
    owo;
    int n;
    cin >> n;
    for (int i = 0, u, v, c; i < n - 1; ++i) {
        cin >> u >> v >> c, --u, --v, --c;
        adj[u].eb(v, c), adj[v].eb(u, c);
    }
    dfs(0, -1);
    lli ans = 0;
    for (int c = 0; c < n; ++c) {
        vector <int> pt = idx[c];
        sort(all(pt), [&](int i, int j) {
            return dep[i] > dep[j];
        });
        set <array <int, 3>> match;
        for (int v : pt) {
            int x = out[v] - in[v] + 1;
            for (auto it = match.lower_bound({in[v], -1, -1}); it != match.end() && (*it)[1] <= out[v]; ++it) {
                x -= (*it)[1] - (*it)[0];
            }
            x >>= 1;
            for (auto it = match.lower_bound({in[v], -1, -1}); it != match.end() && (*it)[1] <= out[v]; ) {
                ans += 1ll * (*it)[2] * x;
                match.erase(it);
                it = match.lower_bound({in[v], -1, -1});
            }
            match.insert({in[v], out[v] + 1, x});
        }
        int x = 2 * n;
        for (auto A : match)
            x -= A[1] - A[0];
        x >>= 1;
        for (auto A : match)
            ans += 1ll * A[2] * x;
    }
    cout << ans << '\n';
}