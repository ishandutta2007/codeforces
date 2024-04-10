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
        int n, m, k;
        cin >> n >> m >> k;
        vector<ll> as(k);
        ll hor = 0;
        ll ver = 0;
        int mxh = 0;
        int mxv = 0;
        for(ll &a : as) {
            cin >> a;
            int h = a/m;
            int v = a/n;
            mxh = max(mxh,h);
            mxv = max(mxv,v);
            hor += (h == 1 ? 0 : h);
            ver += (v == 1 ? 0 : v);
        }
        if(hor >= n) {
            if((mxh == 2) && (n&1)) {
            } else {
                cout << "Yes\n";
                continue;
            }
        }
        if(ver >= m) {
            if((mxv == 2) && (m&1)) {
            } else {
                cout << "Yes\n";
                continue;
            }
        }
        cout << "No\n";
        // cout << ((hor >= n || ver >= m) ? "Yes\n":"No\n");
        
    }
    return 0;
}