#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        string x = "";
        x += s[i];
        x += s[n - 1 - i];
        string y = "";
        y += t[i];
        y += t[n - 1 - i];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        if (x == y || x[0] == x[1] && y[0] == y[1]) {
            ans += 0;
        } else if (x[0] == y[0] || x[0] == y[1] || x[1] == y[0] || x[1] == y[1] || y[0] == y[1]) {
            ans++;
        } else {
            ans += 2;
        }
    }

    if (n % 2) {
        if (s[n / 2] != t[n / 2]) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}