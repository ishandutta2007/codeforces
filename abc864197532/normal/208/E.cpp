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
const int mod = 1e9 + 7, N = 1e5 + 87, logN = 20, K = 111, M = N * 20;

vector <int> adj[N], block[N];
int in[N], out[N], dep[N], rt[N], jump[N][logN], _t;

void dfs(int v, int pa) {
    in[v] = _t++;
    block[dep[v]].pb(in[v]);
    jump[v][0] = pa;
    for (int i = 1; i < logN; ++i) {
        int k = jump[v][i - 1];
        if (k == -1)
            jump[v][i] = k;
        else
            jump[v][i] = jump[k][i - 1];
    }
    for (int u : adj[v]) if (u != pa) 
        dep[u] = dep[v] + 1, dfs(u, v);
    out[v] = _t++;
    block[dep[v]].pb(out[v]);
}

int get(int v, int k) {
    if (dep[v] < k)
        return -1;
    for (int i = logN - 1; ~i; --i) if (k >> i & 1)
        v = jump[v][i];
    return v;
}

int main () {
    owo;
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> rt[i];
        if (rt[i])
            adj[rt[i] - 1].pb(i);
    }
    for (int i = 0; i < n; ++i) if (!rt[i]) {
        dfs(i, -1);
    }
    cin >> q;
    while (q--) {
        int v, k;
        cin >> v >> k, --v;
        int u = get(v, k);
        if (u == -1)
            cout << 0 << ' ';
        else {
            int x = upper_bound(all(block[dep[v]]), out[u]) - lower_bound(all(block[dep[v]]), in[u]);
            assert(x % 2 == 0);
            cout << x / 2 - 1 << ' ';
        }
    }
    cout << endl;
}