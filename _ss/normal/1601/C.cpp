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

const int N = 1e6 + 10;

struct segment_tree
{
    int it[N * 4], lazy[N * 4], n, u, v, x;

    int combine(int obj1, int obj2) { return min(obj1, obj2);}

    void init(int len)
    {
        n = len;
        for (int i = 1; i <= n * 4 + 10; ++i) it[i] = lazy[i] = 0;
    }

    void apply(int id, int val)
    {
        it[id] += val;
        lazy[id] += val;
    }

    void push(int id)
    {
        apply(id << 1, lazy[id]);
        apply((id << 1) | 1, lazy[id]);
        lazy[id] = 0;
    }

    void update(int id, int l, int r)
    {
        if (l > v || r < u) return;
        if (u <= l && r <= v)
        {
            apply(id, x);
            return;
        }
        int mid = (l + r) >> 1;
        push(id);
        update(id << 1, l, mid);
        update((id << 1) | 1, mid + 1, r);
        it[id] = combine(it[id << 1], it[(id << 1) | 1]);
    }

    int get(int id, int l, int r)
    {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return it[id];
        int mid = (l + r) >> 1;
        push(id);
        return combine(get(id << 1, l, mid), get((id << 1) | 1, mid + 1, r));
    }

    void Update(int l, int r, int val)
    {
        u = l;
        v = r;
        x = val;
        update(1, 1, n);
    }

    int Get(int l, int r)
    {
        u = l;
        v = r;
        if (l > r) return 0;
        return get(1, 1, n);
    }
} seg;

int n, b[N], m, bit[N];
pii a[N];

void add(int pos)
{
    for (int i = pos; i <= n; i += (i & -i)) bit[i]++;
}

int get(int pos)
{
    int res = 0;
    for (int i = pos; i; i -= (i & -i)) res += bit[i];
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = i;
        for (int i = 1; i <= m; ++i) cin >> b[i];
        sort(b + 1, b + m + 1);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) bit[i] = 0;
        ll res = 0;
        for (int i = n; i; --i)
        {
            res += get(a[i].se);
            add(a[i].se);
        }
        seg.init(n);
        for (int i = 1; i <= n; ++i) seg.Update(i, n, 1);
        int j = 1, j0 = 1;
        for (int i = 1; i <= m; ++i)
        {
            while (j0 <= n && a[j0].fi <= b[i])
            {
                seg.Update(a[j0].se, n, -1);
                j0++;
            }
            while (j <= n && a[j].fi < b[i])
            {
                seg.Update(a[j].se, n, -1);
                j++;
            }
            res += j - 1 + min(0, seg.it[1]);
        }
        cout << res << "\n";
    }
    return 0;
}