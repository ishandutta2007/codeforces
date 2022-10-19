#include <bits/stdc++.h>

using namespace std;

#define M 200200
#define A 20

int to[A][M];
int cost[A][M];
int t[4 * M];
int n, p[M], l[M], d[M];

void upd(int v, int l, int r, int pos, int val) {
    if (r - l == 1) {
        t[v] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos < m)
        upd(2 * v, l, m, pos, val);
    else
        upd(2 * v + 1, m, r, pos, val);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get(int v, int l, int r, int le, int re) {
    if (l == le && r == re)
        return t[v];
    int m = (l + r) / 2;
    int ans = 0;
    if (le < m)
        ans = max(ans, get(2 * v, l, m, le, min(re, m)));
    if (m < re) 
        ans = max(ans, get(2 * v + 1, m, r, max(le, m), re));
    return ans;
}

void read() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> l[i];
    }
}

void pre() {
    d[n] = p[n] + l[n];
    to[0][n] = n;
    upd(1, 1, n + 1, n, d[n]);

    for (int i = n - 1; i >= 1; --i) {
        int le = i + 1;
        int re = upper_bound(p + 1, p + n + 1, p[i] + l[i]) - p;
        if (le < re)
            d[i] = max(p[i] + l[i], get(1, 1, n + 1, le, re));
        else
            d[i] = p[i] + l[i];
        upd(1, 1, n + 1, i, d[i]);
        to[0][i] = upper_bound(p + 1, p + n + 1, d[i]) - p;

        if (to[0][i] == n + 1)
            to[0][i] = n;

        cost[0][i] = max(p[to[0][i]] - d[i], 0);
    }


    for (int i = 1; i < A; ++i)
        for (int j = 1; j <= n; ++j) {
            to[i][j] = to[i - 1][to[i - 1][j]];
            cost[i][j] = cost[i - 1][j] + cost[i - 1][to[i - 1][j]];
        }
}

void kill() {
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = A - 1; i >= 0; --i)
            if (d[to[i][l]] < p[r]) {
                ans += cost[i][l];
                //cerr << "ho " << to[i][l] << "\n";
                l = to[i][l];
            }
        if (d[l] < p[r])
            ans += cost[0][l];
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    read();
    pre();
    kill();

    return 0;
}