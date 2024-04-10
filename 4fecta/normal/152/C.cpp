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

int n, m, MOD = 1e9 + 7;
char a[105][105];
set<char> s[105];

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            s[i].insert(a[j][i]);
        }
        ans *= s[i].size();
        ans %= MOD;
    }
    printf("%lld\n", ans);

    return 0;
}