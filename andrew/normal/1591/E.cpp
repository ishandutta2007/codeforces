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
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 1e6 + 200;
//const int N = 100;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <int> g[N];
vector <pair <pii, int> > qry[N];
int ans[N], cnt[N], a[N];

ordered_set <pii> r;


void calc(int x){
    int v = a[x];
    if(cnt[v]){
        r.erase(r.find(m_p(cnt[v], v)));        
    }
    cnt[v]++;
    r.insert(m_p(cnt[v], v));

    //
        for(auto pp : qry[x]){
            int l, k, step;
            l = pp.fi.fi, k = pp.fi.se, step = pp.se;
            int x = r.order_of_key(m_p(l, 0));
            if(sz(r) - x < k){
                ans[step] = -1;
            }else{                
                ans[step] = r.find_by_order(x + k - 1) -> se;
            }
        }
    //

    for(auto to : g[x]) calc(to);
    r.erase(r.find(m_p(cnt[v], v)));
    cnt[v]--;
    if(cnt[v]) r.insert(m_p(cnt[v], v));
}


void solve(){
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].p_b(i);
    }

    for(int i = 0; i < q; i++) {
        int v, l, k;
        cin >> v >> l >> k;
        qry[v].p_b({{l, k}, i});
        ans[i] = -1;
    }

    calc(1);

    for(int i = 0; i < q; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        qry[i].clear();
    }

}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    

    return 0;
}