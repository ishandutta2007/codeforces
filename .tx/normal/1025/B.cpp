#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

bool is_prime(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<int> ds;
    for (int i = 1; i * i <= a[0].first; i++) {
        if (a[0].first % i == 0) {
            if (is_prime(i)) {
                ds.push_back(i);
            }
            if (is_prime(a[0].first / i)) {
                ds.push_back(a[0].first / i);
            }
        }
    }

    for (int i = 1; i * i <= a[0].second; i++) {
        if (a[0].second % i == 0) {
            if (is_prime(i)) {
                ds.push_back(i);
            }
            if (is_prime(a[0].second / i)) {
                ds.push_back(a[0].second / i);
            }
        }
    }

    for (int d : ds) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i].first % d != 0 && a[i].second % d != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << d;
            return 0;
        }
    }

    cout << -1;

    return 0;
}//iyapcg