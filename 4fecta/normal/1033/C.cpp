#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

pii a[MN];
int n, dp[MN];

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].f;
        a[i].s = i;
    }

    sort(a + 1, a + n + 1, greater<pii>());
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        int idx = a[i].s;
        for (int j = idx; j > 0; j -= a[i].f) {
            if (dp[j] == 0) dp[idx] = 1;
        }
        for (int j = idx; j <= n; j += a[i].f) {
            if (dp[j] == 0) dp[idx] = 1;
        }
        if (dp[idx] == -1) dp[idx] = 0;
    }

    for (int i = 1; i <= n; i++) if (dp[i]) printf("A"); else printf("B");

    return 0;
}