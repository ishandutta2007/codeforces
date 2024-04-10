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

ll c[5010][5010];

void solve(){
    int n, k;
    cin >> n >> k;
    c[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            if(c[i][j] >= mod) c[i][j] -= mod;
        }
        c[i][0] = 1;
    }
    string s;
    cin >> s;
    ll ans = 1;
    ll f = 0;
    for(int i = 0; i < n; i++){
        vector <int> r(2, 0);
        r[s[i] - '0']++;
        if(r[1] > k) continue;
        int uk = n;
        for(int j = i + 1; j < n; j++){
            r[s[j] - '0']++;
            if(r[1] > k){
                r[s[j] - '0']--;
                uk = j;
                break;
            }            
        }          
        if(r[1] == k && r[(s[i] - '0') ^ 1] > 0){
            r[(s[i] - '0') ^ 1]--;            
            ans += c[r[0] + r[1]][r[1]];
            if(ans >= mod) ans -= mod;
            r[(s[i] - '0') ^ 1]++;
        }else if(r[1] + f >= k && r[(s[i] - '0') ^ 1] > 0){            
            r[(s[i] - '0') ^ 1]--;
            ans += c[r[0] + r[1]][r[1]];
            if(ans >= mod) ans -= mod;
            r[(s[i] - '0') ^ 1]++;
        }   
        if(s[i] == '1') f++;                     
    }
    cout << ans << "\n";
}

int main(){

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> t;
    #endif    
    
    while(t--){
        solve();
    }


    return 0;
}