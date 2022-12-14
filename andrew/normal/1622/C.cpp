#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n);    
    ll s = 0;
    for(auto &i : a){
        cin >> i;
        s += i;
    }
    sort(all(a));

    ll sc = 0;
    ll ans = 1e18;

    if(s <= k) fout(0);
    
    for(int i = 0; i < n; i++){
        ll t = s - sc;
        if(t <= k){
            ans = min(ans, (ll)i);
        }else{
            ll r = i + ((t - k) / (i + 1));
            if((t - k) % (i + 1))r++;  
            ans = min(ans, r);
        }        
        sc += a[n - i - 1] - a[0];
    }
    cout << ans << "\n";
}

int main(){

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    

    int t;
    cin >> t;
    while(t--){
        solve();
    }


    return 0;
}