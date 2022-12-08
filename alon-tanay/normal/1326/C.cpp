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

const int MOD = 998244353;
const ll MODL = 998244353;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vi locs;
    ll res = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(x > n-k) {
            res += x;
            locs.push_back(i);
        }
    }
    ll cnt = 1;
    for(int i = 1; i < k; i ++) {
        cnt *= (locs[i]-locs[i-1]);
        cnt %= MOD;
    }
    cout << res << " " << cnt << endl;
    return 0;
}