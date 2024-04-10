#include <bits/stdc++.h>

using namespace std;

int tree[26][400005];

void update(int t, int i, int l, int r, int lq, int x) {
    if (r - l == 1) tree[t][i] += x;
    else {
        int m = (r + l) / 2;
        if (lq < m) update(t, 2 * i + 1, l, m, lq, x);
        else update(t, 2 * i + 2, m, r, lq, x);
        tree[t][i] = tree[t][2 * i + 1] + tree[t][2 * i + 2];
    }
}

int gett(int t, int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return 0;
    if (lq <= l && r <= rq) return tree[t][i];
    int m = (r + l) / 2;
    return gett(t, 2 * i + 1, l, m, lq, rq) + gett(t, 2 * i + 2, m, r, lq, rq);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        update(s[i] - 'a', 0, 0, n, i, 1);
    }
    int q, t, l, r;
    char c;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> l >> c;
            --l;
            update(s[l] - 'a', 0, 0, n, l, -1);
            s[l] = c;
            update(s[l] - 'a', 0, 0, n, l, 1);
        }
        else {
            cin >> l >> r;
            int ans = 0;
            for (int j = 0; j < 26; ++j) if (gett(j, 0, 0, n, l - 1, r) != 0) ans++;
            cout << ans << '\n';
        }
    }
    return 0;
}