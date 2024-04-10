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
const int mod = 998244353, N = 100005, logN = 20, M = 6e6;

int main () {
    owo;
    int n, x;
    cin >> n >> x, --x;
    vector <vector <int>> adj(n);
    for (int i = 0, u, v; i < n - 1; ++i)
        cin >> u >> v, --u, --v, adj[u].pb(v), adj[v].pb(u);
    queue <pii> q;
    vector <int> vis(n, -1);
    vector <int> dis(n, -1);
    int cnt0 = 1, ans = 0;
    q.push({x, 0}), q.push({0, 1}), dis[0] = 0, vis[x] = 0, vis[0] = 1;
    while (!q.empty()) {
        int v, d;
        tie(v, d) = q.front(); q.pop();
        test(v, d);
        if (!cnt0)
            break;
        for (int u : adj[v]) {
            if (d == 1 && dis[u] == -1) {
                dis[u] = dis[v] + 1;
            }
            if (d == 1 && vis[u] != 1)
                cnt0 -= (vis[u] == 0), ans = max(ans, dis[u]), vis[u] = 1, q.push({u, 1});
            if (d == 0 && vis[u] == -1)
                vis[u] = 0, q.push({u, 0}), cnt0++;
        }
    }
    cout << ans * 2 << endl;
}