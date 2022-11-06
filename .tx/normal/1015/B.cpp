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
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> a1, a2;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (s[j - 1] > s[j]) {
                a1.push_back(j - 1);
                swap(s[j - 1], s[j]);
            }
            if (t[j - 1] > t[j]) {
                a2.push_back(j - 1);
                swap(t[j - 1], t[j]);
            }
        }
    }

    if (s != t) {
        cout << -1;
        return 0;
    }

    cout << a1.size() + a2.size() << "\n";
    for (int i : a1) {
        cout << i + 1 << " ";
    }
    reverse(a2.begin(), a2.end());
    for (int i : a2) {
        cout << i + 1 << " ";
    }

    return 0;
}