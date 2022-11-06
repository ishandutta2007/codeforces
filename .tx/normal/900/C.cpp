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
    set<int> s;
    vector<int> r(n);
    vector<int> cm(n);
    vector<int> om(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (s.empty() || *s.rbegin() < a[i]) {
            r[i] = true;
        } else {
            om[i] = *s.rbegin();
            cm[i] = 1;
            if (s.size() > 1) {
                auto it = s.rbegin();
                ++it;
                if (*it > a[i]) {
                    cm[i]++;
                }
            }
        }
        s.insert(a[i]);
    }

    vector<int> hm(n + 1);
    for (int i = 0; i < n; i++) {
        if (cm[i] == 1) {
            hm[om[i]]++;
        }
    }

    int ans = -1e9;
    int ai = -1;
    for (int i = 0; i < n; i++) {
        int c = 0;
        if (r[i]) {
            c--;
        }
        c += hm[a[i]];
        if (c > ans || (c == ans && a[i] < ai)) {
            ans = c;
            ai = a[i];
        }
    }

    cout << ai;

    return 0;
}//gqltbd