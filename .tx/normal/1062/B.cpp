#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto sz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    if (n == 1) {
        cout << "1 0";
        return 0;
    }
    vector<int> ps;
    int a = 1;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            a *= i;
            ps.push_back(0);
            while (n % i == 0) {
                n /= i;
                ps.back()++;
            }
        }
    }

    sort(ps.begin(), ps.end());
    int x = ps.back();
    int ans = 0;
    if ((x & (x - 1)) || ps.back() != ps.front()) {
        ans = 1;
    }
    while (x > 1) {
        ans++;
        x = (x + 1) / 2;
    }

    cout << a << " " << ans;


    return 0;
}//nmfxrt