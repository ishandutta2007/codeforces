#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200087;

struct Dsu {
    vector <int> rt, sz;
    int n, cc;
    Dsu () = default;
    Dsu (int _n) : n(_n), cc(_n) {
        rt.resize(n), iota(rt.begin(), rt.end(), 0);
        sz.assign(n, 1);
    }
    int Find(int v) {
        return rt[v] == v ? v : rt[v] = Find(rt[v]);
    }
    bool Union(int v, int u) {
        u = Find(u), v = Find(v);
        if (u == v)
            return false;
        if (sz[u] > sz[v])
            swap(u, v);
        rt[u] = v;
        sz[v] += sz[u];
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
};

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

void solve() {
    int n, m;
    cin >> n >> m;
    vector <pii> edge;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        edge.eb(u, v);
    }
    vector <int> ord(m);
    iota(all(ord), 0);
    while (true) {
        shuffle(all(ord), rng);
        string ans(m, '0');
        vector <pii> out;
        Dsu dsu(n);
        for (int i : ord) {
            int u, v; tie(u, v) = edge[i];
            if (!dsu.Union(u, v))
                out.eb(u, v);
            else
                ans[i] = '1';
        }
        if (out.size() == 3) {
            vector <int> V = {out[0].X, out[0].Y, out[1].X, out[1].Y, out[2].X, out[2].Y};
            sort(all(V)), V.resize(unique(all(V)) - V.begin());
            if (V.size() == 3) {
                continue;
            } else {
                cout << ans << '\n';
                break;
            }
        } else {
            cout << ans << '\n';
            break;
        }
    }
}

int main () {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}