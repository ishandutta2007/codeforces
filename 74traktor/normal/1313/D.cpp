#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int b[maxn];
int dp[2 * maxn][257];
int ok[257];
int inf = 2e9 + 7;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, ans = 0, l, r;
    cin >> n >> m >> k;
    vector < vector < int > > T;
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i&(1 << j)) > 0) ok[i]++;
        }
        ok[i] %= 2;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> l >> r;
        T.push_back({l, 0, i});
        T.push_back({r + 1, -1, i});
    }
    for (int j = 0; j < 2 * maxn; ++j) for (int i = 0; i <= 255; ++i) dp[j][i] = -inf;
    dp[0][0] = 0;
    sort(T.begin(), T.end());
    set < int > free;
    for (int i = 0; i < k; ++i) free.insert(i);
    int ptr = 0, lst = 1, numb = 0;
    while (ptr < (int)T.size()) {
        numb++;
        for (int i = 0; i < 256; ++i) {
            if (ok[i]) dp[numb - 1][i] += (T[ptr][0] - lst);
        }
        int x = T[ptr][0];
        int mask = 255;
        while (ptr < (int)T.size() && T[ptr][0] == x && T[ptr][1] == -1) {
            int j = b[T[ptr][2]];
            mask -= (1 << j);
            free.insert(j);
            ptr++;
        }
        for (int i = 0; i < 256; ++i) {
            dp[numb][(i&mask)] = max(dp[numb][(i&mask)], dp[numb - 1][i]);
        }
        while (ptr < (int)T.size() && T[ptr][0] == x) {
            int j = (*free.begin());
            b[T[ptr][2]] = (*free.begin());
            free.erase(free.begin());
            for (int i = 0; i <= 255; ++i) {
                if ((i&(1 << j)) == 0) {
                    dp[numb][i + (1 << j)] = max(dp[numb][i + (1 << j)], dp[numb][i]);
                }
            }
            ptr++;
        }
        lst = T[ptr - 1][0];
    }
    for (int i = 0; i < 256; ++i) {
        ans = max(ans, dp[numb][i]);
    }
    cout << ans << '\n';
    return 0;
}