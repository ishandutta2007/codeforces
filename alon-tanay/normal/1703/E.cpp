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
        int n;
        cin >> n;
        vector<string> mp(n);
        for(int ri = 0; ri < n; ri ++) {
            cin >> mp[ri];
        }
        int cnt = 0;
        if(n&1) {
            for(int ri = 0; ri < n/2; ri ++) {
                for(int ci = 0; ci <= n/2; ci ++) {
                    int cnt0 = 0;
                    int cnt1 = 0;
                    for(int i = 0; i < 4; i ++) {
                        if(mp[ri][ci] == '0') { cnt0 ++;} else {cnt1 ++;}
                        int y = n - 1 - ci;
                        int x = ri;
                        // cout << ri << " " << ci << " -> ";
                        ri = y;
                        ci = x;
                        // cout << ri << " " << ci << endl;
                    }
                    cnt += min(cnt0,cnt1);
                }
            }
        } else {
            for(int ri = 0; ri < n/2; ri ++) {
                for(int ci = 0; ci < n/2; ci ++) {
                    int cnt0 = 0;
                    int cnt1 = 0;
                    for(int i = 0; i < 4; i ++) {
                        if(mp[ri][ci] == '0') { cnt0 ++;} else {cnt1 ++;}
                        int y = n - 1 - ci;
                        int x = ri;
                        ri = y;
                        ci = x;
                    }
                    cnt += min(cnt0,cnt1);
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}