#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

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


const int MOD =  998244353;

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

/*
const int LIM = 1e6 + 5;

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
}*/


/*struct DSU
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
        else
        {
            auto par = find_set(parent[v]);
            parent[v] = par;
            return par;
        }
    }

    void union_sets(int a, int b) {
        find_set(a);
        find_set(b);

        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        };
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

ll n, C;

const ll INF = 1e18;

ll ans(ll x, ll y)
{
    return max(max(abs(x), abs(y)), abs(x+y));
}


set<pair<ll, ll>> guys;

bool check(ll x)
{
    auto pos = guys.lower_bound(mp(x+1, -INF));
    if (pos==guys.begin()) return false;
    pos--; auto kek = *pos;
    if (kek.first<=x && kek.second>=x) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>C;
    vector<ll> w(n-2); for (int i = 0; i<n-2; i++) cin>>w[i];

    vector<ll> coeff(n-1);
    vector<ll> cnst(n-1);

    vector<set<pair<ll, ll>>> to_del(n), to_add(n);

    guys.insert(mp(0, w[0]));

    to_add[0].insert(mp(0, w[0]));
    coeff[0] = 1; cnst[0] = 0;





    for (int i = 1; i<n-2; i++)
    {
        /*cout<<"ITER "<<i-1<<": "<<endl;
        cout<<"Pairs: "<<endl;
        for (auto it: guys) cout<<it.first<<' '<<it.second<<endl;
        cout<<"Coeff: "<<coeff[i-1]<<"*x+"<<cnst[i-1]<<endl;
        cout<<endl;*/

        if (guys.empty()) {cout<<"NO"<<endl; return 0;}

        /*
         if w[i-1] in guys, we can just reset to [0, min(w[i-1], w[i])
          */

        ll val = (w[i-1] - cnst[i-1]) * coeff[i-1];

        if (check(val))
        {
            for (auto it: guys) to_del[i].insert(it);
            guys.clear();
            guys.insert(mp(0, min(w[i-1], w[i])));
            to_add[i].insert(mp(0, min(w[i-1], w[i])));

            coeff[i] = 1; cnst[i] = 0;
            continue;
        }

        ll L = 0;
        ll R = min(w[i-1], w[i]);

        coeff[i] = -coeff[i-1];
        cnst[i] = w[i-1] - cnst[i-1];

        ll valL = (L - cnst[i]) * coeff[i];
        ll valR = (R - cnst[i]) * coeff[i];

        if (valL>valR) swap(valL, valR);

        while (true)
        {
            if (guys.empty()) break;
            auto it = *guys.begin();
            if (it.first>=valL) break;

            if (it.second<valL)
            {
                to_del[i].insert(it);
                guys.erase(it);
            }
            else
            {
                to_del[i].insert(it);
                guys.erase(it);
                to_add[i].insert(mp(valL, min(it.second, valR)));
                guys.insert(mp(valL, min(it.second, valR)));
            }
        }

        while (true)
        {
            if (guys.empty()) break;
            auto it = *prev(guys.end());
            if (it.second<=valR) break;

            if (it.first>valR)
            {
                to_del[i].insert(it);
                guys.erase(it);
            }
            else
            {
                to_del[i].insert(it);
                guys.erase(it);
                to_add[i].insert(mp(max(valL, it.first), valR));
                guys.insert(mp(max(valL, it.first), valR));
            }
        }

        if (w[i-1]<=w[i])
        {
            ll good = (w[i-1] - cnst[i]) * coeff[i];

            if (!check(good))
            {
                guys.insert(mp(good, good));
                to_add[i].insert(mp(good, good));
            }
        }
    }

    if (guys.empty()) {cout<<"NO"<<endl; return 0;}

    vector<ll> diff(n-1);

    diff[n-2] = w[n-3];

    for (int i = n-3; i>=0; i--)
    {

        ll cur = abs(diff[i+1]);

        if (cur==w[i])
        {
            diff[i] = ((*guys.begin()).first)*coeff[i] + cnst[i];

        }
        else
        {
            //2 options: w[i] and w[i] - cur;

            for (auto cand: {w[i], w[i] - cur})
            {

                ll val = (cand  - cnst[i]) * coeff[i];

                if (check(val))
                {
                    diff[i] = cand; break;
                }

            }

        }


        if (ans(diff[i], diff[i+1])!=w[i]) diff[i]*=-1;
        for (auto it: to_add[i]) guys.erase(it);
        for (auto it: to_del[i]) guys.insert(it);
    }


    /*for (auto it: diff) cout<<it<<' ';
    cout<<endl;*/

    vector<ll> a(n);
    for (int i = 1; i<n; i++) a[i] = a[i-1] + diff[i-1];

    ll minn = *min_element(a.begin(), a.end());

    for (int i = 0; i<n; i++) a[i]-=minn;

    cout<<"YES"<<endl;

    for (auto it: a) cout<<it<<' ';


        /*
         Done, now no array contains that shit, and we need to add w[i-1] or reverse

         The new guy has to be in range [0, min(w[i-1],
         */




}
/*

 */

/*

1 1 2
1 3 3
2 3 2
 */