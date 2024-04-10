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

int MOD =  998244353;

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
const int LIM = 100000;

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

/*
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
};*/

ll MMM = 1ll*10000*(1<<30);

ll v;

ll read()
{
    string s; cin>>s;
    while (s.size()<6) s+='0';
    ll ans = 0;
    for (int i = 2; i<6; i++) ans = (ans*10+(s[i]-'0'));
    return ans*(1<<30);
}

ld solve(ll c)
{
    ld ans = 0;
    ans+=(ld)(MMM-c)/(ld)(MMM);
    //Choosing 2:
    if (c>v) ans+=((ld)(c)/(ld)(MMM))*(1.0+solve(c-v));
    else ans+=((ld)(c)/(ld)(MMM))*2.0;

    //cout<<c<<": "<<ans<<endl;

    return ans;
}

ld solve(ll c, ll m)
{

    ld ans = 0;

    //Choosing 3:
    ans+=(ld)(MMM-c-m)/(ld)(MMM);

    //Choosing 1:
    if (c>v) ans+=((ld)(c)/(ld)(MMM))*(1.0+solve(c-v, m+(v/2)));
    else ans+=((ld)(c)/(ld)(MMM))*(1.0+solve(m+(c/2)));

    swap(m, c);

    //Choosing 2:
    if (c>v) ans+=((ld)(c)/(ld)(MMM))*(1.0+solve(c-v, m+(v/2)));
    else ans+=((ld)(c)/(ld)(MMM))*(1.0+solve(m+(c/2)));

    //cout<<c<<' '<<m<<": "<<ans<<endl;
    return ans;

}

void solve()
{

    ld c, m, p; //cin>>c>>m>>p>>v;

    c = read(); m = read(); p = read(); v = read();

    cout<<setprecision(10)<<fixed<<solve(c, m)<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while (t--) solve();

}

/*
1
0.2 0.2 0.6 0.2
 */


/*
0.6 + 0.4 * solve(0.3, 0)
 */