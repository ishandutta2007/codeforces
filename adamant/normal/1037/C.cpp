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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] != b[i] && a[i - 1] != b[i - 1] && a[i] == b[i - 1] && a[i - 1] == b[i]) {
            swap(a[i], a[i - 1]);
            ans++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}