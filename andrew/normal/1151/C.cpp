#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;
const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= MOD;
        (a *= a) %= MOD;
        n >>= 1;
    }
    return res;
}

ll nc(ll a){
    return ((a % MOD) * (a % MOD)) % MOD;
}

ll c(ll a){
    ll x = ((2 * a) % MOD) * ((2 * a) % MOD + 1);
    x %= MOD;
    x *= bp(2, MOD - 2);
    x %= MOD;
    x -= nc(a);
    if(x < 0)x += MOD;
    return x;
}

ll f(ll x){
    ll shag = 0, step = 1;

    ll uk = 1, uk1 = 1, ans = 0;

    while(x){
        ll k = min(step, x);
        ll sum = 0;
        if(shag == 0){
            sum += nc(uk1 + k - 1);
            sum -= nc(uk1 - 1);
            if(sum < 0)sum += MOD;
            uk1 += k;
        }else{
            sum += c(uk + k - 1);
            sum -= c(uk - 1);
            uk += k;
            if(sum < 0)sum += MOD;
        }
        ans += sum;
        ans %= MOD;
        x -= k;
        step *= 2;
        shag = 1 - shag;
    }
    return ans;

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll l, r;
    cin >> l >> r;

    ll ans = f(r) - f(l - 1);
    if(ans < 0)ans += MOD;
    ans %= MOD;
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}