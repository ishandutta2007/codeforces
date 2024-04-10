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

    int n, c, d;
    cin >> n >> c >> d;
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; i++) {
        int x, y;
        string s;
        cin >> y >> x >> s;
        if (s[0] == 'C') {
            a.emplace_back(x, y);
        } else {
            b.emplace_back(x, y);
        }
    }

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    vector<int> mxa(sz(a)), mxb(sz(b));

    for (int i = 0; i < sz(a); i++) {
        mxa[i] = a[i].second;
        if (i) {
            mxa[i] = max(mxa[i], mxa[i - 1]);
        }
    }

    for (int i = 0; i < sz(b); i++) {
        mxb[i] = b[i].second;
        if (i) {
            mxb[i] = max(mxb[i], mxb[i - 1]);
        }
    }

    int ma = 0, mb = 0;

    int ans = 0;
    int p = -1;
    for (int i = 0; i < sz(a); i++) {
        if (a[i].first > c) {
            break;
        }
        ma = mxa[i];
        while (p >= 0 && (p == i || a[i].first + a[p].first > c)) {
            p--;
        }
        if (p >= 0) {
            ans = max(ans, a[i].second + mxa[p]);
        }
        p++;
    }

    p = -1;
    for (int i = 0; i < sz(b); i++) {
        if (b[i].first > d) {
            break;
        }
        mb = mxb[i];
        while (p >= 0 && (p == i || b[i].first + b[p].first > d)) {
            p--;
        }
        if (p >= 0) {
            ans = max(ans, b[i].second + mxb[p]);
        }
        p++;
    }

    if (ma != 0 && mb != 0) {
        ans = max(ans, ma + mb);
    }

    cout << ans;

    return 0;
}//yeqqsa