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

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<int> s(m);
    vector<int> cnt(1 << n);
    for (int i = 0; i < m; i++) {
        string x;
        cin >> x;
        int& r = s[i];
        for (char c : x) {
            r = (r << 1) | (c - '0');
        }
        cnt[r]++;
    }

    vector<int> c(1 << n);
    for (int b = 0; b < (1 << n); b++) {
        for (int i = 0; i < n; i++) {
            if (((b >> i) & 1) == 0) {
                c[b] += w[n - 1 - i];
            }
        }
    }

    vector<vector<pair<int, int>>> d(1 << n, vector<pair<int, int>>(1 << n));
    for (int b = 0; b < (1 << n); b++) {
        for (int i = 0; i < (1 << n); i++) {
            d[b][i] = {c[b ^ i], cnt[i]};
        }
        sort(begin(d[b]), end(d[b]));
        for (int i = 1; i < isz(d[b]); i++) {
            d[b][i].second += d[b][i - 1].second;
        }
    }

    for (int iq = 0; iq < q; iq++) {
        string x;
        cin >> x;
        int r = 0;
        for (char c : x) {
            r = (r << 1) | (c - '0');
        }
        int k;
        cin >> k;
        auto it = lower_bound(begin(d[r]), end(d[r]), pair(k + 1, -1));
        if (it == begin(d[r])) {
            cout << "0\n";
        } else {
            --it;
            cout << it->second << "\n";
        }
    }


    return 0;
}//snmalx