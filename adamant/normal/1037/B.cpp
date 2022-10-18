#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    int a[n];
    for(int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i == n / 2) {
            ans += abs(a[i] - s);
        } else if(i < n / 2) {
            ans += max<int>(0, a[i] - s);
        } else {
            ans += max<int>(0, s - a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}