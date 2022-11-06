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

    llong n, m, k;
    cin >> n >> m >> k;
    if ((2 * n * m) % k) {
        cout << "NO\n";
        return 0;
    }
    if (n * m % k) {
        k /= 2;
        llong g = __gcd(n, k);
        llong g2 = __gcd(m, k / g);
        cout << "YES\n";
        cout << "0 0\n";
        cout << "0 " << m / g2 << "\n";
        cout << n / g << " 0\n";
    } else {
        llong g = __gcd(n, k);
        llong g2 = __gcd(m, k / g);
        llong a1 = n / g;
        llong a2 = m / g2;
        if (a1 * 2 <= n) {
            a1 *= 2;
        } else {
            a2 *= 2;
        }
        cout << "YES\n";
        cout << "0 0\n";
        cout << "0 " << a2 << "\n";
        cout << a1 << " 0\n";
    }


    return 0;
}//gcuyci