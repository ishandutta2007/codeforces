#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5, maxc = 4e6 + 5;
int a[maxn], b[maxn];
int pref[maxn];
int cur = 1;
int nxt[maxc][2], dp[maxc];

void add(int x, int y) {
    int node = 0;
    for (int j = 29; j >= 0; --j) {
        dp[node] = max(dp[node], y);
        int b = 0;
        if ((x&(1 << j)) > 0) b = 1;
        if (nxt[node][b] == 0) nxt[node][b] = cur++;
        node = nxt[node][b];
    }
    dp[node] = max(dp[node], y);
}

int get(int mask, int y) {
    int node = 0, pos = 29;
    while (y--) {
        int b = (mask&(1 << pos));
        b = min(b, 1);
        if (nxt[node][b] == 0) return -1;
        node = nxt[node][b];
        pos--;
    }
    return dp[node];
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans;
    cin >> n;
    ans = n + 1;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n >= 100) {
        cout << 1;
        exit(0);
    }
    for (int i = 1; i <= n; ++i) {
        int A = 0;
        for (int j = i; j <= n; ++j) {
            A = (A^a[j]);
            int B = 0;
            for (int z = j + 1; z <= n; ++z) {
                B = (B^a[z]);
                if (A > B) {
                    ans = min(ans, z - i - 1);
                }
            }
        }
    }
    if (ans == n + 1) cout << -1;
    else cout << ans;
    return 0;
}