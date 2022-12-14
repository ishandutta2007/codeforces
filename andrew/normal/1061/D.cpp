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

const ll MOD = 1e9 + 7;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));

    ll n, x, y;
    cin >> n >> x >> y;

    ll ans = 0;

    multiset <ll> s;

    vector <pll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;

    sort(all(a));


    multiset <ll> :: iterator it;

    for(int i = 0; i < n; i++){
        ll l = a[i].fi, r = a[i].se;
        if(!s.empty() && (*s.begin() < l)){
            it = s.lower_bound(l);
            --it;
            ll time = *it;

            if(x + y * (r - l) > y * (r - time)){

                ans = (ans + y * (r - time)) % MOD;
                s.erase(it);
            }else{
                ans = (ans + x + y * (r - l)) % MOD;
            }
        }else{
            ans = (ans + x + y * (r - l)) % MOD;
        }
        s.insert(r);
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}