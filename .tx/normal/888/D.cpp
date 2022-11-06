#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int get(int n) {
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    int ans = 0;
    do {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (p[i] == i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    } while (next_permutation(begin(p), end(p)));

    return ans;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    llong n, k;
    cin >> n >> k;

    llong ans = 1;
    if (k >= 2) {
        llong x = n * (n - 1) / 2;
        ans += x * get(2);
    }
    if (k >= 3) {
        llong x = n * (n - 1) * (n - 2) / 6;
        ans += x * get(3);
    }
    if (k >= 4) {
        llong x = n * (n - 1) * (n - 2) * (n - 3) / 24;
        ans += x * get(4);
    }

    cout << ans;//

    return 0;
}//yzbayp