#ifdef VSE
#define _GLIBCXX_DEBUG
#endif
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
    llong t;
    cin >> n >> t;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    llong ans = 0;
    while (!a.empty()) {
        llong s = accumulate(a.begin(), a.end(), 0LL);
        llong k = t / s;
        ans += k * a.size();
        t -= k * s;
        vector<int> b;
        for (int i : a) {
            if (t >= i) {
                t -= i;
                ans++;
                b.push_back(i);
            }
        }
        a = b;
    }

    cout << ans;


    return 0;
}//uoxscv