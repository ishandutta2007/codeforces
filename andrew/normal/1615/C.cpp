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

int f[N][60];

void solve(){
    int n;
    cin >> n;
    string a, b;
    vector <int> c;
    bool fl = 0;
    cin >> a >> b;
    if(a == b){
        cout << "0\n";
        return;
    }
    for(auto i : a) if(i == '1') fl = 1;
    if(!fl){
        cout << "-1\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(a[i] != b[i])c.p_b(1);
        else c.p_b(0);
    }
    int inf = 1e9;
    int ans = 1e9;
    for(int s = 0; s < 2; s++){        
        vector <int> d;        
        int id = 0;
        int ca, cb;
        ca = cb = 0;
        for(auto i : c){
            d.p_b(s ^ i);  
            if((s ^ i)){
                if(a[id] == '1')ca++;
                else cb++;                
            }
            id++;
        }        
        int p = 0, c = 0;                
        for(auto i : d){
            c += i;
            p ^= i;
        }        
        if(p == s && (ca == cb || ca == cb + 1)) ans = min(ans, c);
    }
    if(ans == inf) cout << "-1\n";
    else cout << ans << "\n";
}

int main(){

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    for(int i = 0; i < 60; i++){
        for(int j = 1; j < N; j++){
            f[j][i] = f[j - 1][i];
            if((j & pw(i))) f[j][i]++;
        }
    }

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}