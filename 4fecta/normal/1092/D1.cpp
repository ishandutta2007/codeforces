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

const int MN = 200005;

int n, a[MN], dp[MN][2][2];

bool solve() {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            dp[i][0][1] |= dp[i - 1][0][0];
            dp[i][0][0] |= dp[i - 1][0][1];
        } else {
            dp[i][0][0] |= dp[i - 1][0][0];
            dp[i][1][0] |= dp[i - 1][0][1];
        }
    }
    return dp[n][0];
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] %= 2;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (v.size() && v.back() == a[i]) v.pop_back();
        else v.push_back(a[i]);
    }
    int ans = v.size() <= 1;
    if (ans) printf("YES\n");
    else printf("NO\n");

    return 0;
}