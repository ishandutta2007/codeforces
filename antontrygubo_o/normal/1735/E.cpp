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

void print(vector<ll> a)
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

ll L = -2e9;
ll R = 2e9;

bool check = true;

void upd(pair<ll, ll> pr, ll l, ll r)
{
    if (pr.first == 1)
    {
        L = max(L, l - pr.second);
        R = min(R, r - pr.second);
    }
    else
    {
        L = max(L, pr.second - r);
        R = min(R, pr.second - l);
    }
}

void dfs(ll val, set<ll> &visited, map<ll, pair<ll, ll>> &assigner, map<ll, ll> &cnta, map<ll, ll> &cntb, ll x1, ll x2)
{
    if (!check) return;
    visited.insert(val);

    //Processing a:
    ll dif = abs(val - x1);
    if (cnta.find(dif)==cnta.end()) upd(assigner[val], 0, 0);
    else
    {
        upd(assigner[val], 0, cnta[dif]);
        ll sym = 2*x1 - val;

        if (sym == val)
        {
            upd(assigner[val], cnta[dif], cnta[dif]);
        }
        else
        {
            pair<ll, ll> pr = {-assigner[val].first, cnta[dif] - assigner[val].second};
            if (assigner.find(sym)!=assigner.end())
            {
                if (assigner[sym]!=pr) {check = false; return;}
            }
            else
            {
                assigner[sym] = pr; dfs(sym, visited, assigner, cnta, cntb, x1, x2);
            }
        }
    }

    //Processing a:
    dif = abs(val - x2);
    if (cntb.find(dif)==cntb.end()) upd(assigner[val], 0, 0);
    else
    {
        upd(assigner[val], 0, cntb[dif]);
        ll sym = 2*x2 - val;

        if (sym == val)
        {
            upd(assigner[val], cntb[dif], cntb[dif]);
        }
        else
        {
            pair<ll, ll> pr = {-assigner[val].first, cntb[dif] - assigner[val].second};
            if (assigner.find(sym)!=assigner.end())
            {
                if (assigner[sym]!=pr) {check = false; return;}
            }
            else
            {
                assigner[sym] = pr; dfs(sym, visited, assigner, cnta, cntb, x1, x2);
            }
        }
    }
}

void solve()
{
    int n; cin>>n;
    vector<ll> a(n), b(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) cin>>b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    map<ll, ll> cnta, cntb;
    for (auto it: a) cnta[it]++;
    for (auto it: b) cntb[it]++;

    if (a == b)
    {
        cout<<"YES"<<endl;
        for (int i = 0; i<n; i++) cout<<a[i]<<' ';
        cout<<endl;
        cout<<0<<' '<<0<<endl;
        return;
    }

    set<ll> distances;
    for (int i = 0; i<n; i++)
    {
        distances.insert(abs(b[i] + a[0]));
        distances.insert(abs(b[i] - a[0]));
    }

    if (distances.count(0)) distances.erase(0);

    for (auto cand: distances)
    {
        check = true;
        ll x1 = 1e9;
        ll x2 = x1+cand;

        set<ll> possible1;
        for (auto it: a)
        {
            possible1.insert(x1 - it);
            possible1.insert(x1 + it);
        }

        set<ll> visited;

        map<ll, ll> answer;

        for (auto it: possible1) if (!visited.count(it))
        {
            map<ll, pair<ll, ll>> assigner;
            L = -2e9; R = 2e9;
            assigner[it] = {1, 0};
            dfs(it, visited, assigner, cnta, cntb, x1, x2);

            if (L>R) {check = false; break;}
            for (auto it: assigner)
            {
                answer[it.first] = L*it.second.first + it.second.second;
            }
        }

        if (check)
        {
            cout<<"YES"<<endl;
            vector<ll> ans;
            for (auto it: answer)
            {
                for (int i = 0; i<it.second; i++) ans.push_back(it.first);
            }

            //print(ans);
            //cout<<x1<<' '<<x2<<endl;


            ll minn = min(x1, x2);
            for (auto it: ans) minn = min(minn, it);

            //cout<<"DIST: "<<cand<<endl;

            //cout<<"Minn: "<<minn<<endl;

            for (auto &it: ans) it-=minn;
            x1-=minn; x2-=minn;

            print(ans);
            cout<<x1<<' '<<x2<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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
10
999609239 999619397 999621802 999688421 999774470 999810062 999821773 999857815 999914614 999965809
999648402 999943619 999953777 999788546 999941214 999874595 999705201 999597207 999752954 999741243
 */