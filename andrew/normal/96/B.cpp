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

    ll n;
    cin >> n;
    ll ans = 1e18;
    for(int len = 1; len < 15; len++){
        ll m = 1ll << len;
        for(int i = 0; i < m; i++){
            ll x = 0, step = 1;
            ll kol1 = 0, kol2 = 0;
            for(int j = 0; j < len; j++, step *= 10){
                if(((1ll << j) & i))x += step * 4, kol1++;
                else x += step * 7, kol2++;
            }
            if(kol1 == kol2 && x >= n)ans = min(ans, x);
        }
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}