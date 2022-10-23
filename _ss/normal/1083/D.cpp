#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;

struct segment_tree
{
    struct node { ll s1, s2, p; };
    node it[N * 4];
    pii lazy[N * 4], x;
    int n, u, v;

    void recal(int id)
    {
        int lc = id << 1, rc = (id << 1) | 1;
        it[id].s1 = it[lc].s1 + it[rc].s1;
        it[id].s2 = it[lc].s2 + it[rc].s2;
        it[id].p = it[lc].p + it[rc].p;
    }

    void init(int sz) { n = sz;}

    void apply(int id, pii val, int sz)
    {
        it[id].p += it[id].s2 * val.fi + it[id].s1 * val.se + (ll)val.fi * val.se * sz;
        it[id].s1 += (ll)val.fi * sz;
        it[id].s2 += (ll)val.se * sz;
        lazy[id].fi += val.fi;
        lazy[id].se += val.se;
    }

    void push(int id, int l, int r, int mid)
    {
        apply(id << 1, lazy[id], mid - l + 1);
        apply((id << 1) | 1, lazy[id], r - mid);
        lazy[id] = mp(0, 0);
    }

    void Update(int id, int l, int r)
    {
        if (l > v || r < u) return;
        if (u <= l && r <= v)
        {
            apply(id, x, r - l + 1);
            return;
        }
        int mid = (l + r) >> 1;
        push(id, l, r, mid);
        Update(id << 1, l, mid);
        Update((id << 1) | 1, mid + 1, r);
        recal(id);
    }

    ll Get(int id, int l, int r)
    {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return it[id].p;
        int mid = (l + r) >> 1;
        push(id, l, r, mid);
        return Get(id << 1, l, mid) + Get((id << 1) | 1, mid + 1, r);
    }

    void update(int l, int r, pii val)
    {
        if (l > r) return;
        u = l;
        v = r;
        x = val;
        Update(1, 1, n);
    }

    ll get(int l, int r)
    {
        u = l;
        v = r;
        if (l > r) return 0;
        return Get(1, 1, n);
    }
} seg;

int prv[N], nxt[N], n, Lmax[N], Lmin[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, int> last;
    cin >> n;
    for (int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        prv[i] = last[x];
        nxt[prv[i]] = i;
        last[x] = i;
    }
    for (int i = 1; i <= n; ++i)
        if (!nxt[i]) nxt[i] = n + 1;
    prv[0] = n + 1;
    nxt[0] = 0;
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= n; ++i)
    {
        while (prv[i] > prv[st.top()]) st.pop();
        Lmax[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    st.push(0);
    for (int i = 1; i <= n; ++i)
    {
        while (nxt[i] < nxt[st.top()]) st.pop();
        Lmin[i] = st.top();
        st.push(i);
    }
    seg.init(n);
    ll res = 0;
    for (int l = 1, r = 1; r <= n; ++r)
    {
        l = max(l, prv[r] + 1);
        seg.update(r, r, mp(r - prv[r] - 1, nxt[r] - r - 1));
        seg.update(l, r - 1, mp(0, -1));
        int i = r - 1;
        while (i > Lmin[r])
        {
            seg.update(Lmin[i] + 1, i, mp(0, nxt[r] - nxt[i]));
            i = Lmin[i];
        }
        i = r - 1;
        while (i > Lmax[r])
        {
            seg.update(Lmax[i] + 1, i, mp(prv[i] - prv[r], 0));
            i = Lmax[i];
        }
        res = (res + seg.get(l, r)) % mod;
    }
    cout << res;
    return 0;
}