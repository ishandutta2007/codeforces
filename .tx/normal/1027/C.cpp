#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

vector<int> cnt(11111);

void f(const vector<int>& a) {
    vector<int> b;
    for (int i : a) {
        cnt[i]++;
        if (cnt[i] == 4) {
            for (int j = 0; j < 4; j++) {
                cout << i << " ";
            }
            cout << "\n";
            return;
        }
        if (cnt[i] == 2) {
            b.push_back(i);
        }
    }

    sort(b.begin(), b.end());
    int ai = 0;
    for (int i = 1; i + 1 < b.size(); i++) {
        int ap = 2 * (b[ai] + b[ai + 1]);
        int as = b[ai] * b[ai + 1];

        int cp = 2 * (b[i] + b[i + 1]);
        int cs = b[i] * b[i + 1];
        if (1LL * cp * cp * as < 1LL * ap * ap * cs) {
            ai = i;
        }
    }

    cout << b[ai] << " " << b[ai] << " " << b[ai + 1] << " " << b[ai + 1] << "\n";
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        f(a);
        for (int i : a) {
            cnt[i] = 0;
        }
    }

    return 0;
}//rdwfhv