#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define u128 unsigned __int128
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using u32 = uint32_t;
using u64 = uint64_t;

namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l, ll r) {return uniform_int_distribution<ll> (l, r) (mt);}
}

using namespace myrand;
const int N = 2e5 + 10, lgn = 16;
const u64 Hmod = (1ull << 61) - 1, Hbase = Int(N, Hmod - 1);

u64 modmul(u64 x, u64 y)
{
#if defined(__LP64__) || defined(_WIN64)
    u128 res = (u128)x * y + 1;
    res =(res & Hmod) + (res >> 61);
    res =(res & Hmod) + (res >> 61);
    return res - 1;
#else
    u64 lx = (u32)x, hx = x >> 32, ly = (u32)y, hy = y >> 32;
    u64 l = lx * ly, m = lx * hy + ly * hx, h = hx * hy;
    u64 res = (l & Hmod) + (l >> 61) + ((m << 35) >> 3) + (m >> 29) + (h << 3) + 1;
    res = (res & Hmod) + (res >> 61);
    res = (res & Hmod) + (res >> 61);
    return res - 1;
#endif
}

u64 modplus(u64 x, u64 y)
{
    x += y;
    if (x >= Hmod) x -= Hmod;
    return x;
}

u64 Hnxt(u64 x, u64 c)
{
    return modplus(modmul(x, Hbase), c);
}

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

struct merge_sort_tree
{
    int it[20][N], n, u, v, x;

    void build(int id, int l, int r, int h, int a[])
    {
        if (l == r)
        {
            it[h][l] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, h + 1, a);
        build((id << 1) | 1, mid + 1, r, h + 1, a);
        merge(it[h + 1] + l, it[h + 1] + mid + 1, it[h + 1] + mid + 1, it[h + 1] + r + 1, it[h] + l);
    }

    int get_leq(int id, int l, int r, int h)
    {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return upper_bound(it[h] + l, it[h] + r + 1, x) - it[h] - l;
        int mid = (l + r) >> 1;
        return get_leq(id << 1, l, mid, h + 1) + get_leq((id << 1) | 1, mid + 1, r, h + 1);
    }

    void init(int a[], int len)
    {
        n = len;
        build(1, 1, n, 0, a);
    }

    int Get_leq(int l, int r, int val)
    {
        u = l;
        v = r;
        x = val;
        return get_leq(1, 1, n, 0);
    }
} seg;

u64 pwb[N], h[N], rh[N], ht[N];
char S[N];
int st[N], n, m, q, K, SA[N], spr[20][N], d[N];
vector<pii> G[N];

void dfs(int u)
{
    for (int i = 1; i <= lgn; ++i) spr[i][u] = spr[i - 1][spr[i - 1][u]];
    for (pii e : G[u])
        if (e.fi != spr[0][u])
        {
            spr[0][e.fi] = u;
            d[e.fi] = d[u] + 1;
            ht[e.fi] = Hnxt(ht[u], e.se);
            dfs(e.fi);
        }
}

int find_anc(int u, int k)
{
    for (int i = 0; k; k >>= 1, ++i)
        if (k & 1) u = spr[i][u];
    return u;
}

int lca(int u, int v)
{
    if (d[u] > d[v]) swap(u, v);
    v = find_anc(v, d[v] - d[u]);
    int k = lgn;
    while (u != v)
    {
        while (k && spr[k][u] == spr[k][v]) --k;
        u = spr[k][u];
        v = spr[k][v];
    }
    return u;
}

ll get_hash(int l, int r) { return modplus(h[r], Hmod - modmul(h[l - 1], pwb[r - l + 1]));}
ll get_rhash(int l, int r) { return modplus(rh[l], Hmod - modmul(rh[r + 1], pwb[r - l + 1]));}
ll get_hashT(int u, int r) { return modplus(ht[u], Hmod - modmul(ht[r], pwb[d[u] - d[r]]));} // r must be anc of u

bool cmp1(int id, int u, int v, int r) // >=
{
    for (int i = lgn; i >= 0; --i)
    {
        int t = spr[i][u];
        if (d[t] >= d[r] && d[u] - d[t] <= K - id + 1 && get_hashT(u, t) == get_rhash(id, id + d[u] - d[t] - 1))
        {
            id += d[u] - d[t];
            u = t;
        }
    }
    if (u != r)
    {
        if (id > K) return false;
        return S[id] >= get_hashT(u, spr[0][u]);
    }
    if (v == r) return true;
    if (id > K) return false;
    for (int i = lgn; i >= 0; --i)
    {
        int t = spr[i][v];
        if (d[t] >= d[r] && (d[t] - d[r] > K - id + 1 || get_hashT(t, r) != get_hash(id, id + d[t] - d[r] - 1)))
        {
            v = t;
        }
    }
    return (id + d[v] - d[r] - 1 <= K && S[id + d[v] - d[r] - 1] >= get_hashT(v, spr[0][v]));
}

bool cmp2(int id, int u, int v, int r) // =
{
    if (d[u] + d[v] - 2 * d[r] > K - id + 1) return false;
    return (get_hashT(u, r) == get_rhash(id, id + d[u] - d[r] - 1) && get_hashT(v, r) == get_hash(id + d[u] - d[r], id + d[u] + d[v] - 2 * d[r] - 1));
}

pii range(int u, int v)
{
    int t = lca(u, v);
    int l = 1, r = K, L = K + 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (cmp1(SA[mid], u, v, t)) L = mid, r = mid - 1;
        else l = mid + 1;
    }
    l = L, r = K;
    int R = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (cmp2(SA[mid], u, v, t)) R = mid, l = mid + 1;
        else r = mid - 1;
    }
    return mp(L, R);
}

void precal()
{
    string s;
    for (int i = 1; i <= K; ++i) s += S[i];
    SuffixArray tmp(s);
    for (int i = 1; i <= K; ++i) SA[i] = tmp.sa[i] + 1;
    for (int i = 1; i <= K; ++i) h[i] = Hnxt(h[i - 1], S[i]);
    for (int i = K; i; --i) rh[i] = Hnxt(rh[i + 1], S[i]);
    pwb[0] = 1;
    for (int i = 1; i <= K; ++i) pwb[i] = modmul(pwb[i - 1], Hbase);
    d[1] = 1;
    dfs(1);
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1, u, v; i < n; ++i)
    {
        char c;
        cin >> u >> v >> c;
        G[u].eb(v, c);
        G[v].eb(u, c);
    }
    st[1] = 1;
    for (int i = 1; i <= m; ++i)
    {
        string s;
        cin >> s;
        st[i + 1] = st[i] + s.length() + 1;
        for (int j = 0; j < (int)s.length(); ++j) S[st[i] + j] = s[j];
        S[st[i] + s.length()] = '#';
    }
    K = st[m + 1] - 1;
    precal();
    seg.init(SA, K);
    for (int i = 1, u, v, l, r; i <= q; ++i)
    {
        cin >> u >> v >> l >> r;
        l = st[l];
        r = st[r + 1] - 1;
        pii tmp = range(u, v);
        //cout << tmp.fi << " " << tmp.se << "\n";
        if (tmp.fi <= tmp.se) cout << seg.Get_leq(tmp.fi, tmp.se, r) - seg.Get_leq(tmp.fi, tmp.se, l - 1) << "\n";
        else cout << "0\n";
    }
    //cout << cmp1(SA[6], 2, 5, lca(2, 5));
    /*for (int i = 1; i <= K; ++i)
    {
        cout << i << "\n";
        for (int j = SA[i]; j <= K; ++j) cout << S[j];
        cout << "\n";
    }*/
    return 0;
}