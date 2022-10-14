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
const int mod = 1e9 + 7, N = 200087, logN = 20, K = 350;

struct LinearBasis {
    vector <int> basis;
    stack <int> move, pt;
    LinearBasis () {
        basis.resize(30, 0);
    }
    void add(int v) {
        for (int i = 29; ~i; --i) if (v >> i & 1) {
            if (!basis[i]) {
                move.push(i);
                basis[i] = v;
                return;
            }
            v ^= basis[i];
        }
    }
    int query(int v) {
        for (int i = 29; ~i; --i) if (v >> i & 1) {
            if (basis[i]) {
                v ^= basis[i];
            }
        }
        return v;
    }
    void add_point() {
        pt.push(move.size());
    }
    void rollback() {
        while (move.size() > pt.top()) {
            int i = move.top(); move.pop();
            basis[i] = 0;
        }
        pt.pop();
    }
} LB;

struct Dsu {
    struct op {
        int u, v, szv;
    };
    int root[N], weight[N], sz[N];
    stack <int> pt;
    stack <op> move;
    Dsu () {
        for (int i = 0; i < N; ++i) root[i] = i, sz[i] = 1;
    }
    int find_root(int v) {
        if (root[v] == v) return v;
        return find_root(root[v]);
    }
    int find_weight(int v) {
        if (root[v] == v) return 0;
        return find_weight(root[v]) ^ weight[v];
    }
    void add_edge(int u, int v, int w) {
        int U = find_root(u), V = find_root(v);
        if (U == V) {
            LB.add(find_weight(u) ^ find_weight(v) ^ w);
        } else {
            if (sz[U] > sz[V]) swap(U, V);
            move.push({U, V, sz[V]});
            root[U] = V;
            weight[U] = find_weight(u) ^ find_weight(v) ^ w;
            sz[V] += sz[U];
        }
    }
    void add_point() {
        pt.push(move.size());
    }
    void rollback() {
        while (move.size() > pt.top()) {
            op A = move.top(); move.pop();
            root[A.u] = A.u;
            weight[A.u] = 0;
            sz[A.v] = A.szv;
        }
        pt.pop();
    }
} dsu;

pii Q[N];

struct Seg {
    struct edge {
        int u, v, w;
    };
    int l, r, m;
    vector <edge> E;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void add_event(int a, int b, int u, int v, int w) {
        if (a <= l && r <= b) E.pb({u, v, w});
        else {
            if (a < m) ch[0]->add_event(a, b, u, v, w);
            if (m < b) ch[1]->add_event(a, b, u, v, w);
        }
    }
    void travelsal() {
        dsu.add_point();
        LB.add_point();
        for (edge &e : E) {
            dsu.add_edge(e.u, e.v, e.w);
        }
        if (r - l == 1) {
            if (Q[l].X != -1) {
                cout << LB.query(dsu.find_weight(Q[l].X) ^ dsu.find_weight(Q[l].Y)) << '\n';
            }
        } else {
            ch[0]->travelsal();
            ch[1]->travelsal();
        }
        dsu.rollback();
        LB.rollback();
    }
};

int main () {
    owo;
    int n, m, q;
    cin >> n >> m;
    map <pii, pii> m1;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        if (u > v) swap(u, v);
        m1[{u, v}] = mp(0, w);
    }
    cin >> q;
    Seg root(0, q + 1);
    for (int t = 0; t <= q; ++t) Q[t].X = -1;
    for (int t = 1, type, u, v, w; t <= q; ++t) {
        cin >> type >> u >> v, --u, --v;
        if (u > v) swap(u, v);
        if (type == 1) {
            cin >> w;
            m1[{u, v}] = mp(t, w);
        } else if (type == 2) {
            pii A = m1[{u, v}];
            root.add_event(A.X, t, u, v, A.Y);
            m1.erase({u, v});
        } else {
            Q[t] = mp(u, v);
        }
    }
    for (auto A : m1) {
        root.add_event(A.Y.X, q + 1, A.X.X, A.X.Y, A.Y.Y);
    }
    root.travelsal();
}