#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef __int128_t i128;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n; cin >> m >> n;
    vi a(n), b(n);
    map<int, vi> la, lb;
    f0r(i, n) cin >> a[i], a[i]--, la[a[i]].pb(i);
    f0r(i, n) cin >> b[i], b[i]--, lb[b[i]].pb(i);
    vi ans(n);

    auto conn = [&](int x, int y) {
        assert(la.count(x) && lb.count(y));
        ans[la[x].back()] = lb[y].back();
        la[x].pop_back();
        lb[y].pop_back();
    };

    multiset<int> ma, mb;
    f0r(i, n) ma.insert(a[i]), mb.insert(b[i]);
    vpi use;
    each(x, ma) {
        if (mb.count(x)) {
            mb.erase(mb.find(x));
            conn(x, x);
            continue;
        }
        use.eb(x, -1); // you go from -1 to 1
    }
    each(x, mb) {
        use.eb(x, 1);
    }
    sort(all(use));
    int sz = sz(use);
    vl pval(sz);
    vector<vl> p(2, vl(sz));
    vector<vl> c(2, vl(sz));
    f0r(i, sz) {
        pval[i] = (i?pval[i-1]:0) + use[i].s;
        f0r(j, 2) {
            p[j][i] = (i?p[j][i-1]:0) + (use[i].s == 2*j-1 ? use[i].f : 0);
            c[j][i] = (i?c[j][i-1]:0) + (use[i].s == 2*j-1 ? 1 : 0);
        }
    }
    
    // cost from l to r
    auto psum = [&](vector<vl>& v, int t, int l, int r) -> ll {
        return v[t][r]-(l?v[t][l-1]:0);
    };
    
    auto csum = [&](int t, int l, int r) -> ll {
        if (l <= r) return psum(p, t, l, r);
        ll ret = 0;
        ret += psum(p, t, l, sz - 1) + psum(p, t, 0, r);
        ret += psum(c, t, 0, r) * m;
        return ret;

    };  
    
    auto get = [&](int l, int r) -> ll {
        return abs(csum(0, l, r) - csum(1, l, r));
    };

    map<int, vi> locs;

    f0r(i, sz) {
        locs[pval[i]].pb(i);
    }
    // each(x, use) {
    //     cout << x.f << " USE " << x.s << endl;
    // }

    ll amt = INF;
    int best = -1;
    each(id, locs) {
        vi loc = id.s;
        ll tot = 0;
        // cout << "LOC: ";
        f0r(i, sz(loc)) {
            tot += get((loc[i]+1)%sz, loc[(i+1)%sz(loc)]);
            // cout << loc[i] << " ";
        }
        // cout << endl;
        if (ckmin(amt, tot)) {
            best = id.f;
        }
    }

    vi loc = locs[best];

    f0r(j, sz(loc)) {
        int l = (loc[j]+1)%sz;
        int r = loc[(j+1)%sz(loc)];
        vi store;
        int i = l;
        do {
            if (use[l].s == -1) {
                if (use[i].s == -1) {
                    store.pb(use[i].f);
                } else {
                    conn(store.back(), use[i].f);
                    store.pop_back();
                }
            } else {
                if (use[i].s == -1) {
                    conn(use[i].f, store.back());
                    store.pop_back();
                } else {
                    store.pb(use[i].f);
                }
            }
            i = (i+1)%sz;
        } while (i != (r+1)%sz);
    }

    if (amt == INF) amt = 0;

    cout << amt << '\n';

    each(x, ans) cout << x+1 << " ";
    cout << '\n';

    return 0;
}

/**
 * Observations
     * No directed paths should cross in opposite directions
     * 
 */