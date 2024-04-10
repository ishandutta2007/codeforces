#include <bits/stdc++.h>

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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--){
        ll x, y, k;
        cin >> x >> y >> k;
        if(x > y)swap(x, y);
        if(y > k){
            cout << "-1\n";
            continue;
        }
        if(x % 2 != y % 2){
            ll rust = y;
            ll ans = rust - 1;
            k -= rust;
            ans += k;
            cout << ans << endl;
        }else{

            ll rust = y;
            ll ans = rust;
            if((k - rust) % 2){
                ans--;
                k -= rust + 1;
                ans += k;
            }else if(k - rust > 1)ans += k - rust;
            cout << ans << endl;
        }
    }
    return 0;
}