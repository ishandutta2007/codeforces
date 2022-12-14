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

map <ll, ll> mp;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n);
    set <ll> s;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        a[i] = x;
        s.insert(x - m);
        s.insert(x + m);
    }
    ll ans = 0;
    for(auto i : s){
        ll mn = 1e18;
        for(int j = 0; j < n; j++)mn = min(mn, abs(a[j] - i));
        if(mn == m)ans++;
    }
    cout << ans << endl;
    return 0;
}