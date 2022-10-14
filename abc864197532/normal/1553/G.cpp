/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1000002, M = 150000, logN = 20, K = 1000;

vector <int> p[N];

struct Dsu {
    int dsu[N + M], size[N + M], n, cc;
    Dsu (int _n = N + M) : n(_n), cc(_n) {
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
            size[i] = 1;
        }
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
    for (int i = 2; i < N; ++i) if (p[i].empty()) {
        for (int j = i; j < N; j += i) p[j].pb(i);
    }
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j : p[a[i]]) {
            dsu.Union(N + i, j);
        }
    }
    set <pii> s;
    auto add = [&](int u, int v) {
        if (u == v) return;
        if (u > v) swap(u, v);
        s.insert(mp(u, v));
    };
    auto query = [&](int u, int v) {
        if (u > v) swap(u, v);
        return s.count(mp(u, v));
    };
    for (int i = 0; i < n; ++i) {
        for (int j : p[a[i] + 1]) {
            add(dsu.Find(i + N), dsu.Find(j));
        }
        for (int j : p[a[i] + 1]) for (int k : p[a[i] + 1]) {
            add(dsu.Find(j), dsu.Find(k));
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v, --u, --v;
        u += N, v += N;
        if (dsu.same(u, v)) cout << 0 << endl;
        else if (query(dsu.Find(u), dsu.Find(v))) cout << 1 << endl;
        else cout << 2 << endl;
    }
}