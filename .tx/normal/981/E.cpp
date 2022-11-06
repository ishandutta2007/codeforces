#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

const int N = 11111;

vector<int> t[4 * N];
bitset<N> ans;

void add(int i, int l, int r, int ql, int qr, int x) {
    if (r <= ql || qr <= l) {
        return;
    }

    if (ql <= l && r <= qr) {
        t[i].push_back(x);
        return;
    }

    int m = (l + r) >> 1;
    add(i * 2 + 1, l, m, ql, qr, x);
    add(i * 2 + 2, m, r, ql, qr, x);
}

void go(int i, int l, int r, bitset<N> cur) {
    for (int x : t[i]) {
        cur |= cur << x;
    }

    if (l + 1 == r) {
        ans |= cur;
        return;
    }

    int m = (l + r) >> 1;
    go(i * 2 + 1, l, m, cur);
    go(i * 2 + 2, m, r, cur);
}

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        add(0, 0, N, l - 1, r, x);
    }

    bitset<N> cur;
    cur[0] = 1;

    go(0, 0, N, cur);

    vector<int> a;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) {
            a.push_back(i);
        }
    }

    cout << a.size() << "\n";
    for (int i : a) {
        cout << i << " ";
    }

    return 0;
}