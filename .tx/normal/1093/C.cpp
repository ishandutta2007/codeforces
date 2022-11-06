#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<llong> b(n / 2);
    for (auto& i : b) {
        cin >> i;
    }

    vector<llong> a(n);
    a[n - 1] = b[0];
    for (int i = 1; i < isz(b); i++) {
        a[i] = a[i - 1];
        a[n - 1 - i] = b[i] - a[i];
        llong t = a[n - i - 1] - a[n - i];
        if (t > 0) {
            a[n - i - 1] -= t;
            a[i] += t;
        }
    }

    for (auto& i : a) {
        cout << i << " ";
    }



    return 0;
}