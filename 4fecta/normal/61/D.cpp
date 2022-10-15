#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n, u, v, w, dist[MN];
vector<pii> a[MN];

void dijk(int st) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    memset(dist, 0x3f, sizeof(dist));
    dist[st] = 0;
    pq.push({0, st});
    while (pq.size()) {
        pii cur = pq.top(); pq.pop();
        if (cur.f > dist[cur.s]) continue;
        for (pii nxt : a[cur.s]) {
            if (dist[nxt.f] > dist[cur.s] + nxt.s) {
                dist[nxt.f] = dist[cur.s] + nxt.s;
                pq.push({dist[nxt.f], nxt.f});
            }
        }
    }
}

int32_t main() {
    boost();

    int ans = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
        ans += w;
    }
    int st, mx = 0;
    dijk(1);
    for (int i = 1; i <= n; i++) {
        if (dist[i] > mx) {
            mx = dist[i];
            st = i;
        }
    }
    printf("%lld\n", ans * 2 - mx);

    return 0;
}