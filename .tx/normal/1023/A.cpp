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

    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    if (s.find('*') == string::npos) {
        if (s == t) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        return 0;
    }

    bool ok = true;
    int l = 0;
    for (; l < n && s[l] != '*'; l++) {
        if (l >= m || s[l] != t[l]) {
            ok = false;
            break;
        }
    }
    int r = n - 1;
    for (; r >= 0 && s[r] != '*'; r--) {
        int ti = m - (n - r);
        if (ti < 0 || s[r] != t[ti]) {
            ok = false;
            break;
        }
    }

    --l;
    ++r;
    if (l >= m - (n - r)) {
        ok = false;
    }

    for (int ti = l + 1; ti < m - (n - r); ti++) {
        if (t[ti] < 'a' || t[ti] > 'z') {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}//lsiwmr