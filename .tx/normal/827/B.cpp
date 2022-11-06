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

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ans;
    vector<int> cur(k);
    int x = n;
    for (int i = 0; i < k; i++) {
        cur[i] = --x;
    }
    int ll = 0;
    while (x) {
        ll += 2;
        vector<int> nx;
        if (x <= k) {
            int t = -1;
            if (x > 2) {
                t = --x;
            }
            int cx = x;
            for (int i = 0; i < x; i++) {
                nx.push_back(--cx);
                ans.emplace_back(cx, cur[i]);
            }
            for (int i = x; i < k; i++) {
                ans.emplace_back(cx, cur[i]);
            }
            if (t != -1) {
                ll += 2;
                for (int i : nx) {
                    ans.emplace_back(i, t);
                }
            } else {
                for (int i = 0; i + 1 < csz(nx); i++) {
                    ans.emplace_back(nx[i], nx[i + 1]);
                    ll++;
                }
            }
            break;
        }
        for (int i = 0; i < k; i++) {
            nx.emplace_back(--x);
            ans.emplace_back(x, cur[i]);
        }
        cur = nx;
    }

    cout << ll << "\n";
    for (auto& i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }

    return 0;
}//wkgoeh