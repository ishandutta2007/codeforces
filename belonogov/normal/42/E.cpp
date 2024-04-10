#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;
const int LOG = 19;

struct Edge {
    int v, u, c;
};


int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Edge> edge;
    for (int i = 0; i < m; i++) {
        int v, u, c;
        scanf("%d%d%d", &v, &u, &c); v--; u--;
        edge.pb({v, u, c});
    }
    int qq;
    scanf("%d", &qq);
    vector<pair<int,int>> query(qq);
    for (int i = 0; i < qq; i++) {
        scanf("%d%d", &query[i].F, &query[i].S);
        query[i].F--;
        query[i].S--;
    }
    
    sort(all(edge), [](Edge A, Edge B) {
                return A.c < B.c;
            });

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    function<int(int)> getId = [&](int v) {
        return (p[v] == v)? v: p[v] = getId(p[v]);
    };

    vector<Edge> good;
    ll cost = 0;
    for (auto e: edge) {
        int v = getId(e.v);
        int u = getId(e.u);
        if (v != u) {
            good.pb(e);
            cost += e.c;
            p[v] = u;
        }
    }
    vector<ll> answer;
    //db(good.size());

    if (sz(good) < n - 1) {
        if (sz(good) == n - 2) {
            for (auto q: query) {
                if (getId(q.F) != getId(q.S)) {
                    answer.pb(cost);
                }
                else {
                    answer.pb(-1);
                }
            }
        }
        else {
            answer.assign(query.size(), -1);
        }
    }
    else {
        vector<vector<pair<int,int>>> e(n);
        assert(sz(good) == n - 1);
        for (auto x: good) {
            e[x.v].pb({x.u, x.c});
            e[x.u].pb({x.v, x.c});
        }

        vector<vector<int>> jump(n, vector<int> (LOG));
        vector<vector<int>> mxJump(n, vector<int> (LOG));
        vector<int> h(n);

        function<void(int,int)> dfs = [&](int v, int par) {
            for (int i = 1; i < LOG; i++) {
                jump[v][i] = jump[jump[v][i - 1]][i - 1];
                mxJump[v][i] = max(mxJump[v][i - 1], mxJump[jump[v][i - 1]][i - 1]);
            }

            for (auto x: e[v]) {
                int u = x.F;
                if (u == par) continue;
                jump[u][0] = v;
                mxJump[u][0] = x.S;
                h[u] = h[v] + 1;
                dfs(u, v);
            }
        };
        
        jump[0][0] = 0;
        dfs(0, -1);

        auto getPathMx = [&](int v, int u) {
            if (h[v] > h[u]) {
                swap(v, u);
            }   
            int res = 0;
            int dh = h[u] - h[v];
            for (int i = 0; i < LOG; i++) {
                if (dh & pw(i)) {
                    res = max(res, mxJump[u][i]);
                    u = jump[u][i];
                } 
            }
            assert(h[v] == h[u]);
            if (v == u) {
                return res;
            }
            for (int i = LOG - 1; i >= 0; i--) {
                if (jump[v][i] != jump[u][i]) {
                    res = max(res, mxJump[v][i]);
                    res = max(res, mxJump[u][i]);
                    v = jump[v][i];
                    u = jump[u][i];
                }
            }
            res = max(res, mxJump[v][0]);
            res = max(res, mxJump[u][0]);
            return res;
        };

        for (auto x: query) {
            answer.pb(cost - getPathMx(x.F, x.S));
        }
    }


    for (auto x: answer) {
        printf("%lld\n", x);
    }


    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}