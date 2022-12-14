#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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
map <ll,ll> mp;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
   ll ans, n;
   cin >> n;
   ans = 0;
   vector <ll> a(n);
   for(int i = 0; i < n; i++){
    cin >> a[i];
    mp[a[i]]++;
   }
   for(int i = 0; i < n; i++){
        bool fl = 0;
        mp[a[i]]--;
        for(int j = 0; j < 40; j++)if(mp[(1ll << j) - a[i]])fl = 1;
        if(!fl)ans++;
        mp[a[i]]++;
   }
   cout << ans << endl;
    return 0;
}