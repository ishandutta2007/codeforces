#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int dp[maxn];
int cnt[maxn];
int go[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (dp[i - 1] || dp[i]) {
            continue;
        }
        if (cnt[i] > 0) dp[i + 1] = 1;
    }
    int t = 0;
    for (int i = 0; i <= n + 1; ++i) {
        t += dp[i];
    }
    cout << t << ' ';
    for (int i = 1; i <= n; ++i) {
        while (cnt[i] > 0) {
            if (go[i - 1] == 0) {
                go[i - 1] = 1;
            }
            else if (go[i] == 0) {
                go[i] = 1;
            }
            else go[i + 1] = 1;
            cnt[i]--;
        }
    }
    int sum = 0;
    for (int i = 0; i <= n + 1; ++i) sum += go[i];
    cout << sum << '\n';
    return 0;
}