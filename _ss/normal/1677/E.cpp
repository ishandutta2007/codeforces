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

const int N = 2e5 + 10;

struct segment_tree
{
    ll it[N * 4], lazy[N * 4], n, u, v, x;

	ll combine(ll obj1, ll obj2) { return obj1 + obj2;}

    void init(int len)
    {
        n = len;
    }

    void apply(int id, ll val, int len)
    {
        it[id] += val * len;
        lazy[id] += val;
    }

    void push(int id, int l, int r, int mid)
    {
        apply(id << 1, lazy[id], mid - l + 1);
        apply((id << 1) | 1, lazy[id], r - mid);
        lazy[id] = 0;
    }

    void update(int id, int l, int r)
    {
        if (l > v || r < u) return;
        if (u <= l && r <= v)
        {
            apply(id, x, r - l + 1);
            return;
        }
        int mid = (l + r) >> 1;
        push(id, l, r, mid);
        update(id << 1, l, mid);
        update((id << 1) | 1, mid + 1, r);
        it[id] = combine(it[id << 1], it[(id << 1) | 1]);
    }

    ll get(int id, int l, int r)
    {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return it[id];
        int mid = (l + r) >> 1;
        push(id, l, r, mid);
        return combine(get(id << 1, l, mid), get((id << 1) | 1, mid + 1, r));
    }

    void Update(int l, int r, ll val)
    {
        u = l;
        v = r;
        x = val;
        update(1, 1, n);
    }

    ll Get(int l, int r)
    {
        u = l;
        v = r;
        if (l > r) return 0;
        return get(1, 1, n);
    }
} seg1, seg2;

int p[N], n, q, L[N], R[N], pos[N];
vector<pii> LQ[N], RQ[N], LA[N], RA[N];
ll ans[N * 5];
vi divisor[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> p[i], pos[p[i]] = i;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i) divisor[j].eb(i);
    for (int i = 1, l, r; i <= q; ++i)
    {
        cin >> l >> r;
        LQ[l].eb(r, i);
        RQ[r].eb(l, i);
    }
    p[0] = p[n + 1] = n + 1;
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= n; ++i)
    {
        while (p[i] > p[st.top()]) st.pop();
        L[i] = st.top() + 1;
        //cout << L[i] << " ";
        st.push(i);
    }
    //cout << "\n";
    while (!st.empty()) st.pop();
    st.push(n + 1);
    for (int i = n; i; --i)
    {
        while (p[i] > p[st.top()]) st.pop();
        R[i] = st.top() - 1;
        st.push(i);
    }
    //for (int i = 1; i <= n; ++i) cout << R[i] << " ";
    //cout << "\n";
    for (int i = 1; i <= n; ++i)
        if (i - L[i] < R[i] - i)
        {
            int mn = n + 1;
            for (int x : divisor[p[i]])
            {
                int px = pos[x];
                int py = pos[p[i] / x];
                if (px != py && min(px, py) >= i) mn = min(mn, max(px, py));
            }
            for (int j = i; j >= L[i]; --j)
            {
                if (p[i] % p[j] == 0)
                {
                    int d = pos[p[i] / p[j]];
                    if (d != j && d >= j) mn = min(mn, d);
                }
                mn = max(mn, i);
                if (mn <= R[i]) LA[j].eb(mn, R[i])/*, cout << j << " " << mn << " " << R[i] << "\n"*/;
            }
        }
        else
        {
            int mx = 0;
            for (int x : divisor[p[i]])
            {
                int px = pos[x];
                int py = pos[p[i] / x];
                if (px != py && max(px, py) <= i) mx = max(mx, min(px, py));
            }
            for (int j = i; j <= R[i]; ++j)
            {
                if (p[i] % p[j] == 0)
                {
                    int d = pos[p[i] / p[j]];
                    if (d != j && d <= j) mx = max(mx, d);
                }
                mx = min(mx, i);
                if (L[i] <= mx) RA[j].eb(L[i], mx)/*, cout << j << " " << L[i] << " " << mx << "R\n"*/;
            }
        }
    seg1.init(n);
    for (int l = n; l; --l)
    {
        for (pii pa : LA[l]) seg1.Update(pa.fi, pa.se, 1);
        for (pii pa : LQ[l]) ans[pa.se] = seg1.Get(l, pa.fi);
    }
    seg2.init(n);
    for (int r = 1; r <= n; ++r)
    {
        for (pii pa : RA[r]) seg2.Update(pa.fi, pa.se, 1);
        for (pii pa : RQ[r]) ans[pa.se] += seg2.Get(pa.fi, r);
    }
    for (int i = 1; i <= q; ++i) cout << ans[i] << "\n";
    return 0;
}