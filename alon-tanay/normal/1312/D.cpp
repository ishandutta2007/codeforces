#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const int MOD = 998244353;
const ll MODL = 998244353;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

const int mxN = 500005;
ll fact[mxN];
ll invfact[mxN];

ll pw(ll b, ll e) {
    if(e == 0) { return 1;}
    if(e&1) {
        return (b*pw((b*b)%MOD,e/2))%MOD;
    }
    return pw((b*b)%MOD,e/2);
}

ll choose(ll n, ll k) {
    if(n < k || k < 0) { return 0;}
    return (((fact[n]*invfact[n-k])%MOD)*invfact[k])%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for(ll i = 1; i < mxN; i ++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    invfact[mxN-1] = pw(fact[mxN-1],MOD-2);
    for(ll i = mxN - 1; i; i --) {
        invfact[i-1] = (invfact[i]*i)%MOD;
    }

    ll n, m;
    cin >> n >> m;
    ll res = 0;
    for(ll lst = 0; lst <= m; lst ++) {
        if(lst < n - 1) { continue; }
        ll x = lst - (n-1);
        res += choose(n-2+x,x);
        // cout << choose(n-2+x,x) << endl;
        res %= MOD;
    }
    res *= (n-2);
    res %= MOD;
    res *= pw(2,n-3);
    res %= MOD;
    cout << res;
    return 0;
}