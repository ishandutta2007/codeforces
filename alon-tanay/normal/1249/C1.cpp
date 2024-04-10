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
        ll n;
        cin >> n;
        ll nn = n;
        vector<int> b3;
        while(nn) {
            b3.push_back(nn%3);
            nn/=3;
        }
        b3.push_back(0);
        int sz = b3.size();
        int j = -1;
        for(int i = 0; i < sz; i ++) {
            if(b3[i] == 2) {j = i;}
        }
        if(j == -1) {
            cout << n << "\n";
            continue;
        }
        bool two = false;
        ll res = 0;
        for(int i = sz - 1; i >= 0; i --) {
            if(two) { res *= 3; continue; }
            if(b3[i] == 2) {
                ll p3 = 1;
                for(int j = i + 1; j < sz; j ++) {
                    if(b3[j] == 0) {
                        break;
                    }
                    res += p3;
                    p3 *= 3;
                }
                res ++;
                res *= 3;
                two = true;
                continue;
            }
            res *= 3;
            res += b3[i];
        }
        cout << res << "\n";
    }
    return 0;
}