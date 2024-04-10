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

    int n, x;
    cin >> n >> x;

    if (n == 2 && x == 0) {
        cout << "NO";
        return 0;
    }

    vector<int> ans;

    if (n % 4 == 2 && x == 0) {
        ans.push_back((1 << 19) - 1);
        ans.push_back((1 << 18) - 1);
        ans.push_back(1 << 18);
        n -= 3;
    }

    while (n > 4) {
        for (int i = 0; i < 4; i++) {
            if (ans.empty()) {
                ans.push_back(int(1e6) - 1);
            } else {
                ans.push_back(ans.back() - 1);
            }
        }
        n -= 4;
    }

    if (n == 4) {
        ans.push_back(x);
        ans.push_back(x | (1 << 17));
        ans.push_back(x | (2 << 17));
        ans.push_back(3 << 17);
    } else if (n == 3) {
        ans.push_back(x ^ 1);
        ans.push_back(x ^ 2);
        ans.push_back(x ^ 3);
    } else if (n == 2) {
        ans.push_back(1 << 17);
        ans.push_back(x | (1 << 17));
    } else {
        ans.push_back(x);
    }

    cout << "YES\n";
    int t = 0;
    for (int i : ans) {
        cout << i << " ";
        t ^= i;
    }

    cerr << endl << t << endl;

    return 0;
}//ezgoxr