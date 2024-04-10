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
const int mod = 1e9 + 7, N = 1e3 + 1, logN = 20, K = 111, M = N * 20, INF = 1e8;

struct edge {
    int u, v, w;
    bool operator < (const edge &e) {
        return w < e.w;
    }
};  

struct Dsu {
    int dsu[N], size[N], cc;
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
            size[i] = 1;
        }
        cc = n;
    }
    int Find(int v) {
        if (dsu[v] == v) return v;
        return dsu[v] = Find(dsu[v]);
    }
    bool Union(int v, int u) {
        int x = Find(v), y = Find(u);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        dsu[x] = y;
        size[y] += size[x];
        size[x] = 0;
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
} dsu;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <edge> E(m);
    vector <int> weight;
    for (int i = 0; i < m; ++i) {
        cin >> E[i].u >> E[i].v >> E[i].w, --E[i].u, --E[i].v;
        weight.pb(E[i].w);
    }
    sort(all(E));
    weight.pb(0), weight.pb(INF);
    for (int i = 0; i < m; ++i) for (int j = i + 1; j < m; ++j) {
        int x = E[j].w + E[i].w >> 1;
        if (x)
            weight.pb(x - 1);
        weight.pb(x);
        if (x + 1 < INF)
            weight.pb(x + 1);
    }
    sort(all(weight)), weight.resize(unique(all(weight)) - weight.begin());
    vector <pair <lli, int>> block;
    for (int i = 0; i + 1 < weight.size(); ++i) {
        sort(all(E), [&](edge a, edge b) {
            return abs(a.w - weight[i]) < abs(b.w - weight[i]);
        });
        dsu.init(n);
        lli resx = 0, resy = 0;
        for (auto &e : E) {
            if (dsu.Union(e.u, e.v)) {
                if (e.w <= weight[i])
                    resx -= e.w, resy++;
                else
                    resx += e.w, resy--;
            }
        }
        block.eb(resx, resy);
    }
    int fm, q, a, b, c;
    cin >> fm >> q >> a >> b >> c;
    int pre = 0;
    lli ans = 0;
    for (int i = 0; i < fm; ++i) {
        cin >> pre;
        int p = upper_bound(all(weight), pre) - weight.begin() - 1;
        lli res = block[p].X + 1ll * block[p].Y * pre;
        ans ^= res;
    }
    for (int i = fm; i < q; ++i) {
        pre = (1ll * pre * a + b) % c;
        int p = upper_bound(all(weight), pre) - weight.begin() - 1;
        lli res = block[p].X + 1ll * block[p].Y * pre;
        ans ^= res;
    }
    cout << ans << endl;
}