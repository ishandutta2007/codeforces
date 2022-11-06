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
    vector<int> a[4];
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        int r = (s[0] - '0') * 2 + s[1] - '0';
        a[r].push_back(x);
    }

    for (int i = 0; i < 4; i++) {
        sort(begin(a[i]), end(a[i]));
    }

    int ans = 0;
    int k = 0;
    for (int i : a[3]) {
        ans += i;
        k++;
    }

    while (a[1].size() && a[2].size()) {
        ans += a[1].back() + a[2].back();
        a[1].pop_back();
        a[2].pop_back();
    }

    a[0].insert(a[0].end(), begin(a[1]), end(a[1]));
    a[0].insert(a[0].end(), begin(a[2]), end(a[2]));
    sort(rbegin(a[0]), rend(a[0]));
    for (int i = 0; i < min(k, isz(a[0])); i++) {
        ans += a[0][i];
    }

    cout << ans;

    return 0;
}//gisugk