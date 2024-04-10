#include <bits/stdc++.h>

using namespace std;
#define int long long

const int INF = 1e16;
const int mod = 998244353;
vector <int> a, b, c, tree, pref, ob;
int len;

void build(int v, int l, int r) {
    if (l == r) {
        if (l >= a.size()) tree[v] = -1;
        else tree[v] = c[a[l]];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

int get(int v, int l, int r, int A, int B) {
    if (l > B || A > r) return -1;
    if (A <= l && r <= B) return tree[v];
    int m = (l + r) / 2;
    return max(get(2 * v, l, m, A, B), get(2 * v + 1, m + 1, r, A, B));
}

int calc(int l, int r) {
    int lvl = get(1, 0, len - 1, l, r);
    if (lvl == -1) return 1;
    int left = calc(l, ob[b[lvl]] - 1);
    int right = calc(ob[b[lvl]] + 1, r);
    int cur = 0;
    if ((ob[b[lvl]] - l) - (pref[ob[b[lvl]]] - pref[l]) > 0) {
        cur = (left * right) % mod;
    }
    if ((r - ob[b[lvl]]) - (pref[r + 1] - pref[ob[b[lvl]] + 1]) > 0) {
        cur += (left * right) % mod;
    }
    cur %= mod;
    return cur;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        a.assign(n, 0);
        b.assign(k, 0);
        len = (1 << (int)ceil(log2(n)));
        ob.assign(n, 0);
        c.assign(len, -1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
            ob[a[i]] = i;
        }
        for (int i = 0; i < k; ++i) {
            cin >> b[i]; b[i]--;
            c[b[i]] = i;
        }
        tree.assign(2 * len, -1);
        pref.assign(n + 1, 0);
        build(1, 0, len - 1);
        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1];
            if (c[a[i - 1]] != -1) ++pref[i];
        }
        cout << calc(0, n - 1) << "\n";
    }
}