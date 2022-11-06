#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    if (s.find("11") != string::npos || s.find("000") != string::npos || (n > 1 && (s.substr(0, 2) == "00" || s.substr(n - 2, 2) == "00")) || s == "0") {
        cout << "No";
    } else {
        cout << "Yes";
    }

    return 0;
}