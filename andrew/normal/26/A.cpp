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

ll what(ll x){
    for(int i = 2; i * i <= x; i++)if(x % i == 0)return i;
    return x;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll ans = 0;
    for(int i = 2; i <= n; i++){
        ll x = i, y = what(x);
        while(x % y == 0)x /= y;
        if(x != 1){
            y = what(x);
            while(x % y == 0)x /= y;
            if(x == 1)ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}