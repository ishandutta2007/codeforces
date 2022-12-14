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
const ll inf = 1e15;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string f(string x){
    string r = x;
    reverse(all(x));
    r += x;
    return r;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 1) fout(f(s));
    if(s[0] == s[1]) fout(f(s.substr(0, 1)));
    string c;
    c += s[0];
    //int t = 0;
    //char rofl = *min_element(all(s));
    for(int i = 1; i < n; i++){
        if(s[i] > c[i - 1]){            
            break;
        }else{
            //if(s[i] == rofl) break;            
            c += s[i];
        }
    }
    string ans = f(c);
    // for(int i = 1; i <= c.size(); i++){
    //     ans = min(ans, f(c.substr(0, i)));
    // }
    cout << ans << "\n";
}

int main(){

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