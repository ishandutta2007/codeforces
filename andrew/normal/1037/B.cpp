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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(all(a));
    ll k = n / 2;
    if(a[k] == m)vout(0);
    if(a[k] < m){
        ll ans = 0;
        for(int i = k; i < n; i++)ans += max(0ll, m - a[i]);
        vout(ans);
    }
    ll ans = 0;
    for(int i = 0; i <= k; i++)ans += max(0ll, a[i] - m);
    vout(ans);
    return 0;
}