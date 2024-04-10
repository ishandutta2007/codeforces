#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;
    int n = isz(s);
    sort(begin(s), end(s));
    sort(begin(t), end(t));
    deque<char> x(begin(s), begin(s) + (n + 1) / 2);
    deque<char> y(end(t) - n / 2, end(t));

    string ans(n, '?');
    int l = 0, r = n - 1;

    for (int i = 0; i < n; i++) {
        if (i & 1) {
            if (!x.empty() && x.front() < y.back()) {
                ans[l++] = y.back();
                y.pop_back();
            } else {
                ans[r--] = y.front();
                y.pop_front();
            }
        } else {
            if (!y.empty() && y.back() > x.front()) {
                ans[l++] = x.front();
                x.pop_front();
            } else {
                ans[r--] = x.back();
                x.pop_back();
            }
        }
    }

    cout << ans << "\n";

    return 0;
}//nmdfzd