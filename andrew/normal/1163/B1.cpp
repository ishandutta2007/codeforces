#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

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

    ll n;
    cin >> n;
    map <ll, ll> mp;
    set <pll> s;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        if(mp[x])s.erase({mp[x], x});
        mp[x]++;
        s.insert({mp[x], x});
        if(s.size() == 1)ans = i; else{
            pll xe = *s.begin();
            s.erase(s.begin());
            if(xe.fi != 1)s.insert({xe.fi - 1, xe.se});
            if(s.begin() -> fi == (--s.end()) -> fi){
                ans = i;
            }
            s.erase({xe.fi - 1, xe.se});
            s.insert(xe);

            xe = *--s.end();
            s.erase(--s.end());
            if(xe.fi != 1)s.insert({xe.fi - 1, xe.se});
            if(s.begin() -> fi == (--s.end()) -> fi){
                ans = i;
            }
            s.erase({xe.fi - 1, xe.se});
            s.insert(xe);
        }
    }
    cout << ans << "\n";


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}