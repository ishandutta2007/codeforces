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

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

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

map <ll, ll> mp;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll N = 1e6, res = 1;
    set <ll> s;
    for(int i = 2; i <= 1e6; i++)if(n % i == 0){
        while(n % i == 0){
            mp[i]++;
            n /= i;
        }
        s.insert(mp[i]);
        res *= i;
    }
    ll ans = 0;


    for(auto &i : mp){
        ll x = i.se, sc = 0;
        if(s.size() > 1)sc = 1;
        if(x > 1){
            if((x & (x - 1)))sc = 1;
            for(int i = 0; i <= 40; i++)if((1ll << i) >= x){
                x = 1ll << i;
                break;
            }
            while(x > 1){
                sc++;
                x >>= 1;
            }
        }
        ans = max(ans, sc);
    }
    cout << res << " " << ans << "\n";
    return 0;
}