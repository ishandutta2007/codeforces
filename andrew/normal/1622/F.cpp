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

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n;
    cin >> n;
    if(n == 1) fout("1\n1");
    vector <ll> h(n + 1), hash(n + 1), last(n + 1);
    for(int i = 2; i <= n; i++) if(!last[i]){
        for(int j = i; j <= n; j += i) last[j] = i;
    }
    set <int> s;

    set <pll> st;

    for(int i = 1; i <= n; i++){
        h[i] = rnd();
        s.insert(i);        
    }

    ll all_hash = 0;

    for(int i = 2; i <= n; i++){
        hash[i] = hash[i - 1];
        ll x = i;
        while(x > 1){
            hash[i] ^= h[last[x]];
            x /= last[x];
        }
        all_hash ^= hash[i];
        st.insert({hash[i], i});
    }    
    for(int i = 2; i <= n; i++){
        if(hash[i] == all_hash){
            cout << n - 1 << "\n";
            s.erase(i);
            for(auto i : s)cout << i << " ";
            cout << "\n";
            return;
        }
    }

    for(int i = 2; i <= n; i++){
        st.erase({hash[i], i});
        ll x = all_hash ^ hash[i];
        set <pll> :: iterator it = st.lower_bound(make_pair(x, -1));
        if(it != st.end() && it -> fi == x){
            cout << n - 2 << "\n";
            s.erase(i);
            s.erase(it -> se);
            for(auto i : s)cout << i << " ";
            cout << "\n";
            return;
        }
    }
    cout << n - 3 << "\n";
    s.erase(2);
    s.erase((n - 1) / 2);
    s.erase(n);
    for(auto i : s) cout << i << " ";
    cout << "\n";
}

int main(){

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> t;
    #endif    
    //cin >> t;
    
    while(t--){
        solve();
    }


    return 0;
}