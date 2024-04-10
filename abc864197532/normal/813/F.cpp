#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 3e6;

struct Dsu {
    struct cha {
        int x, dx, y, szy;
    };
    int n;
    bool cyc;
    vector <int> dsu, size;
    vector <cha> stk;
    vector <pair <int, bool>> point;
    Dsu (int _n): n(_n) {
        dsu.resize(n);
        size.resize(n);
        cyc = false;
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
            size[i] = 1;
        }
    }
    int Find(int a) {
        if (dsu[a] == a) return a;
        return Find(dsu[a]);
    }
    bool same(int a, int b) {
        return Find(a) == Find(b);
    }
    bool Union(int a, int b) {
        int x = Find(a), y = Find(b);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        stk.pb({x, dsu[x], y, size[y]});
        dsu[x] = y;
        size[y] += size[x];
        return true;
    }
    void addPoint() {
        point.emplace_back(stk.size(), cyc);
    }
    void rollback() {
        while (stk.size() > point.back().first) {
            cha A = stk.back(); stk.pop_back();
            dsu[A.x] = A.dx;
            size[A.y] = A.szy;
        }
        cyc = point.back().second;
        point.pop_back();
    }
} dsu(N * 2);

bool ans[N];

struct TimeSeg {
    int l, r, m;
    vector <pii> E;
    TimeSeg *ch[2];
    TimeSeg(int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new TimeSeg(l, m);
            ch[1] = new TimeSeg(m, r);
        }
    }
    void addedge(pii e, int a, int b) {
        if (a <= l && r <= b) {
            E.pb(e);
        } else {
            if (a < m) ch[0]->addedge(e, a, b);
            if (m < b) ch[1]->addedge(e, a, b);
        }
    }
    void traversal() {
        dsu.addPoint();
        for (auto A : E) {
            if (dsu.same(A.X, A.Y)) dsu.cyc = true;
            dsu.Union(A.X + N, A.Y);
            dsu.Union(A.X, A.Y + N);
        }
        if (r - l == 1) {
            ans[l] = !dsu.cyc;
        } else {
            ch[0]->traversal();
            ch[1]->traversal();
        }
        dsu.rollback();
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, u, v;
    cin >> n >> q;
    vector <int> ask;
    map <pii, int> m1;
    TimeSeg root(0, q + 1);
    for (int i = 0; i < q; ++i) {
        cin >> u >> v, u--, v--;
        if (u > v) swap(u, v);
        if (!m1.count({u, v})) {
            m1[{u, v}] = i;
        } else {
            root.addedge({u, v}, m1[{u, v}], i);
            m1.erase({u, v});
        }
    }
    for (auto A : m1) {
        root.addedge(A.X, A.Y, q + 1);
    }
    root.traversal();
    for (int i = 0; i < q; ++i) cout << (ans[i] ? "YES\n" : "NO\n");
}