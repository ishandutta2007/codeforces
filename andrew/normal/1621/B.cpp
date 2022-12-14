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
    int n;
    cin >> n;

    vector <pair <pll, ll> > a(n);

    for(auto &i : a){
        cin >> i.fi.fi >> i.fi.se >> i.se;
    }

    map <pll, ll> mp;
    map <ll, ll> ml;
    map <ll, ll> mr;
    ll l, r;
    l = a[0].fi.fi, r = a[0].fi.se;    
    //cout << a[0].se << "\n";
    for(int i = 0; i < n; i++){
        l = min(l, a[i].fi.fi);
        r = max(r, a[i].fi.se);
        ll c = a[i].se;
        ll le, ri;
        le = a[i].fi.fi, ri = a[i].fi.se;
        ll ans = 1e18;
        if(ml.find(le) == ml.end() || ml[le] > c)ml[le] = c;
        if(mr.find(ri) == mr.end() || mr[ri] > c)mr[ri] = c;
        if(mp.find(m_p(le, ri)) == mp.end() || mp[m_p(le, ri)] > c)mp[m_p(le, ri)] = c;
        ans = ml[l] + mr[r];
        if(mp.find({l, r}) != mp.end()) ans = min(ans, mp[{l, r}]);
        cout << ans << "\n";
    }

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