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

ll func(ll r, ll a, ll b, ll ra, ll rb){
    ll ca = min(ra, r / a);
    r -= ca * a;
    ll res = ca;
    ca = min(rb, r / b);
    return res + ca;
}

void main_solve(){
    ll t;
    cin >> t;
    while(t--){
        ll n, T, a, b;
        cin >> n >> T >> a >> b;
        vector <ll> f(n);
        vector <ll> t(n);
        for(int i = 0; i < n; i++)cin >> f[i];
        for(int i = 0; i < n; i++)cin >> t[i];
        set <ll> time;
        map <ll, vector <ll>> mp;
        ll kolA = 0;
        for(int i = 0; i < n; i++){
            if(f[i] == 0){
                kolA++;
            }
            time.insert(t[i]);
            mp[t[i]].p_b(i);
        }
        ll ans = 0, start = 0, kola = 0, kol = 0;
        time.insert(T);
        time.insert(T + 1);
        if(*time.begin() != 0)ans = func(*time.begin() - 1, a, b, kolA, n - kolA);

        for(auto d : time){
            if(d == T + 1)break;
            for(auto j : mp[d]){
                if(f[j] == 0){
                    kola++;
                    start += a;
                }else start += b;
                kol++;
            }
            ll nt = *time.upper_bound(d);
            if(start >= nt || start > T)continue;
            ans = max(ans, kol + func(nt - start - 1, a, b, kolA - kola, n - kolA - (kol - kola)));
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