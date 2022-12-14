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


ll f(ll x){
    return ((x + 1) / 2) * (x / 2 + 1);
}

ll func(string s){
    ll ans = 0;
    for(int i = 0; i < sz(s); i++){
        bool fl = 0;
        for(int j = i; j < sz(s); j++){
            if(s[j] == '1')fl = 1;
            if(fl)ans++;
        }
    }
    cout << ans << "\n";
}

ll get(ll n, ll f, ll d){
    return (n * (f + f + d * (n - 1))) / 2;
}

void main_solve(){
    ll n, m;
    cin >> n >> m;
    if(!m)fout(0);
    ll d = (n - m) / (m + 1);
    ll kol = (n - m) % (m + 1);
    ll ans = (d + 2) * get(kol, n - (d + 1), -d - 2);
    ans += (d + 1) * get(m - kol, n - d - (d + 2) * kol, -d - 1);
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