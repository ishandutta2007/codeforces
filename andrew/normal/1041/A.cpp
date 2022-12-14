#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
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
    ll n;
    cin >> n;
    ll mx, mn;
    mx = -1e18, mn = 1e18;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    cout << mx - mn + 1 - n << endl;
    return 0;
}