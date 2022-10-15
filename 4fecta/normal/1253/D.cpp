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

int n, m, u, v, ans = 0, mn = 0;
bool vis[MN];
vector<int> a[MN];
vector<pii> lens;

int main() {
    boost();

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        mn = max(mn, max(u, v));
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= mn; i++) {
        if (vis[i]) continue;
        queue<int> q;
        int lo = INT_MAX, hi = INT_MIN;
        q.push(i);
        while (q.size()) {
            int cur = q.front();
            q.pop();
            lo = min(lo, cur);
            hi = max(hi, cur);
            for (int nxt : a[cur]) {
                if (vis[nxt]) continue;
                vis[nxt] = true;
                q.push(nxt);
            }
        }
        lens.push_back({lo, hi});
    }

    sort(lens.begin(), lens.end());
    int hi = 0;
    for (pii p : lens) {
        if (p.f < hi) {
            ans++;
        }
        hi = max(hi, p.s);
    }

    printf("%d\n", ans);

    return 0;
}