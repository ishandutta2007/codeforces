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
const int mod = 1e9 + 7, N = 200020, logN = 20, M = 6e6;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <int> a(m), b(m), p(n), in(m);
    vector <vector <int>> adj(n), newadj(m);
    for (int i = 0; i < n; ++i)
        cin >> p[i], --p[i];
    for (int i = 0; i < m; ++i)
        cin >> a[i] >> b[i], --a[i], --b[i], adj[a[i]].pb(i), adj[b[i]].pb(i);
    vector <int> vis(n, -1);
    for (int i = 0; i < n; ++i) if (vis[i] == -1) {
        int t = 0, now = i;
        vector <int> cc;
        while (vis[now] == -1)
            vis[now] = t++, cc.pb(now), now = p[now];
        for (int v : cc) {
            sort(all(adj[v]), [&](int i, int j) {
                int u1 = a[i] ^ b[i] ^ v, u2 = a[j] ^ b[j] ^ v;
                return (vis[v] < vis[u1] ? vis[u1] - vis[v] : vis[u1] - vis[v] + t) < (vis[v] < vis[u2] ? vis[u2] - vis[v] : vis[u2] - vis[v] + t);
            });
            test(adj[v]);
            for (int i = 1; i < adj[v].size(); ++i) {
                newadj[adj[v][i - 1]].pb(adj[v][i]), in[adj[v][i]]++;
            }
        }
    }
    queue <int> q;
    vector <int> ans;
    for (int i = 0; i < m; ++i) if (!in[i])
        q.push(i);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        ans.pb(v + 1);
        for (int u : newadj[v]) {
            in[u]--;
            if (!in[u])
                q.push(u);
        }
    }
    printv(all(ans));
}