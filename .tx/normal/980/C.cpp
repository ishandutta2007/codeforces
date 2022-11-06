#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

const int N = 111111;

int a[N];
int rk[N];
int mn[N];
int sz[N];

void init() {
    for (int i = 0; i < N; i++) {
        a[i] = i;
        rk[i] = 1;
        mn[i] = i;
        sz[i] = 1;
    }
}

int get(int x) {
    return a[x] == x ? x : a[x] = get(a[x]);
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
        return;
    }
    if (rk[x] < rk[y]) {
        a[x] = y;

    } else {
        a[y] = x;
        if (rk[x] == rk[y]) {
            rk[x]++;
        }
    }

    mn[get(x)] = min(mn[x], mn[y]);
    sz[get(x)] = sz[x] + sz[y];
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    init();

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (true) {
            int m = mn[get(x)];
            if (m == 0) {
                break;
            }
            if (sz[get(m)] + sz[get(m - 1)] > k) {
                break;
            }
            unite(m, m - 1);
        }
        cout << mn[get(x)] << " ";
    }

    return 0;
}