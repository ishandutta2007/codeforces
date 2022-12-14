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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void main_solve(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll x = 2;
        while(x * x <= n && n % x)x++;
        if(x * x > n){
            cout << "NO\n";
        }else{
            ll a = x, v = n / x;
            bool bad = 1;
            for(ll b = 2; b * b < v; b++)if(v % b == 0){
                if(a != b && a != v / b){
                    bad = 0;
                    cout << "YES\n" << a << " " << b << " " << v / b << "\n";
                    break;
                }
            }
            if(bad)cout << "NO\n";
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        while(t--){
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL



    return 0;
}