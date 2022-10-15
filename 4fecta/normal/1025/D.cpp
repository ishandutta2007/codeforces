#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 705;

int n, a[MN], dp[MN][MN][2], ok[MN][MN];

int rec(int l, int r, int s) {
    if (l > r) return 1;
    if (dp[l][r][s] != -1) return dp[l][r][s];
    dp[l][r][s] = 0;
    int num = s ? r + 1 : l - 1;
    for (int i = l; i <= r; i++) {
        if (!ok[i][num]) continue;
        dp[l][r][s] |= rec(l, i - 1, 1) & rec(i + 1, r, 0);
    }
    return dp[l][r][s];
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (__gcd(a[i], a[j]) > 1) ok[i][j] = 1;
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++) ans |= rec(1, i - 1, 1) & rec(i + 1, n, 0);
    if (ans) printf("Yes\n");
    else printf("No\n");

    return 0;
}