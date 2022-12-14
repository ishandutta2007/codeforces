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

vector <ll> v[MAXN];

void sol(){
    ll n;
    cin >> n;
    vector <pll> a(n);

    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;
    for(int i = 0; i < n; i++)swap(a[i].fi, a[i].se);

    for(int i = 0; i <= n; i++)v[i].clear();

    for(int i = 0; i < n; i++)v[a[i].se].p_b(i);

    ll kol = n;

    ll ans = 0;

    multiset <ll> s;

    ll cnt = 0;

    for(int i = n - 1; i >= 0; i--){
        for(auto j : v[i]){
            kol--;
            s.insert(a[j].fi);
        }
        if(kol + cnt >= i){
            continue;
        }else{
            ll d = i - kol - cnt;
            while(d--){
                cnt++;
                ans += *s.begin();
                s.erase(s.begin());
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll t;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}