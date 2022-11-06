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
    vector<int> a(n);
    vector<pair<int, int>> negs;
    vector<int> zs;
    vector<int> used(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            negs.push_back({a[i], i});
        }
        if (a[i] == 0) {
            zs.push_back(i);
        }
    }

    int co = 0;

    while (zs.size() > 1) {
        cout << "1 " << zs.back() + 1 << " ";
        used[zs.back()] = 1;
        zs.pop_back();
        cout << zs.back() + 1 << "\n";
        co++;
    }

    if (negs.size() % 2) {
        sort(negs.begin(), negs.end());
        if (!zs.empty()) {
            cout << "1 " << zs.back() + 1 << " " << negs.back().second + 1 << "\n";
            used[zs.back()] = 1;
            zs.pop_back();
            co++;
        }
        if (co + 1 < n) {
            cout << "2 " << negs.back().second + 1 << "\n";
            used[negs.back().second] = 1;
            negs.pop_back();
        }
    }

    if (co + 1 < n && zs.size()) {
        cout << "2 " << zs.back() + 1 << "\n";
        used[zs.back()] = 1;
    }


    int p = -1;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (p == -1) {
                p = i;
            } else {
                cout << "1 " << i + 1 << " " << p + 1 << "\n";
            }
        }
    }


    return 0;
}//zfyxol