#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, k, ans = 0;
    map <ll, ll> mp;
    cin >> n >> k;
    vector <ll> v;
    v.p_b(1);
    ll x = k;
    while(abs(k) <= 1e15){
        if(k == 1)break;
        v.p_b(k);
        k *= x;
    }
    ll sc = 0;
    mp[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> x;
        sc += x;
        for(auto it : v)ans += mp[sc - it];
        mp[sc]++;
    }
    cout << ans << "\n";
    return 0;
}