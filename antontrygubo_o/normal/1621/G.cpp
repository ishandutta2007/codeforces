#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair

const int MOD =  1e9 + 7;

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


const int LIM = 400005;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
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

/*
const int mod = 998244353;

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

NTT<mod> ntt;*/

struct SegmentTree
{
    int n;
    vector<int> t;

    int summ(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return add(summ(v*2, tl, tm, l, min(r, tm)), summ(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    void add_on(int v, int tl, int tr, int pos, int adder) {
        if (tl == tr) {
            t[v] = add(t[v], adder);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                add_on(v*2, tl, tm, pos, adder);
            else
                add_on(v*2+1, tm+1, tr, pos, adder);
            t[v] = add(t[v*2], t[v*2+1]);
        }
    }

    int summ(int l, int r)
    {
        if (r<l) return 0;
        return summ(1, 0, n-1, l, r);
    }

    void add_on(int pos, int new_val)
    {
        add_on(1, 0, n-1, pos, new_val);
    }

    SegmentTree(int N)
    {
        n = N;
        t.resize(4*n);
    }
};

void print(vector<int> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

void print(vector<ll> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

pair<vector<int>, vector<int>> en_st(vector<int> a)
{
    set<int> vals;
    for (auto it: a) vals.insert(it);
    int cur = 0;
    map<int, int> mapka;
    for (auto it: vals)
    {
        mapka[it] = cur;
        cur++;
    }
    for (auto &it: a) it = mapka[it];

    int n = a.size();
    vector<int> ending(n), starting(n);

    SegmentTree ends(cur);
    for (int i = 0; i<n; i++)
    {
        int tot = ends.summ(0, a[i]-1);
        tot = add(tot, 1);
        ending[i] = tot;
        ends.add_on(a[i], tot);
    }

    SegmentTree starts(n);
    for (int i = n-1; i>=0; i--)
    {
        int tot = starts.summ(a[i]+1, cur-1);
        tot = add(tot, 1);
        starting[i] = tot;
        starts.add_on(a[i], tot);
    }
    return mp(ending, starting);
}

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    int maxx = -1;
    vector<pair<int, int>> guys;

    for (int i = n-1; i>=0; i--)
    {
        if (a[i]>maxx)
        {
            maxx = a[i];
            guys.push_back(mp(maxx, i));
        }
    }

    sort(guys.begin(), guys.end());

    vector<int> pos_nxt(n, -1);
    for (int i = 0; i<n; i++) if (a[i]!=maxx)
    {
        auto kek = lower_bound(guys.begin(), guys.end(), mp(a[i], 2'000'000'000)) - guys.begin();
        if (guys[kek].second>i) pos_nxt[i] = guys[kek].second;
    }

    vector<vector<int>> where(n);
    for (int i = 0; i<n; i++) if (pos_nxt[i]!=-1) where[pos_nxt[i]].push_back(i);

    auto res = en_st(a);

    /*print(res.first);
    print(res.second);
    print(pos_nxt);*/

    vector<int> subbing(n);
    for (auto vec: where) if (vec.size())
        {
            vector<int> who;
            for (auto it: vec) who.push_back(a[it]);
            auto tmp = en_st(who);

            int K = vec.size();
            for (int i = 0; i<K; i++) subbing[vec[i]] = tmp.second[i];
        }

    //print(subbing);

    int answer = 0;
    for (int i = 0; i<n; i++) if (pos_nxt[i]!=-1)
        {
            answer = add(answer, mul(res.first[i], sub(res.second[i], subbing[i])));
        }

    cout<<answer<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();


}
/*
1
4
4 5 6 5
 */