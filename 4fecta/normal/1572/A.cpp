#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, u, v, k, deg[MN], dist[MN];
vector<int> a[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            dist[i] = -1;
            cin >> k;
            for (int j = 1; j <= k; j++) cin >> u, a[u].push_back(i), deg[i]++;
        }
        priority_queue<int, vector<int>, greater<>> q;
        for (int i = 1; i <= n; i++) if (!deg[i]) q.push(i), dist[i] = 1;
        while (q.size()) {
            int cur = q.top(); q.pop();
            for (int nxt : a[cur]) {
                dist[nxt] = max(dist[nxt], dist[cur] + (nxt < cur));
                if (!--deg[nxt]) q.push(nxt);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i]) ans = 0x3f3f3f3f;
            ans = max(ans, dist[i]);
            a[i].clear();
            deg[i] = 0;
        }
        printf("%lld\n", ans >= 0x3f3f3f3f ? -1 : ans);
    }

    return 0;
}