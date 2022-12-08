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
        int n, k;
        cin >> n >> k;
        vvi ss(k);
        for(int ki = 0; ki < k; ki ++) {
            int c;
            cin >> c;
            ss[ki].resize(c);
            for(int ci = 0; ci < c; ci ++) {
                cin >> ss[ki][ci];
            }
        }
        if(k == 1) {
            vi v;
            vector<bool> in(n+1,true);
            for(int j : ss[0]) {
                in[j] = false;
            }
            for(int i = 1; i <= n; i ++) {
                if(in[i]) { v.push_back(i); }
            }
            
            cout << "? " << v.size();
            for(int j : v) {
                cout << " " << j;
            }
            cout << endl;
            int res;
            cin >> res;
            cout << "! " << res << endl;
            string cor;
            cin >> cor;
            continue;
        }
        cout << "? " << n;
        for(int i = 1; i<= n; i ++) {
            cout << " " << i;
        }
        cout << endl;
        int mx;
        cin >> mx;
        int l = 0, r = k - 1;
        while(l < r) {
            int mid = (l+r)/2;
            vi v;
            vector<bool> in(n+1,true);
            for(int i = 0; i <= mid; i ++) {
                for(int j : ss[i]) {
                    in[j] = false;
                }
            }
            for(int i = 1; i <= n; i ++) {
                if(in[i]) { v.push_back(i); }
            }
            cout << "? " << v.size();
            for(int vi : v) {
                cout << " " << vi;
            }
            cout << endl;
            int ans;
            cin >> ans;
            if(ans == mx) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        vector<int> pass(k,mx);
        vi v;
        vector<bool> in(n+1,true);
        for(int j : ss[l]) {
            in[j] = false;
        }
        for(int i = 1; i <= n; i ++) {
            if(in[i]) { v.push_back(i); }
        }
        cout << "? " << v.size();
        for(int j : v) {
            cout << " " << j;
        }
        cout << endl;
        cin >> pass[l];
        cout << "! ";
        for(int p : pass) {
            cout << p << " ";
        }
        cout << endl;
        string feed;
        cin >> feed;
    }
    return 0;
}

/*
1
4 4
1 2
1 1
1 4
1 3
*/

/*
3 4 1 2
*/

/*
10
2 2
1 1
1 2
*/

/*
10
2 1

1 2

1 1

2 2

2 1

1 1

1 2

2 1

1 2

1 2

2 1

2 1

1 2

2 1

1 2

1 2

2 1

2 1

1 2

2 1

2 1

1 1

2 1

1 2

1 1

2 1

2 1

1 2

*/