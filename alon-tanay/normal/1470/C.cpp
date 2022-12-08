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

    int n, k;
    cin >> n >> k;
    int sq = sqrt(n);
    int idx = 0;
    int res;
    while(true) {
        idx += sq+1;
        idx %= n;
        cout << "? " << idx+1 << endl;
        cin >> res;
        if(res != k) {
            break;
        }
    }
    if(res < k) {
        while(res < k) {
            idx ++;
            idx %= n;
            cout << "? " << idx+1 << endl;
            cin >> res;
        }
        cout << "! " << idx+1 << endl;
    } else {
        while(res >= k) {
            idx --;
            if(idx == -1) { idx = n - 1; }
            cout << "? " << idx+1 << endl;
            cin >> res;
        }
        idx ++;
        idx %= n;
        cout << "! " << idx+1 << endl;
    }
    return 0;
}