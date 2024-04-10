#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5, logg = 18;
int a[maxn], st[maxn];
int dp[logg][maxn];

inline int get_mx(int l, int r) {
    int need = st[r - l + 1];
    return max(dp[need][l], dp[need][r - (1 << need) + 1]);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, xs, ys, xf, yf, k;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        dp[0][i] = a[i];
    }
    for (int j = 1; j < logg; j++) {
        for (int i = 1; i + (1 << j) - 1 <= m; i++) {
            dp[j][i] = max(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
        }
    }
    int nxt = 2;
    for (int i = 2; i <= m; i++) {
        st[i] = st[i - 1];
        if (i == nxt) nxt *= 2, st[i]++;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> xs >> ys >> xf >> yf >> k;
        if (abs(yf - ys) % k == 0 && xs + (n - xs) / k * k > get_mx(min(ys, yf), max(ys, yf)) && abs(xs - xf) % k == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}