#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
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
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 2000, logN = 17;

struct line {
    lli m, k; // y = mx + k
    lli v (lli x) {
        return m * x + k;
    }
};

struct Edge {
    int u, v;
    lli w;
    Edge (int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

lli get(line seg, lli l, lli r) {
    lli ans = (l + r) * (r - l + 1) % mod * ((mod + 1) / 2) % mod * seg.m % mod;
    return (ans + seg.k * (r - l + 1)) % mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q, u, v, w;
    cin >> n >> m >> q;
    vector <Edge> E(m, Edge(0, 0, 0));
    vector <lli> maxx(n, 0);
    fop (i,0,m) {
        cin >> E[i].u >> E[i].v >> E[i].w;
        E[i].u--; E[i].v--;
        maxx[E[i].u] = max(maxx[E[i].u], E[i].w);
        maxx[E[i].v] = max(maxx[E[i].v], E[i].w);
    }
    vector <lli> cur(n, -1ll << 60);
    cur[0] = 0;
    lli ans = 0;
    fop (i,1,m + 1) {
        vector <lli> now(n, -1ll << 60);
        fop (i,0,m) {
            now[E[i].u] = max(now[E[i].u], cur[E[i].v] + E[i].w);
            now[E[i].v] = max(now[E[i].v], cur[E[i].u] + E[i].w);
        }
        ans = (ans + *max_element(all(now))) % mod;
        swap(cur, now);
    }
    vector <line> L;
    fop (i,0,n) if (cur[i] != -1ll << 60) {
        line seg;
        seg.m = maxx[i]; seg.k = cur[i] - maxx[i] * m;
        L.pb(seg);
    }
    auto query = [&](lli x) {
        line best;
        best.m = 0, best.k = -1ll << 60;
        for (line l : L)
            if (best.v(x) < l.v(x)) swap(best, l);
        return best;
    };
    lli now = m + 1;
    while (now < q + 1) {
        line cur = query(now);
        lli l = now, r = mod;
        while (r - l > 1) {
            lli mid = l + r >> 1;
            line now = query(mid);
            if (cur.m == now.m) l = mid;
            else r = mid;
        }
        l = min(l, 1ll * q); 
        ans = (ans + get(cur, now, l)) % mod;
        now = l + 1;
    }
    ans = (ans + mod) % mod;
    cout << ans << endl;
}