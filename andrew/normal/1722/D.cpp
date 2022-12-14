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
const int MAXN = 1e6 + 1e5;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {    
    ll n;
    cin >> n;
    string s;
    cin >> s;
    set <int> l, r;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            l.insert(i);
            ans += i;
        }else {
            r.insert(i);
            ans += n - i - 1;
        }
    }    
    for (int i = 1; i <= n; i++) {        
        if (sz(l) && sz(r)) {
            int le = *l.begin();
            int ri = *--r.end();                            
            ll lv = (n - le - 1) - le;
            ll rv = ri - (n - ri - 1);            
            if (max(lv, rv) > 0) {
                if (lv > rv) {
                    ans += lv;
                    l.erase(le);
                    r.insert(le);
                }else {
                    ans += rv;
                    r.erase(ri);
                    l.insert(ri);
                }
            }            
        }else if(sz(l)) {
            int le = *l.begin();                                    
            ll lv = (n - le - 1) - le;            
            if (lv > 0) {                
                ans += lv;
                l.erase(le);
                r.insert(le);                
            }            
        }else if(sz(r)) {            
            int ri = *--r.end();                                        
            ll rv = ri - (n - ri - 1);            
            if (rv > 0) {                
                ans += rv;
                r.erase(ri);
                l.insert(ri);
            }            
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif         

    cin >> t;   

    while (t--) {
        solve();
    }


    return 0;
}