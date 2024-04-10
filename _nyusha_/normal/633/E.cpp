#include<bits/stdc++.h>

using namespace std;

#define double long double
int const maxn = 1e6 + 5, logg = 20;
int v[maxn], c[maxn], good[maxn], need[maxn];
int max_v[maxn][logg], min_c[maxn][logg];

inline int get_max(int l, int r) {
    int t = need[r - l + 1];
    return max(max_v[l][t], max_v[r - (1 << t) + 1][t]);
}

inline int get_min(int l, int r) {
    int t = need[r - l + 1];
    return min(min_c[l][t], min_c[r - (1 << t) + 1][t]);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] *= 100;
    }
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i) {
        max_v[i][0] = v[i];
        min_c[i][0] = c[i];
    }
    for (int j = 1; j < logg; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            max_v[i][j] = max(max_v[i][j - 1], max_v[i + (1 << (j - 1))][j - 1]);
            min_c[i][j] = min(min_c[i][j - 1], min_c[i + (1 << (j - 1))][j - 1]);
        }
    }
    int nxt = 2;
    for (int i = 2; i <= n; ++i) {
        need[i] = need[i - 1];
        if (i == nxt) need[i]++, nxt *= 2;
    }
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n + 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (get_max(i, m) <= get_min(i, m)) l = m;
            else r = m;
        }
        for (int pos = l; pos <= min(n, l + 1); ++pos) {
            good[i] = max(good[i], min(get_max(i, pos), get_min(i, pos)));
        }
    }
    sort(good + 1, good + n + 1);
    double ans = 0.0, t = k / (double)n;
    for (int i = 1; i <= n - k + 1; ++i) {
        // good[i] * C(n - i, k - 1) / C(n, k)
        // (n - i)! /
        ans += (double)good[i] * t;
        if (i != n - k + 1) t = t * (double)(n - i - k + 1) / (double)(n - i);
    }
    cout << fixed << setprecision(18) << ans << '\n';
    return 0;
}