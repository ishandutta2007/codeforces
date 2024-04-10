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
        int n, q;
        cin >> n >> q;
        vector<int> as(n);
        int idx = 0;
        for(int &a: as) {
            cin >> a;
        }
        if(q >= n) {
            for(int i = 0; i < n; i ++) {
                cout << "1";
            }
            cout << "\n";
            continue;
        }
        vector<bool> used(n);
        int cur = 0;
        for(int i = n - 1; i >= 0; i --) {
            if(as[i] <= cur) {
                used[i] = true;
                continue;
            }
            if(cur == q) { continue; }
            if(as[i] >= cur + 1) {
                cur ++;
                used[i] = true;
            } 
        }
        for(int i = 0; i < n; i ++ ){
            cout << used[i];
        }
        cout << "\n";
    }
    return 0;
}