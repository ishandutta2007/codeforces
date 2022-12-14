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

void solve(){
    int n;
    cin >> n;
    vector <int> p(n + 1), q(n + 1), wh(n + 1);
    string s;
    int a, b;
    a = b = 0;
    for(int i = 1; i <= n; i++) cin >> p[i];

    cin >> s;
    set <int> sa, sb;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            sa.insert(p[i + 1]);
        }else{
            sb.insert(p[i + 1]);
        }
        wh[p[i + 1]] = i + 1;
    }

    a = sa.size();
    b = n;
    while(!sa.empty()){
        int x = *--sa.end();
        q[wh[x]] = a--;
        sa.erase(x);
    }
    while(!sb.empty()){
        int x = *--sb.end();
        q[wh[x]] = b--;
        sb.erase(x);
    }
    for(int i = 1; i <= n; i++) cout << q[i] << " ";
    cout << "\n";
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