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
const ll N = 1e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
void main_solve(){
    ll t;
    cin >> t;
    while(t--){
        ll n, p, k;
        cin >> n >> p >> k;
        vector <ll> a(n), pref(n);
        for(int i = 0; i < n; i++)cin >> a[i];
        sort(all(a));
        pref[0] = a[0];
        for(int i = 1; i < n; i++)pref[i] = pref[i - 1] + a[i];
        ll ans = 0, S = 0;
        for(int i = 1; i <= n; i++){
            if(pref[i - 1] <= p)ans = max(ans, (ll)i);
        }
        ll cost = 0;
        map <ll, ll> mp;
        for(int i = 0; i < n; i++){
            cost += a[i];
            ll ct = 0;
            mp[i % k] += a[i];
            ll pos = (i + 1) % k;
 
            if((pos < 2 ? 0 : pref[pos - 2]) + mp[i % k] <= p)ans = max(ans, ll(i + 1));
        }
        cout << ans << "\n";
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
        ll number = 0;
        while(t--){
            ++number;
            cout << "Test: " << number << "\n";
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL
 
 
    return 0;
}