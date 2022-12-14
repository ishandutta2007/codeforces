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
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5;
vector <pll> v[N];

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].p_b({b, c});
        v[b].p_b({a, c});
    }

    vector <ll> p(n + 1, -1), p1(n + 1, -1);

    queue <ll> q;
    p[a] = 0;
    q.push(a);

    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        if (x == b) continue;
        for (auto to : v[x]) if (p[to.fi] == -1) {
            p[to.fi] = p[x] ^ to.se;
            q.push(to.fi);
        }
    }   

    map <ll, ll> mp;

    for (int i = 1; i <= n; i++) if (i != b){
        mp[p[i]] = 1;
    }

    p1[b] = 0;
    q.push(b);

    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        for (auto to : v[x]) if (p1[to.fi] == -1) {
            p1[to.fi] = p1[x] ^ to.se;
            q.push(to.fi);
        }
    }  
    for (int i = 1; i <= n; i++) if (i != b) {
        if (mp.find(p1[i]) != mp.end()) {
            cout << "YES\n";
            goto l1;            
        }
    }
    if (p[b] == 0) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

    l1:
    for (int i = 1; i <= n; i++) v[i].clear();
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