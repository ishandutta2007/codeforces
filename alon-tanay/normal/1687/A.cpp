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
        vector<ll> xs(n);
        vector<ll> pre(n+1);
        int idx = 0;
        ll sum = 0;
        for(ll &x : xs) {
            cin >> x;
            sum += x;
            pre[++idx] = sum;
        }
        if(k >= n) {
            ll res = sum;
            res += k * n - ((n)*(n+1))/2;
            cout << res << "\n";
            continue;
        }
        ll res = (k*(k-1)) / 2;
        ll mx = 0;
        for(int i = k; i <= n; i ++) {
            mx = max(mx,pre[i]-pre[i-k]);
        }
        res += mx;
        cout << res << "\n";
    }
    return 0;
}