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
        vector<int> as(n);
        vector<pi> is(n);
        for(int i = 0; i < n; i ++) {
            cin >> is[i].f;
            is[i].s = i;
        }
        sort(is.begin(),is.end());
        vector<int> cur_eq;
        vector<int> lst_eq;
        int cur_v = is[0].f;
        int len = 0;
        int mx = -1;
        int res = 0;
        is.push_back({1e9+1,0});
        for(int i = 0; i <= n; i ++) {
            pi cur = is[i];
            // cout << "~  ";
            for(int c : cur_eq) {
                // cout << c << " ";
            }
            // cout << "\n";
            // cout << cur.f << " " << "/ " << cur.s << "\n";
            if(cur.f != cur_v) {
                sort(cur_eq.begin(),cur_eq.end());
                // cout << len << " " << mx << endl;
                int cnt = 0;
                for(int c : cur_eq) { if(c > mx) { cnt ++; } }
                res = max(res,len + cnt);
                // cout << "  " << res << endl;
                if(cnt == cur_eq.size()) {
                    len += cnt;
                } else {
                    int cnt2 = 0;
                    for(int c : lst_eq) { if(c < cur_eq[0]) { cnt2 ++; } }
                    len = cur_eq.size() + cnt2;
                }
                mx = cur_eq[cur_eq.size()-1];
                // cout << mx << endl;
                res = max(res,(int)cur_eq.size());
                
                int j = lst_eq.size()-1;
                int i = cur_eq.size();
                while(j >= 0 && i > 0) {
                    i --;
                    while(lst_eq[j] > cur_eq[i]) {
                        j --;
                        if(j == -1) { break; }
                    }
                    res = max(res,-i+(int)cur_eq.size()+j+1);
                }
                // cout << res << "!" << endl;
                cur_v = cur.f;
                lst_eq = cur_eq;
                cur_eq.clear();
            }
            cur_eq.push_back(is[i].s);
            // cout << res << endl;
        }
        cout << (n-res) << "\n";
    }
    return 0;
}

/*
1
5
3 5 8 1 7
*/

/*
1
4
0 1 0 1
*/