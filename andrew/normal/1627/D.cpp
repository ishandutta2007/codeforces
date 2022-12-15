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

    const ll N = 1e6;
    vector <int> a(n), c(N + 1);
    for(auto &i : a) {
        cin >> i;
        c[i]++;
    }

    int ans = 0;

    for(int i = N; i > 0; i--) if(!c[i]){
        vector <int> t(N / i + 1, 0);
        int x = -1;
        for(int j = i; j <= N; j += i) if(c[j]){
            if(x == -1) x = j / i;
            else x = __gcd(x, j / i);
        }
        if(x == 1) c[i] = 1, ans++;
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
        cin >> t;
    #endif      

    //cin >> t;  
    
    while(t--){
        solve();
    }

    return 0;
}