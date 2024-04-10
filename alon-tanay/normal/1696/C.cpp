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
        int n, m;
        cin >> n >> m;
        vector<pi> xs(n);
        ll sum = 0;
        for(int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            sum += x;
            int c = 1;
            while(x%m == 0) {
                x /= m;
                c *= m;
            }
            xs[i] = {c,x};
        }
        int k;
        cin >> k;
        vector<int> bs(k);
        for(int &b : bs) {
            cin >> b;
            sum -= b;
        }
        if(sum != 0) {
            cout << "No\n";
            continue;
        }
        int j = 0;
        bool fail = false;
        for(int i = 0; i < k; i ++) {
            // cout << j << endl;
            int b = bs[i];
            int c = 1;
            while(b%m == 0) {
                b /= m;
                c *= m;
            }
            while(true) {
                if(xs[j].s != b && xs[j].f > 0) {
                    fail = true;
                    break;
                }
                if(xs[j].f >= c) {
                    xs[j].f -= c;
                    c = 0;
                    break;
                }
                c -= xs[j].f;
                j ++;
                if(j == n) {
                    fail = true;
                    break;
                }
            }
            if(fail) { break; }
            
        }
        if(fail) { 
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
    return 0;
}


/*
1
8 3
3 9 6 3 12 12 36 12
16
9 3 2 2 2 3 4 12 4 12 4 12 4 12 4 4
*/