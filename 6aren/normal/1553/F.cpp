#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 350005;

int bit_cnt[N];
long long bit_sum[N];

void update(int k, int val) {
    for (int i = k; i < N; i += (i & (-i))) {
        bit_cnt[i]++;
        bit_sum[i] += val;
    }
}

long long get_cnt(int k) {
    long long res = 0;
    for (int i = k; i > 0; i -= (i & (-i))) {
        res += bit_cnt[i];
    }
    return res;
}

long long get_sum(int k) {
    long long res = 0;
    for (int i = k; i > 0; i -= (i & (-i))) {
        res += bit_sum[i];
    }
    return res;
}

long long get_cnt(int l, int r) {
    if (l > r) return 0;
    if (r >= N) r = N - 1;
    return get_cnt(r) - get_cnt(l - 1);
}

long long get_sum(int l, int r) {
    if (l > r) return 0;
    if (r >= N) r = N - 1;
    return get_sum(r) - get_sum(l - 1);
}

int it[4 * N], lazy[4 * N];

void down(int k, int l, int r) {
    int val = lazy[k];
    if (val == 0) return;
    int mid = (l + r) / 2;
    it[2 * k] += val * (mid - l + 1);
    it[2 * k + 1] += val * (r - mid);
    lazy[2 * k] += val;
    lazy[2 * k + 1] += val;
    lazy[k] = 0;
    return;
}

void update_it(int k, int l, int r, int u, int v, int val) {
    if (u > v) return;
    if (v >= N) v = N - 1;
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        it[k] += (r - l + 1) * val;
        lazy[k] += val;
        return;
    }
    down(k, l, r);
    int mid = (l + r) / 2;
    update_it(2 * k, l, mid, u, v, val);
    update_it(2 * k + 1, mid + 1, r, u, v, val);
    it[k] = it[2 * k] + it[2 * k + 1];
}

int get_it(int k, int l, int r, int u, int v) {
    if (u > v) return 0;
    if (v >= N) v = N - 1;
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) {
        return it[k];
    }
    down(k, l, r);
    int mid = (l + r) / 2;
    return get_it(2 * k, l, mid, u, v) + get_it(2 * k + 1, mid + 1, r, u, v);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int x = a[i];
        for (int foo = a[i]; foo < N; foo += a[i]) {
            res[i] += get_sum(foo + 1, foo + x - 1) - get_cnt(foo + 1, foo + x - 1) * foo; 
        }
        res[i] += get_sum(x);
        int foo = get_cnt(x + 1, N - 1);
        res[i] += foo * x;
        update(x, x);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int foo = a[i]; foo < N; foo += a[i]) {
            update_it(1, 1, N - 1, foo + 1, foo + a[i] - 1, 1);
            update_it(1, 1, N - 1, foo + a[i], foo + a[i], -(a[i] - 1));
        }
        int sum = get_it(1, 1, N - 1, 1, a[i]);
        update_it(1, 1, N - 1, a[i], a[i], -sum);
        update_it(1, 1, N - 1, a[i] + 1, a[i] + 1, sum);
    }
    // cout << res[3] << endl;
    for (int i = 0; i < n; i++) {
        res[i] += get_it(1, 1, N - 1, 1, a[i]);
    }
    // cout << res[3] << endl;
    for (int i = 1; i < n; i++) res[i] += res[i - 1];
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    cout << '\n';

    return 0;
}