#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    llong s = 0;
    multiset<llong> p;
    for (auto& i : a) {
        cin >> i;
        s += i;
        p.insert(i);
    }

    multiset<llong> ns;
    llong l = 0, r;
    for (int i = 0; i < n; i++) {
        l += a[i];
        r = s - l;
        if (l == r) {
            cout << "YES\n";
            return 0;
        }
        ns.insert(a[i]);
        if (l > r && (l - r) % 2 == 0 && ns.find((l - r) / 2) != end(ns)) {
            cout << "YES\n";
            return 0;
        }
        p.erase(p.find(a[i]));
        if (l < r && (r - l) % 2 == 0 && p.find((r - l) / 2) != end(p)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}//eusddy