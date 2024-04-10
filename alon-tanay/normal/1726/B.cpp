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
        if(m<n) { cout << "No\n"; continue; }
        if((n == m) || (n&1)) {
            cout << "Yes\n";
            cout << m-n+1 << " ";
            for(int i = 1; i < n; i ++) {
                cout << "1 ";
            }
            cout << "\n";
            continue;
        }
        if(m%n==0) {
            cout << "Yes\n";
            for(int i = 0; i < n; i ++) {
                cout << m/n << " ";
            }
            cout << "\n";
            continue;
        }
        if((m&1)||(n&1)||(m<n)) { cout << "No\n"; continue; }
        cout << "Yes\n";
        cout << (m-n+2)/2 << " " << (m-n+2)/2 << " ";
        for(int i = 2; i < n; i ++) {
            cout << "1 ";
        }
        cout << "\n";
    }
    return 0;
}