#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' && a.size() * 2 < k) {
            a.push_back(i);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')' && a.size() < k) {
            a.push_back(i);
        }
    }

    sort(a.begin(), a.end());
    for (int i : a) {
        cout << s[i];
    }

    return 0;
}//zphiop