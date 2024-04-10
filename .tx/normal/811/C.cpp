#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    vector<int> nx(n, -1);
    vector<int> pr(n, -1);
    vector<int> lst(5555, -1);
    for (int i = 0; i < n; i++) {
        if (lst[a[i]] != -1) {
            pr[i] = lst[a[i]];
            nx[lst[a[i]]] = i;
        }
        lst[a[i]] = i;
    }

    vector<int> d(n + 1);
    vector<int> cnt(5555);
    for (int i = n - 1; i >= 0; i--) {
        d[i] = d[i + 1];
        if (pr[i] != -1) {
            continue;
        }
        int j = i;
        int mx = nx[j];
        fill(begin(cnt), end(cnt), 0);
        int c = a[i];
        cnt[a[i]]++;
        while (j < n) {
            if (j >= mx) {
                d[i] = max(d[i], c + d[j + 1]);
            }
            if (j + 1 == n) {
                break;
            }
            j++;
            if (pr[j] != -1 && pr[j] < i) {
                break;
            }
            mx = max(mx, nx[j]);
            if (cnt[a[j]] == 0) {
                cnt[a[j]] = 1;
                c ^= a[j];
            }
        }
    }

    cout << *max_element(begin(d), end(d));

    return 0;
}//ejjdwm