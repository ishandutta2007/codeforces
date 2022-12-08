#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vvi vs(n,vi(m));
        for(vi &a : vs) {
            for(int &ai : a) {
                cin >> ai;
            }
        }
        ll mx = -1;
        ll res = 0;
        for(int i = 0; i < n; i ++) {
            ll sum = 0;
            ll ts = 0;
            for(int j = 0; j < m; j ++) {
                sum += vs[i][j];
                ts += sum;
            }
            if(mx == -1) {
                mx = ts;
                continue;
            }
            if(mx > ts) {
                cout << i+1 << " ";
                res = mx-ts;
                break;
            } else if(mx < ts) {
                cout << 1 << " ";
                res = ts-mx;
                break;
            }
            mx = ts;
        }
        cout << res << "\n";
        
    }
    return 0;
}