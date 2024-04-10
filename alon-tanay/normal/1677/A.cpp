#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>
#define ld long double

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> xs(n);
        vector<vector<int>> ord(n,vector<int>(n+1));
        for(int &x : xs) {
            cin >> x;
        }
        for(int i = 0; i < n; i ++) {
            int sum = 0;
            for(int j = 1; j <= n; j ++) {
                sum += (xs[j-1]<xs[i]);
                ord[i][j] = sum;
            }
        }
        // pbds L;
        // pbds R;
        ll res = 0;
        // cout << "~~~~\n";
        for(int a = 0; a < n - 3; a ++) {
            // cout << a << ": \n";
            // L.clear();
            // R.clear();
            // for(int i = a + 1; i < n-2; i ++) {
            //     L.insert(xs[i]);
            // }
            // R.insert(xs[n-1]);
            // ll cur = L.size() - L.order_of_key(xs[n-1]);
            ll cur = n - 3 - (a+1) + 1 - (ord[n-1][n-2]-ord[n-1][a+1]);
            for(int c = n - 2; c > a + 1; c --) {
                if(xs[a] < xs[c]) { res += cur; }
                // cout << "  " << cur << "\n";
                // cur -= R.order_of_key(xs[c-1]);
                cur -= ord[c-1][n]-ord[c-1][c+1];
                // L.erase(xs[c-1]);
                // R.insert(xs[c]);
                // cur += L.size() - L.order_of_key(xs[c]);
                cur += c-a-2 - (ord[c][c-1]-ord[c][a+1]);
            }
        }
        cout << res << "\n";

    }
    return 0;
}