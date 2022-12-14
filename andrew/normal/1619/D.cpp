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
const int N = 70;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve(){
    int n, m;
    cin >> m >> n;
    vector <vector <int>> a(m, vector <int> (n, 0));

    vector <int> _max(n, 0);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            _max[j] = max(_max[j], a[i][j]);
        }
    }

    int l, r;
    l = 0, r = *min_element(all(_max));
    while(l < r){
        int mid = (l + r + 1) >> 1;
        bool good = 0;
        for(int i = 0; i < m; i++){
            int c = 0;
            for(int j = 0; j < n; j++) if(a[i][j] >= mid) c++;
            if(c > 1) {
                good = 1;
                break;
            }
        }
        if(good) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
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