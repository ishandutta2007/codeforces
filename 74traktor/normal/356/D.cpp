#include<bits/stdc++.h>

using namespace std;

int const maxn = 70005;
pair < int, int > a[maxn];
bitset < maxn > dp[2];
int start[maxn];
int ok[maxn], go[maxn], cnt[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s, nxt = 0;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
        cnt[i] = a[i].first;
    }
    sort(a + 1, a + n + 1);
    if (a[n].first > s) {
        cout << -1 << '\n';
        exit(0);
    }
    s -= a[n].first;
    dp[0][0] = 1;
    bitset < maxn > cur;
    for (int i = 1; i < n; ++i) {
        nxt = (nxt^1);
        dp[nxt] = (dp[(1^nxt)]|(dp[(1^nxt)] << a[i].first));
        cur = (dp[nxt]^dp[(1^nxt)]);
        for (int j = cur._Find_first(); j < (int)cur.size(); j = cur._Find_next(j)) start[j] = i;
        //for (int j = 0; j <= 10; ++j) cout << dp[nxt][j];
        //cout << '\n';
    }
    if (dp[nxt][s] == 0) {
        cout << -1 << '\n';
        return 0;
    }
    ok[n] = 1;
    int i = start[s], j = s;
    while (j > 0) {
        ok[i] = 1;
        j -= a[i].first;
        i = start[j];
    }
    for (int i = n; i >= 1; --i) {
        if (ok[i]) continue;
        go[a[i + 1].second] = a[i].second;
    }
    for (int i = 1; i <= n; ++i) {
        int out = cnt[i] - cnt[go[i]];
        cout << out << " ";
        if (go[i] == 0) cout << 0 << '\n';
        else cout << 1 << " " << go[i] << '\n';
    }
    return 0;
}