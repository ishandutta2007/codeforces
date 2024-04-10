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

const int MN = 1000005;

int n, x, a[MN], low[MN], up[MN];
vector<int> pos[MN];

int32_t main() {
    boost();

    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    low[0] = 0;
    for (int i = 1; i <= x; i++) {
        if (pos[i].empty()) {low[i] = low[i - 1]; continue;}
        if (pos[i].front() < low[i - 1]) low[i] = 0x3f3f3f3f;
        else low[i] = pos[i].back();
    }
    up[x + 1] = n + 1;
    for (int i = x; i > 0; i--) {
        if (pos[i].empty()) {up[i] = up[i + 1]; continue;}
        if (pos[i].back() > up[i + 1]) up[i] = -0x3f3f3f3f;
        else up[i] = pos[i].front();
    }
    int ans = 0;
    for (int i = 0; i < x; i++) {
        int lo = i + 2, hi = x + 2, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (low[i] < up[mid]) hi = mid;
            else lo = mid + 1;
        }
        ans += x + 2 - lo;
        //printf("%d %d %d %d\n", 1, i, lo, x);
    }
    printf("%lld\n", ans);

    return 0;
}