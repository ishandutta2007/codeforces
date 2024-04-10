#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int it[4 * N], lazy[4 * N];

void down(int k, int l, int r) {
    int val = lazy[k];
    if (val == 0) return;
    val -= 1;
    int mid = (l + r) / 2;
    it[2 * k] = (mid - l + 1) * val;
    it[2 * k + 1] = (r - mid) * val;
    lazy[2 * k] = val + 1;
    lazy[2 * k + 1] = val + 1;
    lazy[k] = 0;
}

void update(int k, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        it[k] = (r - l + 1) * val;
        lazy[k] = val + 1;
        return;
    }
    int mid = (l + r) / 2;
    down(k, l, r);
    update(2 * k, l, mid, u, v, val);
    update(2 * k + 1, mid + 1, r, u, v, val);
    it[k] = it[2 * k] + it[2 * k + 1];
}

int get(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return it[k];
    int mid = (l + r) / 2;
    down(k, l, r);
    return get(2 * k, l, mid, u, v) + get(2 * k + 1, mid + 1, r, u, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, q;
        cin >> n >> q;
        string s, f;
        cin >> f >> s;
        for (int i = 1; i <= n; i++) {
            update(1, 1, n, i, i, s[i - 1] - '0');
        }

        bool ok = 1;
        vector<pair<int, int>> que(q);
        for (auto &e : que) cin >> e.first >> e.second;
        reverse(que.begin(), que.end());
        for (auto e : que) {
            int l, r;
            l = e.first;
            r = e.second;
            int sum = get(1, 1, n, l, r);
            // cout << sum << '\n';
            int len = r - l + 1;
            if (sum * 2 == len) ok = 0;
            if (sum <= len / 2) update(1, 1, n, l, r, 0);
            else update(1, 1, n, l, r, 1);
            // for (int i = 1; i <= n; i++) {
            //     cout << get(1 ,1, n, i, i);
            // }
            // cout << '\n';
        }

        // cout << ok << '\n';

        for (int i = 1; i <= n; i++) {
            // cout << get(1 ,1, n, i, i);
            if (get(1, 1, n, i, i) != f[i - 1] - '0') ok = 0;
        }
        // cout << '\n';

        cout << (ok ? "YES\n" : "NO\n");
        for (int i = 1; i <= 4 * n + 5; i++) {
            it[i] = lazy[i] = 0;
        }
    }   

    return 0;
}