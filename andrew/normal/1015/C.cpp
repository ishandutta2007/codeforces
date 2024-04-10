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
    vector < pair<ll, pll> > a(n);
    ll s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].se.fi >> a[i].se.se;
        s += a[i].se.fi;
        a[i].fi = a[i].se.fi - a[i].se.se;
    }
    sort(all(a));
    reverse(all(a));
    for(int i = 0; i < n; i++){
        if(s <= m)vout(i);
        s -= a[i].fi;
    }
    if(s <= m)vout(n);
    vout(-1);
    return 0;
}