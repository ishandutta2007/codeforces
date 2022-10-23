#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using pll = pair<ll, ll>;

const int N = 1e6 + 10;
const ll inf = 1e18;
struct segment_tree
{
    ll it[N * 4], n, u, v, x;

	ll combine(ll obj1, ll obj2) { return max(obj1, obj2);}

    void init(int len)
    {
        n = len;
    }

    void update(int id, int l, int r)
    {
        if (l == r)
        {
            it[id] = x;
            return;
        }
        int mid = (l + r) >> 1;
        if (v <= mid) update(id << 1, l, mid);
        else update((id << 1) | 1, mid + 1, r);
        it[id] = combine(it[id << 1], it[(id << 1) | 1]);
    }

    ll get(int id, int l, int r)
    {
        if (l > v || r < u) return -inf;
        if (u <= l && r <= v) return it[id];
        int mid = (l + r) >> 1;
        return combine(get(id << 1, l, mid), get((id << 1) | 1, mid + 1, r));
    }

    void Update(int r, ll val)
    {
        v = r;
        x = val;
        update(1, 1, n);
    }

    ll Get(int l, int r)
    {
        u = l;
        v = r;
        if (l > r) return -inf;
        return get(1, 1, n);
    }
} seg;

struct segment_tree2
{
    struct ds {ll a, b, best;};
    int n, u, v;
    ds it[N * 4];
    ds combine(ds obj1, ds obj2)
    {
        return {max(obj1.a, obj2.a), max(obj1.b, obj2.b), max({obj1.best, obj2.best, obj1.a + obj2.b})};
    }

    void build(int id, int l, int r, pll ar[])
    {
        if (l == r)
        {
            it[id] = {ar[l].fi, ar[l].se, ar[l].fi + ar[l].se};
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, ar);
        build((id << 1) | 1, mid + 1, r, ar);
        it[id] = combine(it[id << 1], it[(id << 1) | 1]);
    }

    void init(pll ar[], int len)
    {
        n = len;
        build(1, 1, n, ar);
    }

    ds get(int id, int l, int r)
    {
        if (l > v || r < u) return {-inf, -inf, -inf};
        if (u <= l && r <= v) return it[id];
        int mid = (l + r) >> 1;
        return combine(get(id << 1, l, mid), get((id << 1) | 1, mid + 1, r));
    }

    ll Get(int l, int r)
    {
        u = l;
        v = r;
        if (l > r) return -inf;
        return get(1, 1, n).best;
    }
} seg2;

int n, q, a[4][N];
ll ps[N], pr[N], su[N], ps2[N];
pll val[N];
vector<pii> Q[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
    {
        pr[i] = pr[i - 1] + a[1][i];
        ps2[i] = ps[i] = ps[i - 1] + a[2][i];
    }
    for (int i = n; i; --i) su[i] = su[i + 1] + a[3][i];
    for (int i = 1; i <= n; ++i) ps[i] += su[i];
    for (int i = 0; i < n; ++i) ps2[i] = -ps2[i] + pr[i + 1];
    for (int i = 1, l, r, k; i <= q; ++i)
    {
        cin >> l >> r >> k;
        Q[r].eb(l, k);
    }
    val[1] = mp(ps2[0], ps[1]);
    seg.init(n);
    seg.Update(1, val[1].fi);
    for (int i = 2; i <= n; ++i)
    {
        ll best = ps2[i - 1];
        for (pii p : Q[i - 1])
            best = max(best, seg.Get(p.fi, i - 1) - p.se);
        val[i] = mp(best, ps[i]);
        seg.Update(i, best);
    }
    seg2.init(val, n);
    ll res = -inf;
    for (int r = 1; r <= n; ++r)
    {
        for (pii p : Q[r])
            res = max(res, seg2.Get(p.fi, r) - p.se);
    }
    cout << res;
    return 0;
}