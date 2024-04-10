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
    string s;
    cin >> s;

    int as = 0;
    for (int i = 0; i < n; i++) {
        as += s[i] - '0';
    }

    if (as == 0) {
        cout << "YES\n";
        return 0;
    }

    for (int sum = 1; sum < as; sum++) {
        bool ok = true;
        int cs = 0;
        int i = 0;
        while (i < n) {
            int x = s[i] - '0';
            if (x + cs > sum) {
                ok = false;
                break;
            }
            cs = (cs + x) % sum;
            i++;
        }

        ok &= cs == 0;
        if (ok) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}//ducvzg