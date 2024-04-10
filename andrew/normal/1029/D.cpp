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
unordered_map <ll,ll> mp[11];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector <pll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].fi;
        ll x = a[i].fi;
        while(x){
            a[i].se++;
            x /= 10;
        }
        a[i].fi %= k;
        mp[a[i].se][a[i].fi]++;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        mp[a[i].se][a[i].fi]--;
        ll chislo = a[i].fi;
        for(int j = 1; j <= 10; j++){
            chislo *= 10;
            while(chislo >= k)chislo -= k;
            ll ost = (k - chislo) % k;
            if(mp[j].find(ost) != mp[j].end())ans += mp[j][ost];
        }
        mp[a[i].se][a[i].fi]++;
    }
    cout << ans << endl;
    return 0;
}