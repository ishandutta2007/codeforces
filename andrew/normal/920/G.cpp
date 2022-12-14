#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define delete kek_void

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

bool fl[MAXN];
vector <ll> a;
ll last[MAXN];

ll f(ll x){
    if(a.empty())return x;
    ll ans = 0;
    for(int i = 0; i < pw(a.size()); i++){
        bool fx = 1;
        ll pr = 1;
        for(int j = 0; j < a.size(); j++)if((i & pw(j))){
            fx ^= 1;
            pr *= a[j];
        }
        if(fx)ans += x / pr; else ans -= x / pr;
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i <= 1e6; i++)if(!fl[i]){
        last[i] = i;
        if(ll(i) * ll(i) <= 1e6)for(int j = i * i; j <= 1e6; j += i)last[j] = i, fl[j] = 1;
    }

    ll t;
    cin >> t;

    while(t--){
        ll x, p, k;
        cin >> x >> p >> k;
        ll l = x + 1, r = 1e7;
        a.clear();

        while(p != 1){
            ll k = last[p];
            a.p_b(k);
            while(p % k == 0)p /= k;
        }

        while(l < r){
            ll c = (l + r) >> 1;
            if(f(c) - f(x) < k)l = c + 1; else r = c;
        }
        cout << l << "\n";
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}