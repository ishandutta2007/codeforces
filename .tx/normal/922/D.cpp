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

    int n;
    cin >> n;
    vector<string> a(n);
    vector<int> s(n);
    vector<int> h(n);
    vector<int> id(n);

    for (int i = 0; i < n; i++) {
        id[i] = i;
        cin >> a[i];
        for (int c : a[i]) {
            if (c == 's') {
                s[i]++;
            } else {
                h[i]++;
            }
        }
    }

    sort(id.begin(), id.end(), [&](int x, int y) {
        return 1LL * s[x] * h[y] > 1LL * s[y] * h[x];
    });

    string t = "";
    for (int i : id) {
        t += a[i];
    }

    int cs = 0;
    llong ans = 0;
    for (int c : t) {
        if (c == 's') {
            cs++;
        } else {
            ans += cs;
        }
    }

    cout << ans;

    return 0;
}//fomrgc