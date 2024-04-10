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
        ll n, s;
        cin >> n >> s;
        vector <ll> a(n + 1);
        for(int i = 1; i <= n; i++)cin >> a[i];
        pll ans = {0, 0};
        ll mx = 0, sc = 0, t = 0;
        for(int i = 1; i <= n; i++){
            sc += a[i];
            mx = max(mx, a[i]);
            if(mx == a[i])t = i;
            if(sc <= s)ans = max(ans, {ll(i), 0ll});
            if(sc - mx <= s)ans = max(ans, {ll(i - 1), ll(t)});
        }
        cout << ans.se << "\n";
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