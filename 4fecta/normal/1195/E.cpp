#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 3005;

int n, m, x, y, a[MN][MN], mn[MN][MN], ans, g[MN * MN], X, Y, Z;

int32_t main() {
    boost();

    cin >> n >> m >> x >> y >> g[0] >> X >> Y >> Z;
    for (int i = 1; i < MN * MN; i++) g[i] = (g[i - 1] * X + Y) % Z;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = g[(i - 1) * m + j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        deque<int> deq1;
        for (int j = 1; j <= m; j++) {
            while (deq1.size() && a[i][deq1.back()] > a[i][j]) deq1.pop_back();
            deq1.push_back(j);
            while (deq1.front() <= j - y) deq1.pop_front();
            mn[i][j] = a[i][deq1.front()];
        }
    }
    for (int j = y; j <= m; j++) {
        deque<int> deq1;
        for (int i = 1; i <= n; i++) {
            while (deq1.size() && mn[deq1.back()][j] > mn[i][j]) deq1.pop_back();
            deq1.push_back(i);
            while (deq1.front() <= i - x) deq1.pop_front();
            if (i >= x) ans += mn[deq1.front()][j];
        }
    }
    printf("%lld\n", ans);

    return 0;
}