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

void solve()
{
    int n, m; cin>>n>>m;

    vector<int> a(n); for (int i = 0; i<n; i++) cin>>a[i];

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    a.resize(m);
    reverse(a.begin(), a.end());

    vector<vector<int>> b(m);
    for (int i = 0; i<m; i++)
    {
        int k; cin>>k;
        for (int j = 0; j<k; j++)
        {
            int val; cin>>val;
            b[i].push_back(val);
        }
    }
    //avgs, pos

    vector<ll> sums(m);
    vector<pair<ll, int>> avgs;
    for (int i = 0; i<m; i++)
    {
        ll sum = 0;
        for (auto it: b[i]) sum+=it;
        sums[i] = sum;
        ll sz = b[i].size();
        ll avg = (sum+sz-1)/sz;
        avgs.push_back(mp(avg, i));
    }

    sort(avgs.begin(), avgs.end());

    int Lgood = -1;
    while (Lgood+1<m && avgs[Lgood+1].first<=a[Lgood+1]) Lgood++;
    int Rgood = m;
    while (Rgood-1>=0 && avgs[Rgood-1].first<=a[Rgood-1]) Rgood--;

    vector<int> shiftR(m);
    shiftR[0] = 0;
    for (int i = 1; i<m; i++)
    {
        if (avgs[i-1].first>a[i]) shiftR[i] = i;
        else shiftR[i] = shiftR[i-1];
    }

    vector<int> shiftL(m);
    shiftL[m-1] = m-1;
    for (int i = m-2; i>=0; i--)
    {
        if (avgs[i+1].first>a[i]) shiftL[i] = i;
        else shiftL[i] = shiftL[i+1];
    }

    int totsz = 0;
    for (auto vec: b) totsz+=vec.size();

    vector<int> st(m);
    for (int i = 1; i<m; i++) st[i] = st[i-1] + b[i-1].size();

    vector<bool> ans(totsz);

    for (int i = 0; i<m; i++)
    {
        //processing avgs[i].second;
        int idx = avgs[i].second;
        for (int j = 0; j<b[idx].size(); j++)
        {
            int stud = st[idx] + j;
            ll sum1 = sums[idx] - b[idx][j];
            ll sz1 = b[idx].size() - 1;
            ll new_avg = (sum1 + sz1-1)/sz1;

            int new_pos = lower_bound(avgs.begin(), avgs.end(), mp(new_avg, -1)) - avgs.begin();

            //new_pos is the first idx larger than new_avg

            bool ok;
            if (new_pos == i)
            {
                ok = (new_avg<=a[i] && Lgood>=i-1 && Rgood<=i+1);
            }
            else if (new_pos<i)
            {
                //putting element at new_pos, right_shift;
                ok = (new_avg<=a[new_pos] && Lgood>=new_pos-1 && Rgood<=i+1 && shiftR[i]<=new_pos);
            }
            else
            {
                //putting element at new_pos-1, left shift
                ok = (new_avg<=a[new_pos-1] && Lgood>=i-1 && Rgood<=new_pos && shiftL[i]>=new_pos-1);
            }
            ans[stud] = ok;
        }
    }

    for (auto it: ans) cout<<it;
    cout<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();


}
/*
p = 4 2 1 3
1->4->3
1 2 3 4
4 2 1 3
3 2 4 1
1 2 3 4

 */