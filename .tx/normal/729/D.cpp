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

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    s += "1";
    n++;
    int l = -1;
    vector<pair<int, int>> ls;
    int pp = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == '1') {
            int c = i - l - 1;
            if (c >= b) {
                ls.push_back({c, l + 1});
                pp += c / b;
            }
            l = i;
        }
    }

    sort(ls.rbegin(), ls.rend());
    vector<int> ans;
    while (pp >= a) {
        int c = ls.back().first;
        int p = ls.back().second;
        ls.pop_back();
        int t = c / b;
        for (int i = 0; pp >= a && i < t; i++) {
            ans.push_back(p + b);
            p += b;
            pp--;
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }


    return 0;
}//xdqvzv