#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int n;
int a[111111];
int win[111111];

int dfs(int v) {
    if (win[v]) {
        return win[v];
    }
    int x = a[v];
    for (int i = v; i < n; i += x) {
        if (a[i] > x) {
            int t = dfs(i);
            if (t == -1) {
                return win[v] = 1;
            }
        }
    }
    for (int i = v; i >= 0; i -= x) {
        if (a[i] > x) {
            int t = dfs(i);
            if (t == -1) {
                return win[v] = 1;
            }
        }
    }

    return win[v] = -1;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (dfs(i) == 1) {
            cout << 'A';
        } else {
            cout << 'B';
        }
    }


    return 0;
}//vavphb