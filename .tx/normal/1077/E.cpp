#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> a;
    for (auto& i : cnt) {
        a.push_back(i.second);
    }

    sort(a.begin(), a.end());

//    for (int i : a) {
//        cout << i << " ";
//    }
//    cout << "\n";

    llong ans = 0;
    for (int f = 1; f <= n; f++) {
        llong cur = 0;
        llong x = f;
        auto it = a.begin();

        while (true) {
            auto nit = lower_bound(it, a.end(), x);
//            cout << f << " " << x << " " << nit - a.begin() << "\n";
            if (nit == a.end()) {
                break;
            }
            cur += x;
            x *= 2;
            it = nit + 1;
        }

        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}