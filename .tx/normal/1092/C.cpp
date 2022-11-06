#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

#define all(c) begin(c), end(c)

mt19937 rng((size_t) make_shared<char>().get());

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<string> a(2 * n - 2);
    vector<string> b;
    for (int i = 0; i < 2 * n - 2; i++) {
        cin >> a[i];
        if (isz(a[i]) == n - 1) {
            b.push_back(a[i]);
        }
    }

    vector<int> ans(2 * n - 2);
    vector<int> p(n);
    vector<int> s(n);

    for (int tt = 0; tt < 2; tt++) {
        string w = b[0] + b[1].back();
        bool ok = true;
        for (int i = 0; i < isz(a); i++) {
            int x = isz(a[i]);
            if (p[x] == 0 && w.substr(0, x) == a[i]) {
                ans[i] = 1;
                p[x] = 1;
            } else if (s[x] == 0 && w.substr(n - x, x) == a[i]) {
                ans[i] = 2;
                s[x] = 1;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            break;
        }
        assert(tt == 0);
        swap(b[0], b[1]);
        fill(all(p), 0);
        fill(all(s), 0);
    }

    for (int i : ans) {
        cout << (i == 1 ? 'P' : 'S');
    }

    return 0;
}//mastvr