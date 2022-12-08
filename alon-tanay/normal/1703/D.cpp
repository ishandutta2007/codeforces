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
        set<string> ss;
        vector<string> vs(n);
        for(int i = 0; i < n; i ++) {
            string str;
            cin >> str;
            vs[i] = str;
            ss.insert(str);
        }
        for(int i = 0; i < n; i ++) {
            bool found = false;
            string str = vs[i];
            int sz = str.length();
            string L;
            string R = str;
            for(int j = 1; j < sz; j ++) {
                L += str[j-1];
                for(int i = 0; i < R.size()-1; i ++) {
                    R[i] = R[i+1];
                }
                R.pop_back();
                // cout << L << " " << R << endl;
                if((ss.find(L) != ss.end()) && ss.find(R) != ss.end()) {
                    found = true;
                }
            }
            cout << found;
        }
        cout << "\n";
    }
    return 0;
}