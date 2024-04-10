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

ll f(ll x){
    return 1ll << x;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, l, r, x;
    cin >> n >> l >> r >> x;
    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    ll musk = 1ll << n;

    ll ans = 0;
    for(int i = 1; i < musk; i++){
        ll sc = 0, mx = -1e18, mn = 1e18;
        for(int j = 0; j < n; j++)if(f(j) & i){
            sc += a[j];
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
        }
        if(l <= sc && sc <= r && mx - mn >= x)ans++;
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}