#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int d[111111][222][3];

const int M = 998244353;

void add(int& a, int b) {
    if (b >= M) {
        b -= M;
    }
    a += b;
    if (a >= M) {
        a -= M;
    }
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 200; i++) {
        if (a[0] == -1 || a[0] == i) {
            d[0][i][1] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        int s0 = 0, s1 = 0, s2 = 0;

        if (i > 1) {
            for (int j = 200; j >= 1; j--) {
                if (a[i] == -1 || a[i] == j) {
                    add(d[i][j][0], s0);
                }
                add(s0, d[i - 1][j][0] + d[i - 1][j][1]);
            }
        }

        for (int j = 1; j <= 200; j++) {
            if (a[i] == -1 || a[i] == j) {
                add(d[i][j][1], d[i - 1][j][0]);
                add(d[i][j][1], d[i - 1][j][1]);
                add(d[i][j][1], d[i - 1][j][2]);
            }
        }

        for (int j = 1; j <= 200; j++) {
            if (a[i] == -1 || a[i] == j) {
                add(d[i][j][2], s2);
            }
            add(s2, d[i - 1][j][0]);
            add(s2, d[i - 1][j][1]);
            add(s2, d[i - 1][j][2]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= 200; i++) {
        add(ans, d[n - 1][i][0]);
        add(ans, d[n - 1][i][1]);
    }

    cout << ans;

    return 0;
}//rlanht