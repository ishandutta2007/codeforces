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

    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int b = 0;
        int q = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '(') {
                b++;
            } else if (s[j] == ')') {
                b--;
            } else {
                if (b > 0) {
                    b--;
                    q++;
                } else {
                    b++;
                }
            }
            if (b < 0) {
                if (q == 0) {
                    break;
                }
                b += 2;
                q--;
            }
            if (b == 0) {
//                cout << i + 1 << " " << j + 1 << endl;
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}//rbpoyk