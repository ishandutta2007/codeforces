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
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
bitset <101> s[101];
ll p[101];
ll get(ll x){
    if(p[x] != x)p[x] = get(p[x]);
    return p[x];
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
 
    ll n, m;
    cin >> n >> m;
 
    ll S = 0;
 
    for(int i = 1; i <= n; i++){
        p[i] = i;
        ll k;
        cin >> k;
        S += k;
        while(k--){
            ll j;
            cin >> j;
            s[i][j] = 1;
        }
    }
 
    if(!S)vout(n);
 
    ll ans = n - 1;
 
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)if((s[i] & s[j]).any()){
            if(get(i) != get(j)){
                p[get(i)] = get(j);
                ans--;
            }
        }
 
    cout << ans << "\n";
 
    return 0;
}