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
    vector <pll> a(n);
    set <ll> s;
    for(int i = 0; i < n; i++){
        cin >> a[i].fi >> a[i].se;
        s.insert(a[i].fi);
        if(s.size() > 2)s.erase(s.begin());
    }
    ll ans = 0;
    for(auto i : s){
        ll x = i;
        ll l = x, r = 1e9;
        while(l < r){
            ll c = (l + r) >> 1;
            if(l == c)c++;
            ll kol = 0;
            for(int i = 0; i < n; i++)if(a[i].fi <= x && c <= a[i].se)kol++;
            if(kol >= n - 1)l = c; else r = c - 1;
        }
        ans = max(ans, l - x);
    }
    cout << ans << endl;
    return 0;
}