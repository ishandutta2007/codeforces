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
        int n;
        cin >> n;
        vector<ll> as(n);
        for(ll &a : as) {
            cin >> a;
        }
        ll mnv = as[0];
        ll mnh = as[1];
        ll sum = as[0];
        ll res = 1e18;
        bool h = true;
        for(int i = 1; i < n; i ++) {
            if(h) {
                mnh = min(mnh,as[i]);
                sum += as[i];
            } else {
                mnv = min(mnv,as[i]);
                sum += as[i];
            }
            ll cur = sum + (n-((i/2)+1))*mnv + (n-(((i-1)/2)+1))*mnh;
            res = min(res,cur);
            h = !h;
        }
        cout << res << "\n";
    }
    return 0;
}