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
    int n;
    vector<int> sz;
    vector<int> parent;
    vector<int> pos; //From parent
    vector<int> gcd;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_pos(int v)
    {
        if (v==parent[v])
            return 0;
        return (pos[v] + find_pos(parent[v]))%n;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    ll eval(int v)
    {
        v = find_set(v);
        return gcd[v];
    }

    void union_sets(int a, int b, int d) {
        int da = find_pos(a);
        int db = find_pos(b);

        int diff = (da + d - db + n)%n;

        //cout<<"DIFF: "<<diff<<endl;

        if (find_set(a) == find_set(b))
        {
            a = find_set(a);
            gcd[a] = __gcd(gcd[a], diff);
        }
        else
        {
            a = find_set(a);
            b = find_set(b);

            if (sz[a] < sz[b])
            {
                swap(a, b);
                diff = (n - diff)%n;
            }
            parent[b] = a;
            sz[a] += sz[b];
            pos[b] = diff;
            gcd[a] = __gcd(gcd[a], gcd[b]);
        }

    }

    DSU (int N)
    {
        n = N;
        parent.resize(n);
        sz.resize(n);
        gcd = vector<int>(n, n);
        pos = vector<int>(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};

void print(vector<int> a)
{
    for (auto it: a) cout<<it+1<<' ';
    cout<<endl;
}

void print(vector<bool> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

void print(vector<pair<ll, ll>> a)
{
    for (auto it: a) cout<<it.first<<' '<<it.second<<"| ";
    cout<<endl;
}

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

vector<int> find(int n)
{
    init();
    vector<vector<int>> eval(n, vector<int>(n));
    eval[n-1][n-1] = 1;
    for (int i = n-2; i>=0; i--)
    {
        eval[i][i] = 1;
        for (int pos = i+1; pos<n; pos++)
        {
            int ways = C(pos, i);
            for (int j = 0; j<n; j++) eval[i][j]-=ways*eval[pos][j];
        }
    }

    /*for (int i = n-1; i>=0; i--)
    {
        cout<<i<<": "; print(eval[i]);
    }*/

    vector<int> vec(n);
    for (int i = 0; i<n; i++) vec[i] = eval[0][i] + eval[1][i];

    return vec;
}

vector<int> min_prime(LIM, -1);

int n;

vector<vector<pair<int, int>>> divs;

vector<pair<int, int>> lcm(vector<int> pos)
{
    set<int> primes;
    for (auto i: pos)
    {
        for (auto it: divs[i]) primes.insert(it.first);
    }

    vector<pair<int, int>> ans;
    for (auto pr: primes)
    {
        vector<int> vals;
        for (auto i: pos)
        {
            int cnt = 0;
            for (auto it: divs[i]) if (it.first == pr) cnt = it.second;

            vals.push_back(cnt);
        }
        sort(vals.begin(), vals.end());
        ans.push_back(mp(pr, vals.back()));
    }

    sort(ans.begin(), ans.end());
    return ans;
}

vector<pair<int, int>> eval(vector<int> pos)
{
    set<int> primes;
    for (auto i: pos)
    {
        for (auto it: divs[i]) primes.insert(it.first);
    }

    vector<pair<int, int>> ans;
    for (auto pr: primes)
    {
        vector<int> vals;
        for (auto i: pos)
        {
            int cnt = 0;
            for (auto it: divs[i]) if (it.first == pr) cnt = it.second;

            vals.push_back(cnt);
        }
        sort(vals.begin(), vals.end());
        if (vals.size()>=2 && vals[0]+vals[1]>0) ans.push_back(mp(pr, vals[0]+vals[1]));
    }

    sort(ans.begin(), ans.end());
    return ans;
}

vector<int> cur;

bool reduce()
{
    if (cur.size()<=2) return false;
    //cout<<"EVALING"<<endl;
    auto res = eval(cur);
    /*for (auto it: cur) cout<<it<<' ';
    cout<<": ";
    print(res);*/

    int k = cur.size();
    for (int i = 0; i<k; i++)
    {
        vector<int> tmp;
        for (int j = 0; j<k; j++) if (j!=i) tmp.push_back(j);

        /*for (auto it: tmp) cout<<it<<' ';
        cout<<": ";*/

        auto kek = eval(tmp);

        //print(kek);

        if (kek == res)
        {
            cur = tmp; return true;
        }
    }

    //cout<<"OVER"<<endl;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    for (int i = 2; i<LIM; i++)
    {
        if (min_prime[i]==-1)
        {
            min_prime[i] = i;
            if (i<LIM/i)
            {
                for (int j = i*i; j<LIM; j+=i) if (min_prime[j]==-1) min_prime[j] = i;
            }
        }
    }

    cin>>n;
    divs.resize(n);
    vector<int> a(n);

    for (int i = 0; i<n; i++) cin>>a[i];

    for (int i = 0; i<n; i++)
    {
        int x = a[i];
        while (x!=1)
        {
            int pr = min_prime[x];
            int cnt = 0;
            while (x%pr == 0)
            {
                x/=pr; cnt++;
            }
            divs[i].push_back(mp(pr, cnt));
        }
    }

    set<int> good;
    good.insert(0); good.insert(1);

    set<int> present;
    for (auto it: divs[0]) present.insert(it.first);
    for (auto it: divs[1]) present.insert(it.first);

    for (auto pr: present)
    {
        vector<pair<int, int>> b;
        for (int i = 0; i<n; i++)
        {
            int tmpcnt = 0;
            for (auto it: divs[i]) if (it.first==pr) tmpcnt = it.second;
            b.push_back(mp(tmpcnt, i));
        }
        sort(b.begin(), b.end());
        good.insert(b[0].second);  good.insert(b[1].second);
    }

    for (auto it: good) cur.push_back(it);

    //print(cur);

    while (true)
    {
        //print(cur);
        bool check = reduce();
        //cout<<check<<endl;
        if (!check) break;
    }

    //cout<<"OVER"<<endl;

    int sz = cur.size();

    if (sz<=1)
    {
        cout<<0<<endl; return 0;
    }

    auto who = find(sz);

    //print(who);

    map<vector<pair<int, int>>, vector<int>> representative;
    map<vector<pair<int, int>>, int> amount;

    for (int mask = (1<<sz)-1; mask>=1; mask--)
    {
        vector<int> setbits;
        for (int i = 0; i<sz; i++) if (mask&(1<<i)) setbits.push_back(cur[i]);
        int cursz = setbits.size();

        auto res = lcm(setbits);

        /*print(res);
        print(setbits);
        cout<<endl;*/

        representative[res] = setbits;
        amount[res]+=who[cursz-1];
    }

    vector<vector<int>> pos, neg;

    for (auto it: representative)
    {
        /*print(it.first);
        print(it.second);
        cout<<amount[it.first]<<endl;
        cout<<endl;*/
        if (amount[it.first]>0)
        {
            for (int i = 0; i<amount[it.first]; i++) pos.push_back(it.second);
        }
        else
        {
            for (int i = 0; i>amount[it.first]; i--) neg.push_back(it.second);
        }
    }

    cout<<neg.size() + pos.size()<<endl;
    for (auto vec: pos)
    {
        cout<<0<<' '<<vec.size()<<' '; print(vec);
    }
    for (auto vec: neg)
    {
        cout<<1<<' '<<vec.size()<<' '; print(vec);
    }
}