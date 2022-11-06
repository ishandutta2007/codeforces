#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

llong fact[22];
int nc[11];
int c[11];

llong ans = 0;

void go(int i) {
    if (i == 10) {
        int s = 0;
        for (int j = 0; j < 10; j++) {
            s += c[j];
        }

        for (int j = 1; j < 10; j++) {
            if (c[j] == 0) {
                continue;
            }
            c[j]--;
            llong cr = fact[s - 1];
            for (int t = 0; t < 10; t++) {
                cr /= fact[c[t]];
            }
            c[j]++;
            ans += cr;
        }

        return;
    }

    if (nc[i] == 0) {
        go(i + 1);
    }

    for (int j = 1; j <= nc[i]; j++) {
        c[i] = j;
        go(i + 1);
    }
}

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < 22; i++) {
        fact[i] = i * fact[i - 1];
    }

    llong n;
    cin >> n;
    while (n) {
        nc[n % 10]++;
        n /= 10;
    }

    go(0);

    cout << ans;

    return 0;
}