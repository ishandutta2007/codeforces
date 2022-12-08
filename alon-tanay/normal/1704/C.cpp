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
        vector<int> as(m);
        for(int &a : as) {
            cin >> a;
        }
        sort(as.begin(),as.end());
        vector<int> ds(m);
        for(int i = 0; i < m; i ++) {
            ds[i] = ((as[(i+1)%m]-as[i]-1)+n)%n;
        }
        sort(ds.begin(),ds.end());
        int res = 0;
        int c = 0;
        for(int i = m - 1; i >= 0; i --) {
            if((ds[i]-2*c <= 2) && (ds[i]-2*c >= 1)) {
                res ++;
            } else {
                res += max(0,ds[i]-2*c-1);
            }
            c += 2;
        }
        cout << (n-res) << "\n";
    }
    return 0;
}