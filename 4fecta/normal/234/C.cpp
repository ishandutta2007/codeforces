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

const int MN = 100005;

int n, pn[MN], pp[MN], u, ans = MN;

int main() {
    boost();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        if (!u) pn[i]++, pp[i]++;
        else if (u > 0) pp[i]++;
        else pn[i]++;
        pn[i] += pn[i - 1];
        pp[i] += pp[i - 1];
    }
    for (int i = 1; i < n; i++) {
        ans = min(ans, pp[i] + pn[n] - pn[i]);
    }
    printf("%d\n", ans);

    return 0;
}