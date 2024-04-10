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
    map<llong, set<int>> cnt;
    vector<string> a(n);
    int id = 0;
    for (auto& i : a) {
        cin >> i;
        id++;
        for (int j = 0; j < isz(i); j++) {
            llong c = 1;
            for (int k = 0; k + j < isz(i); k++) {
                c = c * 10 + i[k + j] - '0';
                cnt[c].insert(id);
            }
        }
    }

    for (auto& s : a) {
        int ans = isz(s);
        int ai = 0;
        for (int i = 0; i < isz(s); i++) {
            llong c = 1;
            for (int k = 0; k + i < isz(s); k++) {
                c = c * 10 + s[i + k] - '0';
                if (cnt[c].size() == 1) {
                    if (k + 1 < ans) {
                        ans = k + 1;
                        ai = i;
                    }
                }
            }
        }
        for (int i = 0; i < ans; i++) {
            cout << s[ai + i];
        }
        cout << "\n";
    }

    return 0;
}//nefqyn