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

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

const int mxN = 500005;

ll pw(ll b, ll e) {
    if(e == 0) { return 1LL; }
    if(e&1) {
        return (b*pw((b*b)%MODL,e/2))%MODL;
    }
    return pw((b*b)%MODL,e/2);
}

ll fact[mxN];
ll invfact[mxN];

ll choose(ll n, ll k) {
    return (((fact[n]*invfact[k])%MODL)*invfact[n-k])%MODL;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for(ll i = 1; i < mxN; i ++) {
        fact[i] = (fact[i-1]*i)%MODL;
    }
    invfact[mxN-1] = pw(fact[mxN-1],MODL-2);
    for(ll i = mxN-1; i; i --) {
        invfact[i-1] = (invfact[i]*i)%MODL;
    }

    int n;
    cin >> n;
    ll res = 0;
    for(int i = 0; i <= n; i ++) {
        ll x;
        cin >> x;
        if(x == 0) { continue;}
        res += choose(i+x,i+1);
        res %= MODL;
    }
    cout << res;
    return 0;
}