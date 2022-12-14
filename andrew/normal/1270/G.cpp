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
const ll mod = 998244353;
const ll MOD = mod * (mod - 2);
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}



void main_solve(){
    ll n;
    cin >> n;
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    vector <bool> f(n + 1);
    vector <ll> c, ans;
    ll s = 1;
    while(1){
        c.p_b(s);
        if(f[s])break;
        f[s] = 1;
        s = s - a[s];
    }
    reverse(all(c));
    ans.p_b(c[0]);
    for(int i = 1; i < sz(c); i++)if(c[i] != c[0]){
        ans.p_b(c[i]);
    }else break;
    cout << sz(ans) << "\n";
    for(auto i : ans)cout << i << " ";
    cout << "\n";
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
        ll t;
        cin >> t;
        while(t--){
            main_solve();
        }
    #endif // LOCAL

    return 0;
}