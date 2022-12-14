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
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <int> v[N];
vector <pii> g[N];
int cl[N];
bool good = 1;

int f(int x){
    return (__builtin_popcount(x)) % 2;
}

void eq(int a, int b){
    g[a].p_b({b, 1});
    g[b].p_b({a, 1});
}

void neq(int a, int b){
    g[a].p_b({b, 0});
    g[b].p_b({a, 0});
}

void dfs(int x, int p){
    if(cl[x] != -1) return;
    cl[x] = p;
    for(auto to : g[x]){
        int f = p ^ 1;
        f ^= to.se;
        if(cl[to.fi] == -1){
            dfs(to.fi, f);
        }else{
            if(f != cl[to.fi]){
                good = 0;
                return;
            }
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    good = 1;
    for(int i = 1; i <= n; i++) cl[i] = -1;
    map <pii, int> mp;
    for(int i = 1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b)swap(a, b);
        if(c != -1){
            mp[{a, b}] = c;
            if(f(c) == 1){
                neq(a, b);            
            }else{
                eq(a, b);
            }
        }        
        v[a].p_b(b);
        v[b].p_b(a);        
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 1){
            neq(a, b);            
        }else{
            eq(a, b);
        }
    }

    for(int i = 1; i <= n; i++){
        dfs(i, 0);
    }
    if(!good){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        for(int i = 1; i <= n; i++){
            for(auto j : v[i]) if(i < j){
                if(mp.find({i, j}) != mp.end()){
                    cout << i << " " << j << " " << mp[{i, j}] << "\n";
                }else{
                    cout << i << " " << j << " " << (cl[i] ^ cl[j]) << "\n";
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        v[i].clear();
        g[i].clear();
    }
}

int main(){

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}