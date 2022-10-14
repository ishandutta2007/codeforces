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
const int mod = 1e9 + 7, N = 300001, logN = 20, C = 350;

vector <int> adj[N], newadj[N];
int col[N], sz[N], par[N];

void dfs(int v, int pa) {
    sz[v] = col[v];
    par[v] = pa;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        sz[v] += sz[u];
    }
}

int main () {
    owo;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> col[i];
    int cnt = count(col, col + n, 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    for (int i = 1; i < n; ++i) {
        int p = par[i];
        // p -> i
        if (sz[i] >= 2 || col[i]) {
            newadj[i].pb(p);
        }
        // i -> p
        if (cnt - sz[i] >= 2 || col[p]) {
            newadj[p].pb(i);
        }
    }
    vector <bool> ans(n, false);
    queue <int> q;
    for (int i = 0; i < n; ++i) if (col[i])
        ans[i] = true, q.push(i);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : newadj[v]) if (!ans[u]) {
            ans[u] = true;
            q.push(u);
        }
    }
    printv(all(ans));
}