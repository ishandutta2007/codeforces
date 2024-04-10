#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 3e5 + 5;
int mod = 1e9 + 7;
int used[2 * maxn], p[maxn], ok[2 * maxn], go[maxn];
pair < int, int > ask[maxn];
unordered_map < int, int > ptr;
int cnt[(1 << 21)], sum_a[(1 << 21)], sum_b[(1 << 21)], ans[(1 << 21)];

int st(int x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) {
        int c = st(x, y / 2);
        return c * c % mod;
    }
    return x * st(x, y - 1) % mod;
}

inline void merge(int i) {
    cnt[i] = cnt[2 * i + 1] + cnt[2 * i + 2];
    ans[i] = (ans[2 * i + 1] * go[cnt[2 * i + 2]] + ans[2 * i + 2] * go[cnt[2 * i + 1]] + sum_a[2 * i + 1] * sum_b[2 * i + 2]) % mod;
    sum_a[i] = (sum_a[2 * i + 1] + sum_a[2 * i + 2] * go[cnt[2 * i + 1]]) % mod;
    sum_b[i] = (sum_b[2 * i + 2] + sum_b[2 * i + 1] * go[cnt[2 * i + 2]]) % mod;
}

void build(int i, int l, int r) {
    if (r - l == 1) {
        cnt[i] = ok[l];
        if (cnt[i]) sum_a[i] = used[l], sum_b[i] = used[l];
        return;
    }
    int m = (r + l) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m, r);
    merge(i);
}

void update(int i, int l, int r, int lq, int f) {
    if (r - l == 1) {
        ok[l] += f;
        cnt[i] = ok[l], sum_a[i] = 0, sum_b[i] = 0, ans[i] = 0;
        if (cnt[i]) sum_a[i] = used[l], sum_b[i] = used[l];
        return;
    }
    int m = (r + l) / 2;
    if (lq < m) update(2 * i + 1, l, m, lq, f);
    else update(2 * i + 2, m, r, lq, f);
    merge(i);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, pos, x;
    cin >> n;
    go[0] = 1;
    for (int i = 1; i <= n; ++i) go[i] = go[i - 1] * 2 % mod;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        used[i] = p[i];
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> pos >> x;
        ask[i] = {pos, x};
        used[i + n] = x;
    }
    sort(used + 1, used + n + q + 1);
    for (int i = 1; i <= n + q; ++i) {
        if (used[i] != used[i - 1]) ptr[used[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        ok[ptr[p[i]]] = 1;
        ptr[p[i]]++;
        p[i] = ptr[p[i]] - 1;
    }
    build(0, 1, 2 * maxn);
    cout << ans[0] * st(go[n], mod - 2) % mod << '\n';
    for (int i = 1; i <= q; ++i) {
        pos = ask[i].first, x = ask[i].second;
        update(0, 1, 2 * maxn, p[pos], -1);
        p[pos] = ptr[x];
        ptr[x]++;
        update(0, 1, 2 * maxn, p[pos], 1);
        cout << ans[0] * st(go[n], mod - 2) % mod << '\n';
    }
    return 0;
}