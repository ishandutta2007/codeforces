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
        string a;
        cin >> a;
        string b;
        cin >> b;
        int idx = 0;
        bool fail = false;
        for(int i = 1; i < m; i ++) {
            if(a[n-i] != b[m-i]) {
                fail = true;
                break;
            }
        }
        bool f2 = false;
        for(int i = n-m; i >= 0; i --) {
            if(a[i] == b[0]) {
                f2 = true;
            }
        }
        if(!f2) {
            fail = true;
        }
        cout << (fail ? "NO\n":"YES\n");    
    }
    return 0;
}