#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
mt19937 rng((size_t) make_shared<char>().get());

int ask(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

int main(int argc, char** argv) {
#ifdef VSE
    // if (argc > 1) assert(freopen(argv[1], "r", stdin));
    rng.seed(0);
#endif
#ifndef cin
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

    vector<int> c = {4, 8, 15, 16, 23, 42};

    vector<int> ans;

    for (int z = 0; z < 2; z++) {

        int r1 = ask(z * 3, z * 3 + 1);
        int r2 = ask(z * 3 + 1, z * 3 + 2);

        vector<int> a, b;
        for (int i = 0; i < 6; i++) {
            for (int j = i + 1; j < 6; j++) {
                if (c[i] * c[j] == r1) {
                    a.push_back(i);
                    a.push_back(j);
                }

                if (c[i] * c[j] == r2) {
                    b.push_back(i);
                    b.push_back(j);
                }
            }
        }

        int x = -1;
        for (int i : a) {
            if (find(begin(b), end(b), i) != end(b)) {
                x = i;
                break;
            }
        }

        assert(x != -1);

        if (a[0] == x) {
            swap(a[0], a[1]);
        }
        if (b[0] == x) {
            swap(b[0], b[1]);
        }

        ans.push_back(c[a[0]]);
        ans.push_back(c[x]);
        ans.push_back(c[b[0]]);
    }

    cout << "! ";

    for (int i : ans) {
        cout << i << ' ';
    }

    return 0;
}