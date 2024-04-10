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
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5;
const int MAXN = 1123456;
const ll inf = 3e18;
const ll mod = 1000000007;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    ll n;
    cin >> n;
    vector <ll> a(n), b(n);
    set <ll> st;
    ll ans = 0;
    vector <bool> f(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    for(int i = 0; i < n; i++){
        if(b[i] >= a[(i + 1) % n]){
            f[(i + 1) % n] = 1;
        }
    }
    if(*min_element(all(f)) == 1){
        fout(*min_element(all(a)));
    }else{
        ll ans = inf, temp = 0;
        for(int i = 0; i < n; i++){
            if(!f[i]){
                temp += a[i] - b[(i - 1 + n) % n];
            }
        }
        for(int i = 0; i < n; i++){
            if(!f[i]){
                ans = min(ans, temp - (a[i] - b[(i - 1 + n) % n]) + a[i]);
            }else{
                ans = min(ans, temp + a[i]);
            }
        }
        fout(ans);
    }
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
        solve();
    }

    return 0;
}