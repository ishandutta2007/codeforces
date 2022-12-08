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

struct Seg {
    vector<int> seg;
    int n;
    Seg(vector<int> &xs) {
        n = xs.size();
        seg.resize(2*n);
        for(int i = 0; i < n; i ++) {
            seg[i+n] = xs[i];
        }
        for(int i = n - 1; i; i --) {
            seg[i] = seg[i<<1]+seg[(i<<1)|1];
        }
    }
    void update(int i, int v) {
        i += n;
        seg[i] = v;
        for(i >>= 1; i; i >>= 1) {
            seg[i] = seg[i<<1]+seg[(i<<1)|1];
        }
    }
    int query(int a, int b) {
        int res = 0;
        for(a += n, b += n; a < b; a >>= 1, b >>= 1) {
            if(a&1) {
                res += seg[a++];
            }
            if(b&1) {
                res += seg[--b];
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> xs(n);
        for(int &x : xs) {
            cin >> x;
        }
        sort(xs.begin(),xs.end());
        vector<int> dp(2e5+1);
        for(int i = 0; i < n; i ++) {
            int x = xs[i];
            int sx = sqrt(x);
            int mx = 0;
            for(int j = 1; j <= sx; j ++) {
                if(x%j == 0) {
                    mx = max(mx,dp[j]);
                    mx = max(mx,dp[x/j]);
                }
            }
            dp[x] = mx + 1;
        }
        int mx = 0;
        for(int i = 0; i <= 2e5; i ++) {
            mx = max(mx,dp[i]);
        }
        cout << (n-mx) << "\n";
    }
    return 0;
}