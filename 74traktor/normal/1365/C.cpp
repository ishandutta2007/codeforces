#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn], b[maxn], pos_a[maxn], pos_b[maxn];
int cnt[2][2 * maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        pos_a[a[i]] = i, pos_b[b[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (pos_a[i] <= pos_b[i]) {
            cnt[0][maxn + pos_b[i] - pos_a[i]]++;
            cnt[0][maxn - (pos_a[i] + n - pos_b[i])]++;
            cnt[1][maxn - (pos_b[i] - pos_a[i])]++;
            cnt[1][maxn + n - pos_b[i] + pos_a[i]]++;
        }
        else {
            swap(pos_a[i], pos_b[i]);
            cnt[1][maxn + pos_b[i] - pos_a[i]]++;
            cnt[1][maxn - (pos_a[i] + n - pos_b[i])]++;
            cnt[0][maxn - (pos_b[i] - pos_a[i])]++;
            cnt[0][maxn + n - pos_b[i] + pos_a[i]]++;
        }
    }
    for (int j = 0; j <= 1; ++j) {
        for (int i = 0; i < 2 * maxn; ++i) ans = max(ans, cnt[j][i]);
    }
    cout << ans << '\n';
    return 0;
}