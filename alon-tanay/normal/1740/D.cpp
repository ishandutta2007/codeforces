#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT =
#define enl "\n";
#define debug(k)                             \
    for (int _ = 0; _ < DEBUG_INDENT; _++) { \
        cout << "  ";                        \
    }                                        \
    cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

struct Seg {
    vector<int> seg;
    int n;
    Seg(int n) : n(n), seg(n * 2) {}
    void add(int i) {
        i += n;
        seg[i]++;
        for (i >>= 1; i; i >>= 1) {
            seg[i] = seg[i << 1] + seg[(i << 1) | 1];
        }
    }
    int query(int a, int b) {
        int res = 0;
        for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                res += seg[a++];
            }
            if (b & 1) {
                res += seg[--b];
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> lc(k + 1);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            lc[x] = i;
        }
        int mx = 0;
        Seg seg(k);
        for (int i = k; i >= 1; i--) {
            mx = max(mx, lc[i] - seg.query(0, lc[i] + 1));
            seg.add(lc[i]);
        }
        bool fail = mx >= n * m - 3;
        cout << (fail ? "TIDAK\n" : "YA\n");
    }
    return 0;
}