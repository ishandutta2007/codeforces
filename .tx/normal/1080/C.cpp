#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

pair<llong, llong> get(llong x, llong y) {
    x++; y++;
    if (x < 0 || y < 0) {
        return {0, 0};
    }
    llong w = ((x + 1) / 2) * ((y + 1) / 2) + (x / 2) * (y / 2);
    llong b = x * y - w;
    return {w, b};
}

pair<llong, llong> get(llong x1, llong y1, llong x2, llong y2) {
    auto a = get(x2, y2);
    auto l = get(x1 - 1, y2);
    auto d = get(x2, y1 - 1);
    auto ld = get(x1 - 1, y1 - 1);

    llong w = a.first - l.first - d.first + ld.first;
    llong b = (x2 - x1 + 1) * (y2 - y1 + 1) - w;

    return {w, b};
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for (int it = 0; it < t; it++) {
        int n, m;
        cin >> n >> m;
        auto [w, b] = get(n - 1, m - 1);

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1; --y1; --x2; --y2;

        auto [w1, b1] = get(x1, y1, x2, y2);
        w += b1;
        b -= b1;

        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;
        --x3; --y3; --x4; --y4;

        auto [w2, b2] = get(x3, y3, x4, y4);
        w -= w2;
        b += w2;

        int xx1 = max(x1, x3);
        int xx2 = min(x2, x4);
        int yy1 = max(y1, y3);
        int yy2 = min(y2, y4);

        if (xx1 <= xx2 && yy1 <= yy2) {
            auto [ww, bb] = get(xx1, yy1, xx2, yy2);
            w -= bb;
            b += bb;
        }

        cout << w << " " << b << "\n";
    }

    return 0;
}//oxskso