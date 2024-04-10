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
        ll n, k;
        cin >> n >> k;
        vector<ll> as(n);
        vector<vector<ll>> lw(n,vector<ll>(30));
        for(ll &a :as) {
            cin >> a;
        }
        for(int i = 0; i < n; i ++) {
            int a = as[i];
            for(int j = 0; j < 30; j ++) {
                a /= 2;
                lw[i][j] = a;
            }
        }
        ll res = 0;
        ll cur = 0;
        for(int i = 0; i <= n; i ++) {
            ll dif = 0;
            for(int j = 0; j < 30; j ++) {
                if(i + j >= n) { break; }
                dif += lw[i+j][j];
            }
            // cout << cur << " " << i << "\n";
            res = max(res,cur+dif);
            if(i == n) { break; }
            cur += as[i] - k;
        }
        cout << res << "\n";
    }
    return 0;
}