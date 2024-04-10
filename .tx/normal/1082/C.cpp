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
    int ans = 0;
    vector<vector<int>> a(m);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        a[x].push_back(y);
    }
    for (auto& i : a) {
        sort(rbegin(i), rend(i));
    }

    vector<int> b(m);
    vector<int> s(m);
    for (int i = 0; i < m; i++) {
        b[i] = i;
    }

    for (int k = 1; k <= n; k++) {
        int cs = 0;
        int i = 0;
        while (i < csz(b)) {
            int x = b[i];
            if (csz(a[x]) < k || s[i] + a[x][k - 1] < 0) {
                swap(b[i], b.back());
                swap(s[i], s.back());
                b.pop_back();
                s.pop_back();
                continue;
            } else {
                s[i] += a[x][k - 1];
                cs += s[i];
                i++;
            }
        }
        ans = max(ans, cs);
    }

    cout << ans;

    return 0;
}//fpslie