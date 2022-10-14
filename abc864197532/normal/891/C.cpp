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
const int mod = 998244353, N = 1 << 19;

vector <int> E[N];
vector <pii> Q[N];

int dsu[N], sz[N], u[N], v[N], w[N];

int Find(int x) {
    if (dsu[x] == x)
        return x;
    return Find(dsu[x]);
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v)
        return;
    if (sz[u] > sz[v])
        swap(u, v);
    dsu[u] = v;
    sz[v] += sz[u];
}

int main () {
    owo;
    int n, m, q;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> w[i], --u[i], --v[i];
        E[w[i]].pb(i);
    }
    iota(dsu, dsu + n, 0);
    fill(sz, sz + n, 1);
    cin >> q;
    for (int i = 0, sz; i < q; ++i) {
        cin >> sz;
        for (int j = 0, x; j < sz; ++j) {
            cin >> x, --x;
            Q[w[x]].eb(i, x);
        }
    }
    vector <bool> ans(q, true);
    for (int cur_w = 1; cur_w < N; ++cur_w) {
        for (int i = 0, j = 0; i < Q[cur_w].size(); i = j) {
            int id = Q[cur_w][i].X;
            vector <pii> upd;
            auto add = [&](int x) {
                x = Find(x);
                upd.eb(x, sz[x]);
            };
            while (j < Q[cur_w].size() && Q[cur_w][j].X == id) {
                int x = Q[cur_w][j].Y;
                add(u[x]), add(v[x]);
                j++;
            }
            for (int k = i; k < j; ++k) {
                int x = Q[cur_w][k].Y;
                if (Find(u[x]) == Find(v[x]))
                    ans[id] = false;
                Union(u[x], v[x]);
            }
            for (auto [v, s] : upd)
                sz[v] = s, dsu[v] = v;
        }
        for (int i : E[cur_w])
            Union(u[i], v[i]);
    }
    for (bool i : ans)
        cout << (i ? "YES\n" : "NO\n");
}