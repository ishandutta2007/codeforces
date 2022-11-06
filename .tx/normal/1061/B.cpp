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

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    sort(rbegin(a), rend(a));
    a.push_back(0);
    llong ans = accumulate(begin(a), end(a), 0LL);

    int cl = a[0];

    for (int i = 0; i < n; i++) {
        ans -= max(1, cl - a[i + 1]);
        cl = min(cl - 1, a[i + 1]);
    }

    cout << ans;

    return 0;
}//kkqghu