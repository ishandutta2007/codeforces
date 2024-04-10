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

vector <int> adj[N];

int main () {
    owo;
    int n;
    cin >> n;
    vector <array <int, 3>> edge;
    for (int i = 0, u, v, w; i < n - 1; ++i) {
        cin >> u >> v >> w, --u, --v;
        adj[u].pb(v), adj[v].pb(u), edge.pb({u, v, w});
    }
    for (int i = 0; i < n; ++i) if (adj[i].size() == 2) {
        cout << "NO\n";
        return 0;
    }
    if (n == 2) {
        cout << "YES\n1\n";
        cout << edge[0][0] + 1 << ' ' << edge[0][1] + 1 << ' ' << edge[0][2] << endl;
        return 0;
    }
    function <int(int, int)> dfs = [&](int v, int pa) {
        for (int u : adj[v]) if (u != pa) {
            return dfs(u, v);
        }
        return v;
    };
    cout << "YES\n" << (n - 1) * 4 << endl;
    for (auto i : edge) {
        int u = i[0], v = i[1], w = i[2];
        vector <int> a, b;
        for (int k : adj[u]) if (k != v)
            a.pb(dfs(k, u));
        for (int k : adj[v]) if (k != u)
            b.pb(dfs(k, v));
        if (a.empty())
            a.pb(u);
        if (b.empty())
            b.pb(v);
        if (a.size() >= 2 && b.size() >= 2) {
            cout << a[0] + 1 << ' ' << b[0] + 1 << ' ' << w / 2 << endl;
            cout << a[1] + 1 << ' ' << b[1] + 1 << ' ' << w / 2 << endl;
            cout << a[0] + 1 << ' ' << a[1] + 1 << ' ' << -w / 2 << endl;
            cout << b[0] + 1 << ' ' << b[1] + 1 << ' ' << -w / 2 << endl;
        } else {
            if (a.size() > b.size())
                swap(a, b);
            assert(a.size() == 1 && b.size() > 1);
            cout << a[0] + 1 << ' ' << b[0] + 1 << ' ' << w / 2 << endl;
            cout << a[0] + 1 << ' ' << b[1] + 1 << ' ' << w / 2 << endl;
            cout << b[0] + 1 << ' ' << b[1] + 1 << ' ' << -w / 2 << endl;
            cout << b[0] + 1 << ' ' << b[1] + 1 << ' ' << 0 << endl;
        }
    }
}