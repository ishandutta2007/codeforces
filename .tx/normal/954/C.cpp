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
    if (n == 1) {
        cout << "YES\n1000000000 1000000000\n";
        return 0;
    }
    int mx = 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        if (i) {
            mx = max(mx, abs(a[i] - a[i - 1]));
        }
    }

    int y = mx;
    int x = (*max_element(begin(a), end(a)) + y) / y;

    int vx = a[0] / y;
    int vy = a[0] % y;

    for (int i = 1; i < n; i++) {
        int nx = a[i] / y;
        int ny = a[i] % y;
        if (nx == vx && abs(ny - vy) == 1 || ny == vy && abs(vx - nx) == 1) {
            vx = nx;
            vy = ny;
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n" << x << " " << y << "\n";

    return 0;
}//rmbrhe