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


const int N = 1e6 + 5;

ll n, m, k;
vector<int> a, b;

vector<int> pos_a(N, -1), pos_b(N, -1);

vector<ll> together(N, -1);

ll LCM;

ll cnt(ll time)
{
    ll tot = time;
    for (int i = 0; i<N; i++) if (together[i]!=-1)
    {
        if (time<together[i]) continue;
        else tot-=((time - together[i])/LCM + 1);
    }
    return tot;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>m>>k;

    LCM = n*m/__gcd(n, m);

    a.resize(n); for (int i = 0; i<n; i++) cin>>a[i];
    b.resize(m); for (int i = 0; i<m; i++) cin>>b[i];


    for (int i = 0; i<n; i++) pos_a[a[i]] = i;
    for (int i = 0; i<m; i++) pos_b[b[i]] = i;

    vector<int> first_mod(m, -1);
    for (int i = 0; i<m; i++)
    {
        ll tmp = n*i;
        if (first_mod[tmp%m]==-1) first_mod[tmp%m] = i;
    }

    for (int i = 0; i<N; i++) if (pos_a[i]!=-1 && pos_b[i]!=-1)
    {
        //cout<<i<<": "<<pos_a[i]<<' '<<pos_b[i]<<endl;
        //pos_a[i] - pos_b[i] + c1*n = pos_b[i] + c2*m

        ll tmp = pos_a[i] - pos_b[i];

        ll need = m - tmp;
        if (need<0) need+=1e6 * m;
        need%=m;

        if (first_mod[need]!=-1) together[i] = 1 + pos_a[i] + first_mod[need] * n;
    }


    //for (int i = 0; i<N; i++) if (together[i]!=-1) cout<<i<<' '<<together[i]<<endl;


    for (int i = 0; i<n; i++) pos_a[a[i]] = i;
    for (int i = 0; i<m; i++) pos_b[b[i]] = i;

    ll L = 0; ll R = 1e18;

    while (R-L>1)
    {
        ll mid = (L+R)/2;
        if (cnt(mid)<k) L = mid; else R = mid;
    }

    cout<<R<<endl;

}
/*

 */

/*
1 + 2 + ... + n <= 5*10^6
n<=1000 or smth
 */