#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = double;


typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair

int MOD = 998244353;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));


const int LIM = 1000005;

vector<int> facs(LIM), invfacs(LIM), invs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);

    for (int i = 1; i<LIM; i++) invs[i] = mul(invfacs[i], facs[i-1]);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}



struct DSU
{
    vector<int> sz;
    vector<int> parent;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};

void print(vector<int> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

void print(vector<bool> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}
/*
void print(vector<pair<ll, ll>> a)
{
    for (auto it: a) cout<<it.first<<' '<<it.second<<"| ";
    cout<<endl;
}*/

void print(vector<pair<int, int>> a)
{
    for (auto it: a) cout<<it.first<<' '<<it.second<<"| ";
    cout<<endl;
}

/*const int mod = 998244353;

template<int mod>
struct NTT {
    static constexpr int max_lev = __builtin_ctz(mod - 1);

    int prod[2][max_lev - 1];

    NTT() {
        int root = find_root();//(mod == 998244353) ? 31 : find_root();
        int rroot = power(root, mod - 2);
        vector<vector<int>> roots(2, vector<int>(max_lev - 1));
        roots[0][max_lev - 2] = root;
        roots[1][max_lev - 2] = rroot;
        for (int tp = 0; tp < 2; ++tp) {
            for (int i = max_lev - 3; i >= 0; --i) {
                roots[tp][i] = mul(roots[tp][i + 1], roots[tp][i + 1]);
            }
        }
        for (int tp = 0; tp < 2; ++tp) {
            int cur = 1;
            for (int i = 0; i < max_lev - 1; ++i) {
                prod[tp][i] = mul(cur, roots[tp][i]);
                cur = mul(cur, roots[tp ^ 1][i]);
            }
        }
    }

    template<bool inv>
    void fft(int *a, int lg) const {
        const int n = 1 << lg;
        int pos = max_lev - 1;
        for (int it = 0; it < lg; ++it) {
            const int h = inv ? lg - 1 - it : it;
            const int shift = (1 << (lg - h - 1));
            int coef = 1;
            for (int start = 0; start < (1 << h); ++start) {
                for (int i = start << (lg - h); i < (start << (lg - h)) + shift; ++i) {
                    if (!inv) {
                        const int y = mul(a[i + shift], coef);
                        a[i + shift] = a[i];
                        inc(a[i], y);
                        dec(a[i + shift], y);
                    } else {
                        const int y = mul(a[i] + mod - a[i + shift], coef);
                        inc(a[i], a[i + shift]);
                        a[i + shift] = y;
                    }
                }
                coef = mul(coef, prod[inv][__builtin_ctz(~start)]);
            }
        }
    }

    vector<int> product(vector<int> a, vector<int> b) const {
        if (a.empty() || b.empty()) {
            return {};
        }
        const int sz = a.size() + b.size() - 1;
        const int lg = 32 - __builtin_clz(sz - 1), n = 1 << lg;
        a.resize(n);
        b.resize(n);
        fft<false>(a.data(), lg);
        fft<false>(b.data(), lg);
        for (int i = 0; i < n; ++i) {
            a[i] = mul(a[i], b[i]);
        }
        fft<true>(a.data(), lg);
        a.resize(sz);
        const int rn = power(n, mod - 2);
        for (int &x : a) {
            x = mul(x, rn);
        }
        return a;
    }

private:
    static inline void inc(int &x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }
    }

    static inline void dec(int &x, int y) {
        x -= y;
        if (x < 0) {
            x += mod;
        }
    }

    static inline int mul(int x, int y) {
        return (1LL * x * y) % mod;
    }

    static int power(int x, int y) {
        if (y == 0) {
            return 1;
        }
        if (y % 2 == 0) {
            return power(mul(x, x), y / 2);
        }
        return mul(x, power(x, y - 1));
    }

    static int find_root() {
        for (int root = 2; ; ++root) {
            if (power(root, (1 << max_lev)) == 1 && power(root, (1 << (max_lev - 1))) != 1) {
                return root;
            }
        }
    }
};

NTT<mod> ntt;
*/

struct SegmentTree
{
    int n;
    vector<int> t;
    vector<bool> marked;

    void push(int v) {
        if (marked[v]) {
            t[v*2] = t[v*2+1] = t[v];
            marked[v*2] = marked[v*2+1] = true;
            marked[v] = false;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int new_val) {
        if (l > r)
            return;
        if (l == tl && tr == r) {
            t[v] = new_val;
            marked[v] = true;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), new_val);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        }
    }

    int get(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return get(v*2, tl, tm, pos);
        else
            return get(v*2+1, tm+1, tr, pos);
    }

    SegmentTree(int N)
    {
        n = N;
        t = vector<int>(4*n, -1);
        marked = vector<bool>(4*n, true);
    }

    void upd(int l, int r, int new_val)
    {
        //cout<<"Making from "<<l<<" to "<<r<<" equal to "<<new_val<<endl;

        update(1, 0, n-1, l, r, new_val);
    }

    int get(int pos)
    {
        //cout<<"Searching for "<<pos<<endl;
        return get(1, 0, n-1, pos);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, t; cin>>n>>t;

    vector<ll> g(n), c(n); for (int i = 0; i<n; i++) cin>>g[i]>>c[i];

    vector<ll> d(n-1); for (int i = 0; i<n-1; i++) cin>>d[i];

    ll ans = 0;
    for (int i = 0; i<n-1; i++)
    {
        ans+=d[i]; c[i+1] = (c[i+1] + ans)%t;
    }

    vector<ll> st(n), en(n);
    for (int i = 0; i<n; i++)
    {
        st[i] = (t - c[i])%t;
        en[i] = (st[i] + g[i])%t;
    }

    /*cout<<t<<endl;
    for (int i = 0; i<n; i++) cout<<st[i]<<' '<<en[i]<<endl;*/

    set<int> vals;
    for (int i = 0; i<n; i++)
    {
        vals.insert(st[i]);
        vals.insert(en[i]);
    }

    vals.insert(0);

    map<int, int> mapka;
    vector<int> invmapka;

    int cur = 0;
    for (auto it: vals)
    {
        mapka[it] = cur;
        invmapka.push_back(it);
        cur++;
    }

    /*cout<<"MAPKA: "<<endl;
    for (auto it: mapka) cout<<it.first<<": "<<it.second<<endl;
    cout<<endl;*/


    SegmentTree tree(cur);

    vector<ll> dp(n);
    for (int i = n-1; i>=0; i--)
    {
        //Calculating dp
        int who = tree.get(mapka[st[i]]);

        //cout<<"Next for "<<i<<": "<<who<<endl;

        if (who == -1)
        {
            dp[i] = 0;
        }

        else dp[i] = dp[who] + (t + st[who] - st[i])%t;


        //Updating
        if (mapka[en[i]]<mapka[st[i]])
        {
            tree.upd(mapka[en[i]], mapka[st[i]]-1, i);
        }
        else
        {
            tree.upd(mapka[en[i]], cur-1, i);
            if (mapka[st[i]]>0) tree.upd(0, mapka[st[i]] - 1, i);
        }
    }

    ll best = 1e18;
    for (int i = 0; i<cur; i++)
    {
        int who = tree.get(i);
        if (who == -1) best = 0;
        else
        {
            best = min(best, dp[who] + (t + st[who] - (invmapka[(i+1)%cur] + t - 1)%t)%t);
        }
    }

    //for (int i = 0; i<n; i++) cout<<i<<": "<<dp[i]<<endl;

    //cout<<best<<endl;

    cout<<best + ans<<endl;
}

//after i = covers segment i