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
        vector<bool> col(m);
        vector<bool> row(n);
        for(int ri = 0; ri < n; ri ++) {
            for(int ci = 0; ci < m; ci ++) {
                int x;
                cin >> x;
                if(x) {
                    row[ri] = col[ci] = true;
                }
            }
        }
        int fR = n;
        int fC = m;
        for(bool b : row) { fR -= b; }
        for(bool b : col) { fC -= b; }
        int mn = min(fR,fC);
        cout << (mn&1 ? "Ashish\n":"Vivek\n");
    }
    return 0;
}