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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 300001, logN = 20, K = 15;

struct Dsu {
    int dsu[N << 1], sza[N << 1], szb[N << 1];
    Dsu () {
        for (int i = 0; i < N << 1; ++i)
            dsu[i] = i, (i < N ? sza[i] : szb[i]) = 1;
    }
    int Find(int x) {
        if (dsu[x] == x)
            return x;
        return Find(dsu[x]);
    }
    vector <pair <pii, pii>> move;
    vector <int> pt;
    bool Union(int u, int v) {
        u = Find(u), v = Find(v);
        if (u == v)
            return false;
        if (sza[u] + szb[u] < sza[v] + szb[v])
            swap(u, v);
        move.pb(mp(mp(u, v), mp(sza[u], szb[u])));
        sza[u] += sza[v];
        szb[u] += szb[v];
        dsu[v] = u;
        return true;
    }
    void add_point() {
        pt.pb(move.size());
    }
    void rollback() {
        assert(!pt.empty());
        while (move.size() > pt.back()) {
            sza[move.back().X.X] = move.back().Y.X;
            szb[move.back().X.X] = move.back().Y.Y;
            dsu[move.back().X.Y] = move.back().X.Y; move.pop_back();
        }
        pt.pop_back();
    }
} dsu;

lli cur_ans;
vector <lli> ans;

struct Seg {
    int l, r, m;
    Seg* ch[2];
    vector <pii> edge;
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void add_event(int a, int b, pii A) {
        if (a <= l && r <= b)
            edge.pb(A);
        else {
            if (a < m)
                ch[0]->add_event(a, b, A);
            if (m < b)
                ch[1]->add_event(a, b, A);
        }
    }
    void travelsal() {
        dsu.add_point();
        lli add = 0;
        for (auto [x, y] : edge) {
            x = dsu.Find(x), y = dsu.Find(y + N);
            if (x == y)
                continue;
            add -= 1ll * dsu.sza[x] * dsu.szb[x];
            add -= 1ll * dsu.sza[y] * dsu.szb[y];
            dsu.Union(x, y);
            x = dsu.Find(x);
            add += 1ll * dsu.sza[x] * dsu.szb[x];
        }
        cur_ans += add;
        if (r - l == 1) {
            ans.pb(cur_ans);
        } else {
            ch[0]->travelsal();
            ch[1]->travelsal();
        }
        cur_ans -= add;
        dsu.rollback();
    }
};

int main () {
    owo;
    int q;
    cin >> q;
    map <pii, int> m1;
    Seg root(0, q);
    for (int i = 0, x, y; i < q; ++i) {
        cin >> x >> y, --x, --y;
        if (m1.count({x, y})) {
            root.add_event(m1[{x, y}], i, {x, y});
            m1.erase({x, y});
        } else {
            m1[{x, y}] = i;
        }
    }
    for (auto A : m1) {
        root.add_event(A.Y, q, A.X);
    }
    root.travelsal();
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
}