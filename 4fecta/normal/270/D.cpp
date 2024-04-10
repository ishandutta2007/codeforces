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

int n, a[MN], dp[MN], len = 1;
double wtf;

int main() {
    boost();

    cin >> n >> wtf;
    for (int i = 1; i <= n; i++) cin >> a[i] >> wtf, dp[i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        len = max(len, dp[i]);
    }
    printf("%d\n", n - len);

    return 0;
}