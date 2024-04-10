#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("fence.in","r",stdin);
    //freopen("fence.out","w",stdout);

    ll q;
    cin >> q;

    while(q--){
        ll x;
        cin >> x;

        ll kek = 180;

        ll ans = 1e18;
        ld t;
        for(int i = 1; i <= 360; i++){
            t = ld(180) / i;
            ll k = x / t;
            if(abs(k * t - x) <= 1e-9 && k <= i - 2)ans = min(ll(i), ans);
        }
        if(ans == 1e18)ans = -1;
        cout << ans << "\n";

    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}