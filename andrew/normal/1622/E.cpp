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
    ll ans = -1;
    int n, m;
    cin >> n >> m;
    vector <ll> x(n);
    vector <vector <int>> s(n);
    vector <pll> p(m);

    for(int i = 0; i < n; i++){
        cin >> x[i];        
    }
    char fl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> fl;
            if(fl == '1'){
                s[i].p_b(j);
            }
        }
    }

    vector <ll> res;

    for(int musk = 0; musk < pw(n); musk++){
        for(int i = 0; i < m; i++){
            p[i].fi = 0;
            p[i].se = i + 1;
        }
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            if((musk & pw(i)))sum += x[i];
            else sum -= x[i];
        }        
        for(int i = 0; i < n; i++){
            for(auto j : s[i]){
                if((musk & pw(i)))p[j].fi--;
                else p[j].fi++;
            }
        }
        sort(all(p));
        for(int i = 0; i < m; i++){
            sum += p[i].fi * (i + 1);
        }
        if(ans < sum){
            ans = sum;
            res.resize(m);
            for(int i = 0; i < m; i++)res[p[i].se - 1] = i + 1;            
        }        
    }
    //cout << ans << "\n";
    for(auto i : res)cout << i << " ";
    cout << "\n";
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