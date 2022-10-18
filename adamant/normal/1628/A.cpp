#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

#define int int64_t

void solve() {
    int n;
    cin >> n;
    int a[n];
    set<int> al;
    for(int i = 0; i <= n + 2; i++) {
        al.insert(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mxs[n];
    for(int i = n - 1; i >= 0; i--) {
        al.erase(a[i]);
        mxs[i] = *begin(al);
    }
    int j = 0;
    vector<int> b;
    order_set cur;
    for(int i = 0; i < n; i++) {
        cur.insert(a[i]);
        if(cur.order_of_key(mxs[j]) == mxs[j]) {
            //cout << "! " << i << ' ' << mxs[j] << endl;
            b.push_back(mxs[j]);
            cur.clear();
            j = i + 1;
        }
    }
    cout << b.size() << "\n";
    for(auto it: b) {
        cout << it << ' ';
    }
    cout << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}