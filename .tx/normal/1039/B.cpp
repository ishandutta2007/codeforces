#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

bool ask(llong l, llong r) {
    cout << l << " " << r << endl;
    string res;
    cin >> res;
    if (res == "Bad") {
        exit(0);
    }
    if (res == "No") {
        return false;
    }
    if (l == r) {
        exit(0);
    }
    return true;
}

int main() {
#ifdef VSE
//    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    srand(31);

    llong n, k;
    cin >> n >> k;

    llong l = 1, r = n;

    while (true) {
        if (r - l < 60) {
            llong x = l + rand() % (r - l + 1);
            ask(x, x);
            l = max(1LL, l - k);
            r = min(n, r + k);
            continue;
        }

        llong m = (l + r) >> 1;
        if (ask(l, m)) {
            l = max(1LL, l - k);
            r = min(n, m + k);
        } else {
            l = max(1LL, m - k);
            r = min(n, r + k);
        }
    }

    return 0;
}//winokz