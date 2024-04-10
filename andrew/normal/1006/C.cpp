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

unordered_map <ll,ll> mp;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector <ll> pref(n), a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i] = a[i];
        if(i > 0)pref[i] += pref[i - 1];
        mp[pref[i]]++;
    }
    ll ans = 0, sc = 0;
    for(int i = n; i > 0;){
        i--;
        mp[pref[i]]--;
        sc += a[i];
        if(mp[sc])ans = sc;
    }
    cout << ans << "\n";
}