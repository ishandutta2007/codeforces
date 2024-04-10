#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}


void main_solve(){
    ll a, m;
    cin >> a >> m;
    ll k = __gcd(a, m);
    ll ans = 0;
    ll b = m / k, x = b;
    vector <ll> v;
    for(ll i = 2; i * i <= x; i++)if(x % i == 0){
        v.p_b(i);
        while(x % i == 0){
            x /= i;
        }
    }
    if(x != 1)v.p_b(x);
    for(int i = 0; i < pw(sz(v)); i++){
        ll mt = 1;
        for(int j = 0; j < sz(v); j++)if((i & pw(j)))mt *= v[j];
        if((__builtin_popcount(i) & 1)){
            ans -= b / mt;
        }else ans += b / mt;
    }
    cout << ans << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        for(int id = 1; id <= t; id++){
            cout << "Test number " << id << ":\n";
            main_solve();
        }
    #else
        ll t;
        cin >> t;
        while(t--){
            main_solve();
        }
    #endif // LOCAL



    return 0;
}