#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

const int M1 = int(1e9) + 7;
const int M2 = int(1e9) + 31;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    map<pair<llong, llong>, set<int>> m;

    int n;
    cin >> n;
    vector<string> ss(n);
    for (int in = 0; in < n; in++) {
        string s;
        cin >> s;
        ss[in] = s;
        for (int i = 0; i < csz(s); i++) {
            llong h1 = 0, h2 = 0;
            for (int j = i; j < csz(s); j++) {
                h1 = (h1 * 997 + s[j]) % M1;
                h2 = (h2 * 239 + s[j]) % M2;
                m[{h1, h2}].insert(in);
            }
        }
    }

    int q;
    cin >> q;
    for (int iq = 0; iq < q; iq++) {
        string s;
        cin >> s;

        llong h1 = 0, h2 = 0;
        for (char c : s) {
            h1 = (h1 * 997 + c) % M1;
            h2 = (h2 * 239 + c) % M2;
        }

        auto it = m.find({h1, h2});
        if (it == m.end()) {
            cout << "0 -\n";
        } else {
            cout << it->second.size() << " " << ss[*(it->second.begin())] << "\n";
        }

    }

    return 0;
}//fzkltw