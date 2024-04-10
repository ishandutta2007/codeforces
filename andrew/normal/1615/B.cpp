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
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for(int i = 0; i < 60; i++){
        ans = max(ans, f[r][i] - f[l - 1][i]);
    }
    cout << (r - l + 1) - ans << "\n";
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