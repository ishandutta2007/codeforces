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

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> s(n);
    for (int i= 0 ; i < n; i++) {
        cin >> s[i];
        s[i] = (s[i] + 1) % 3;
    }

    vector<int> t = s;

    for (int i = 0; 2 * i < n; i++) {
        int r = n - i - 1;
        if (s[i] != 0) {
            if (s[r] != 0 && s[i] != s[r]) {
                cout << -1;
                return 0;
            }
            s[r] = s[i];
        } else if (s[r] != 0) {
            if (s[i] != 0 && s[i] != s[r]) {
                cout << -1;
                return 0;
            }
            s[i] = s[r];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            ans += min(a, b);
        } else if (s[i] != t[i]) {
            if (s[i] == 1) {
                ans += a;
            } else {
                ans += b;
            }
        }
    }

    cout << ans;

    return 0;
}//dhpbjh