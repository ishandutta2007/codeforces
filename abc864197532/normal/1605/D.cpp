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
const int mod = 998244353, N = 52, logN = 20, K = 111;

void solve() {
    int n;
    cin >> n;
    vector <vector <int>> adj(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    vector <int> c(n, 0);
    function<void(int, int)> dfs = [&](int v, int pa) {
        for (int u : adj[v]) if (u != pa) {
            c[u] = c[v] ^ 1;
            dfs(u, v);
        }
    };
    dfs(0, -1);
    int f = 0;
    if (count(all(c), 1) * 2 < n) 
        f = 1;
    int cnt = count(all(c), f);
    vector <int> res, oth;
    for (int b = 0; b < 18; ++b) if ((1 << b) <= n) {
        if (cnt >> b & 1) {
            for (int i = 1 << b; i < min(1 << b + 1, n + 1); ++i) {
                res.pb(i);
            }
        } else {
            for (int i = 1 << b; i < min(1 << b + 1, n + 1); ++i) {
                oth.pb(i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (c[i] == f) {
            cout << res.back() << ' ';
            res.pop_back();
        } else {
            cout << oth.back() << ' ';
            oth.pop_back();
        }
    }
    cout << endl;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}