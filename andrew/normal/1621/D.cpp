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
const ll inf = -1e18;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){   
    ll n;
    cin >> n;
    vector <vector <ll>> c(2 * n + 1, vector <ll> (2 * n + 1, 0));
    ll ans = 1e18;
    ll s = 0;
    for(int i = 1; i <= 2 * n; i++){
        for(int j = 1; j <= 2 * n; j++) cin >> c[i][j];
    }
    for(int i = n + 1; i <= 2 * n; i++)
        for(int j = n + 1; j <= 2 * n; j++) s += c[i][j];

    ll t = 1e18;
    t = min(t, c[1][n + 1]);
    t = min(t, c[1][2 * n]);
    t = min(t, c[n][n + 1]);
    t = min(t, c[n][2 * n]);
    t = min(t, c[n + 1][1]);
    t = min(t, c[n + 1][n]);
    t = min(t, c[2 * n][1]);
    t = min(t, c[2 * n][n]);    
    cout << s + t << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //cin >> t;
    #endif      

    cin >> t;  
    
    while(t--){
        solve();
    }

    return 0;
}