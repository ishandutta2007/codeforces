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

    string s;
    cin >> s;
    int n = csz(s);
    int a = (n + 19) / 20;
    int b = (n + a - 1) / a;
    int c = 0;
    int r = a * b;
    cout << a << " " << b << "\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j + 1 < b; j++) {
            cout << s[c++];
            r--;
        }
        if (n - c < r) {
            cout << "*";
        } else {
            cout << s[c++];
        }
        r--;
        cout << "\n";
    }

    return 0;
}//dysgna