#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int a[111][111];

void f(int n, int k, int i) {
    if (k == 0 || n == 0) {
        return;
    }
    a[i][i] = 1;
    --k;
    for (int j = 1; k >= 2 && j < n; j++) {
        a[i + j][i] = a[i][i + j] = 1;
        k -= 2;
    }
    f(n - 1, k, i + 1);
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    if (k > n * n) {
        cout << -1;
        return 0;
    }

    f(n, k, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}//ouxymm