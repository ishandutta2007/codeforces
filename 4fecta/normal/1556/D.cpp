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

const int MN = 10005;

int n, m, u, v, k, ans[MN], ands[MN], ors[MN], dist[MN], par[MN], psa[2 * MN], vis[MN];
vector<int> a[MN];
vector<int> cyc;

int guess(int i, int j, int t) {
    if (t) cout << "or " << i << " " << j << endl;
    else cout << "and " << i << " " << j << endl;
    int ret;
    cin >> ret;
    return ret;
}

void dfs(int cur, int pre, int d) {
    par[cur] = pre;
    dist[cur] = d;
    vis[cur] = 1;
    for (int nxt : a[cur]) {
        if (vis[nxt]) {
            if (cyc.size() || dist[nxt] % 2 != dist[cur] % 2) continue;
            if (dist[nxt] <= dist[cur]) {
                int node = cur;
                cyc.push_back(node);
                while (nxt != node) node = par[node], cyc.push_back(node);
            } else continue;
        } else dfs(nxt, cur, d + 1);
    }
}

int32_t main() {
    boost();

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        a[i].push_back(i + 1);
        a[i + 1].push_back(i);
    }
    if (n & 1) a[1].push_back(n), a[n].push_back(1);
    else a[2].push_back(n), a[n].push_back(2);
    memset(dist, 0x3f, sizeof(dist));
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        cyc.clear();
        dfs(i, 0, 1);
        int sz = cyc.size();
        if (sz == 1) ans[cyc[0]] = guess(cyc[0], cyc[0], 1);
        else {
            for (int j = 0; j < sz; j++) ands[j] = ors[j] = 0;
            for (int j = 0; j < sz; j++) {
                ands[j] = guess(cyc[j], cyc[(j + 1) % sz], 0);
                ors[sz - 1] ^= ands[j];
            }
            for (int j = 0; j < sz - 1; j++) {
                ors[j] = guess(cyc[j], cyc[(j + 1) % sz], 1);
                ors[sz - 1] ^= ors[j];
            }
            for (int j = 0; j <= 2 * sz; j++) psa[j] = 0;
            for (int j = 0; j < sz; j++) {
                int k = 2 * j % sz;
                psa[j + 1] = psa[j] + (ands[k] + ors[k]);
            }
            for (int j = 0; j < sz; j++) {
                psa[j + sz + 1] = psa[sz] + psa[j + 1];
            }
            int sum = psa[sz] / 2;
            for (int j = 0; j < sz; j++) {
                int id = j * (sz + 1) / 2 % sz + sz;
                assert(id >= (sz - 1) / 2);
                ans[cyc[j]] = sum - (psa[id] - psa[id - (sz - 1) / 2]);
            }
        }
        queue<int> q;
        for (int p : cyc) q.push(p);
        while (q.size()) {
            int cur = q.front(); q.pop();
            for (int nxt : a[cur]) {
                if (ans[nxt] != -1) continue;
                ans[nxt] = guess(cur, nxt, 0) ^ guess(cur, nxt, 1) ^ ans[cur];
                q.push(nxt);
            }
        }
    }
    sort(ans + 1, ans + n + 1);
    cout << "finish " << ans[k] << endl;

    return 0;
}