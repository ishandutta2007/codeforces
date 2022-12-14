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
#define fout(x) {cout << x << endl;return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e3;
const ll inf = 2e9;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}


ll f(ll x){
    ll res = 0;
    while(x >= 10){
        res++;
        x /= 10;
    }
    return res;
}

void solve(){
    ll a, b;
    cin >> a >> b;
    ll res = f(b);
    bool fl = 1;
    while(b){
        if(b % 10 != 9)fl = 0;
        b /= 10;
    }
    if(fl)res++;
    cout << res * a << "\n";
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

    while(t--)solve();

    return 0;
}