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
        vector<int> xs(n);
        vector<int> cnt(n);
        for(int &x : xs) {
            cin >> x;
            x--;
            cnt[x] ++;
        }
        vector<vector<int>> suf(n,vi(n+1));
        vector<vector<int>> nxt(n,vi(n+1));
        for(int i = 0; i < n; i ++) {
            int lst = n;
            for(int j = n - 1; j >= 0; j --) {
                if(xs[j] == i) {
                    lst = j;
                }
                nxt[i][j] = lst;
                suf[i][j] = suf[i][j+1] + (xs[j] == i);
            }
        }
        ll res = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = i + 1; j < n; j ++) {
                if(xs[i] == xs[j]) { continue; }
                ll cur = (cnt[xs[j]]-suf[xs[j]][i]);
                cur *= suf[xs[i]][j];
                res += cur;
            }
        }
        for(int i = 0; i < n; i ++) {
            if(cnt[i] >= 4) {
                ll c = cnt[i];
                ll cur = c * (c-1) * (c-2) * (c-3);
                cur /= 24;
                res += cur;
            }
        }
        cout << res << "\n";
    }
    return 0;
}