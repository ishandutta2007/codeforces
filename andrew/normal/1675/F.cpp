#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
// const int MAXN = 1e3;;
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <ll> v[MAXN];
ll deep[MAXN];
ll p[MAXN];
ll f[MAXN];
ll gg[MAXN];
ll in_way[MAXN];
ll ans;

bool calc(int x) {
    if (f[x])return 0;
    ll fl = 0;
    f[x] = 1;
    for (auto to : v[x]){
        if (!in_way[to]){
            fl |= calc(to);
        }
    }
    if (gg[x]) fl |= 1;
    if (fl && !in_way[x]) ans += 2;
    return fl;
}

void dfs(ll x, ll pr = 0) {
    p[x] = pr;
    deep[x] = deep[pr] + 1;
    for (auto to : v[x]) if (to != pr) {
        dfs(to, x);
    }
}

void solve(){
   ll n, k;
   cin >> n >> k;
   for (int i = 1; i <= n; i++) {
       f[i] = 0;
       v[i].clear();
       in_way[i] = 0;
       gg[i] = 0;
   }
   ll x, y;
   cin >> x >> y;
   for (int i = 1; i <= k; i++) {
       ll ve;
       cin >> ve;
       gg[ve] = 1;
   }
   for (int i = 1; i < n; i++) {
       ll a, b; 
       cin >> a >> b; 
       v[a].p_b(b);
       v[b].p_b(a);
   }   
   dfs(1);   
   while (deep[x] < deep[y]) {
        in_way[y] = 1;
        y = p[y];
   }
   while (deep[x] > deep[y]) {
        in_way[x] = 1;
        x = p[x];
   }
   while(x != y){
       in_way[x] = in_way[y] = 1;
       x = p[x];
       y = p[y];
   }
   in_way[x] = in_way[y] = 1;
   ans = -1;   
   for (int i = 1; i <= n; i++) if(in_way[i]){
       calc(i);       
       ans++;
   }
   cout << ans << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif    
    cin >> t;
    
    while(t--){
        solve();
    }


    return 0;
}