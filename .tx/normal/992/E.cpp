#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

const int N = 222222;

llong s[4 * N];
int mx[4 * N];

void tset(int i, int l, int r, int qi, int qx) {
    if (l + 1 == r) {
        s[i] = qx;
        mx[i] = qx;
        return;
    }
    int m = (l + r) >> 1;
    if (qi < m) {
        tset(i * 2 + 1, l, m, qi, qx);
    } else {
        tset(i * 2 + 2, m, r, qi, qx);
    }
    s[i] = s[i * 2 + 1] + s[i * 2 + 2];
    mx[i] = max(mx[i * 2 + 1], mx[i * 2 + 2]);
}

llong gets(int i, int l, int r, int ql, int qr) {
    if (ql >= r || l >= qr) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return s[i];
    }
    int m = (l + r) >> 1;
    return gets(i * 2 + 1, l, m, ql, qr) + gets(i * 2 + 2, m, r, ql, qr);
}

int findm(int i, int l, int r, int ql, int qr, int qm) {
    if (r <= ql || qr <= l) {
        return N;
    }
    if (mx[i] < qm) {
        return N;
    }
    if (l + 1 == r) {
        return l;
    }
    int m = (l + r) >> 1;
    int res = findm(i * 2 + 1, l, m, ql, qr, qm);
    if (res == N) {
        res = findm(i * 2 + 2, m, r, ql, qr, qm);
    }
    return res;
}

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tset(0, 0, n, i, x);
    }

    for (int iq = 0; iq < q; iq++) {
        int p, x;
        cin >> p >> x;
        --p;
        tset(0, 0, n, p, x);
        int ck = 0;
        bool any = false;
        while (true) {
            llong bs = gets(0, 0, n, 0, ck);
            llong gs = gets(0, 0, n, ck, ck + 1);
            if (gs == bs) {
                cout << ck + 1 << "\n";
                any = true;
                break;
            }
            if (bs + gs > 1e9) {
                break;
            }
            ck = findm(0, 0, n, ck + 1, n, bs + gs);
            if (ck == N) {
                break;
            }
        }
        if (!any) {
            cout << "-1\n";
        }
    }

    return 0;
}