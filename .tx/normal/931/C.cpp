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
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    if (cnt.size() == 2) {
        int f = cnt.begin()->first;
        int l = cnt.rbegin()->first;
        if (f + 1 < l) {
            cnt[f + 1] = 0;
        }
    }
    if (cnt.size() < 3) {
        cout << n << "\n";
        for (auto& p : cnt) {
            for (int i = 0; i < p.second; i++) {
                cout << p.first << " ";
            }
        }
    } else {
        vector<int> a;
        for (auto& p : cnt) {
            a.push_back(p.first);
        }
        if (cnt[a[1]] / 2 * 2 > 2 * min(cnt[a[0]], cnt[a[2]])) {
            cout << n - cnt[a[1]] / 2 * 2 << "\n";
            cnt[a[0]] += cnt[a[1]] / 2;
            cnt[a[2]] += cnt[a[1]] / 2;
            cnt[a[1]] %= 2;
        } else {
            int t = min(cnt[a[0]], cnt[a[2]]);
            cout << n - 2 * t << "\n";
            cnt[a[0]] -= t;
            cnt[a[2]] -= t;
            cnt[a[1]] += 2 * t;
        }
        for (auto& p : cnt) {
            for (int i = 0; i < p.second; i++) {
                cout << p.first << " ";
            }
        }
    }

    return 0;
}//cwlbkp