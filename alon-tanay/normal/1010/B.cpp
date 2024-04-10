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

    int m,n;
    cin >> m >> n;
    vector<int> p(n);
    for(int &pi : p) {
        cout << 1 << endl;
        int r;
        cin >> r;
        if(r == 0) { return 0; }
        if(r == -1) {
            pi = true;
        }
    }
    int l = 1, r = m;
    int idx = 0;
    while(l < r) {
        int mid = (l+r)/2;
        cout << mid << endl;
        int res;
        cin >> res;
        if(res == 0) { return 0; }
        if((res == 1)^p[idx]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        idx ++;
        idx %= n;
    }
    cout << l << endl;
    int res;
    cin >> r;

    return 0;
}