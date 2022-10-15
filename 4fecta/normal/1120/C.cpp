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

const int MN = 5005;

int n, a, b, lcs[MN][MN], dp[MN];
string s;

int main() {
    boost();

    cin >> n >> a >> b;
    cin >> s; s = "$" + s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i] == s[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + a;
        for (int j = 1; j < i; j++) {
            int len = min(lcs[i][j], i - j); //always take max len since dp vals monotonic
            dp[i] = min(dp[i], dp[i - len] + b);
        }
    }
    printf("%d\n", dp[n]);

    return 0;
}