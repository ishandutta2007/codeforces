#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200008, logN = 18, K = 600, C = 100, M = 1e9;

struct Dsu {
    struct op {
        int x, dx, y, szy;
    };
    int dsu[N], size[N], n, cc;
    stack <op> stk;
    stack <int> point;
    Dsu (int _n): n(_n), cc(_n) {
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
            size[i] = 1;
        }
    }
    int Find(int a) {
        if (dsu[a] == a) return a;
        return Find(dsu[a]);
    }
    bool Union(int a, int b) {
        int x = Find(a), y = Find(b);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        stk.push({x, dsu[x], y, size[y]});
        dsu[x] = y;
        size[y] += size[x];
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
    void addPoint() {
        point.push(stk.size());
    }
    void rollback() {
        int x = point.top();
        while (stk.size() > x) {
            op A = stk.top(); stk.pop();
            dsu[A.x] = A.dx;
            size[A.y] = A.szy;
            cc++;
        }
        point.pop();
    }
};

struct op {
    int t, u, v;
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <op>> block;
    for (int i = 0; i < m; ++i) {
        if (block.empty() || block.back().size() == K) block.pb({});
        op tmp;
        cin >> tmp.t >> tmp.u >> tmp.v;
        block.back().pb(tmp);
    }
    int last = 0;
    set <pii> has_edge;
    for (int i = 0; i < block.size(); ++i) {
        set <pii> in_block_edge, cur_block_edge;
        for (op &A : block[i]) {
            if (A.t == 1) {
                in_block_edge.insert({A.u % n, A.v % n});
                in_block_edge.insert({(A.u - 1) % n, (A.v - 1) % n});
                in_block_edge.insert({A.v % n, A.u % n});
                in_block_edge.insert({(A.v - 1) % n, (A.u - 1) % n});
            }
        }
        Dsu dsu(n);
        for (pii A : has_edge) {
            if (!in_block_edge.count(A)) dsu.Union(A.X, A.Y);
            else cur_block_edge.insert(A);
        }
        for (op &A : block[i]) {
            int u = (A.u + last - 1) % n, v = (A.v + last - 1) % n;
            if (u > v) swap(u, v);
            if (A.t == 1) {
                assert(in_block_edge.count({u, v}));
                if (cur_block_edge.count({u, v})) {
                    cur_block_edge.erase({u, v});
                    has_edge.erase({u, v});
                } else {
                    cur_block_edge.insert({u, v});
                    has_edge.insert({u, v});
                }
            } else {
                dsu.addPoint();
                for (pii A : cur_block_edge) {
                    dsu.Union(A.X, A.Y);
                }
                last = dsu.same(u, v);
                cout << last;
                dsu.rollback();
            }
        }
    }
}