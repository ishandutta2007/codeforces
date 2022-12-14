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
    vector <pair<pll,pll> > a(n);
    set <ll> s, s1;
    for(int i = 0; i < n; i++){
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se.fi >> a[i].se.se;
        s.insert(a[i].fi.fi);
        if(s.size() > 2)s.erase(s.begin());
        s1.insert(a[i].fi.se);
        if(s1.size() > 2)s1.erase(s1.begin());
    }

    for(auto it : s){
        for(auto it1 : s1){
            ll y = it, x = it1;
            ll kol = 0;
            for(int i = 0; i < n; i++)if(a[i].fi.fi <= y && y <= a[i].se.fi && a[i].fi.se <= x && x <= a[i].se.se)kol++;
            if(kol >= n - 1){
                cout << y << " " << x << endl;
                return 0;
            }
        }
    }
    return 0;
}