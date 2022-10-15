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

struct evt {
    int i, j, d;
};

const int MN = 300005;

int n, sum1, sum2, b[MN];
pii a[MN];
stack<pii> s;
vector<evt> ans;

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].f, a[i].s = i, sum1 += a[i].f;
    for (int i = 1; i <= n; i++) cin >> b[i], sum2 += b[i];
    if (sum1 != sum2) return 0 * printf("NO\n");
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        int d = b[i] - a[i].f;
        if (d > 0) s.push({a[i].s, d});
        while (d < 0) {
            if (s.empty()) return 0 * printf("NO\n");
            int dist = min(-d, s.top().s);
            ans.push_back({s.top().f, a[i].s, dist});
            d += dist;
            s.top().s -= dist;
            if (s.top().s == 0) s.pop();
        }
    }
    if (s.size()) return 0 * printf("NO\n");
    cout << "YES\n" << ans.size() << "\n";
    for (evt e : ans) cout << e.i << " " << e.j << " " << e.d << "\n";

    return 0;
}