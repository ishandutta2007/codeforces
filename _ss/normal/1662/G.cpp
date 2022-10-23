#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, cnt[N], sz[N], last = -1;
vector<int> adj[N];
bitset<N> dp;

void dfsSz(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfsSz(v, u);
        sz[u] += sz[v];
    }
}

int findCentroid(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (2 * sz[v] >= n) {
            last = u;
            return findCentroid(v, u);
        }
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfsSz(1, -1);

    int centroid = findCentroid(1, -1);
    long long ans = 0;

    for (int trial = 0; trial < 2; ++trial) {
        dfsSz(centroid, -1);
        long long extra = accumulate(sz + 1, sz + 1 + n, 0ll);

        for (int v : adj[centroid]) {
            ++cnt[sz[v]];
        }

        dp.reset();
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 0) {
                continue;
            }

            int cur = 1;
            while (cur <= cnt[i]) {
                dp |= (dp << (cur * i));
                cnt[i] -= cur;
                cur = cur * 2;
            }
            if (cnt[i]) {
                dp |= (dp << (cnt[i] * i));
                cnt[i] = 0;
            }
        }

        long long res = 0;
        for (int i = 1; i <= n; ++i) {
            if (dp[i]) {
                res = max(res, 1ll * i * (n - 1 - i));
            }
        }
        ans = max(ans, res + extra);

        if (last == -1) {
            break;
        } else {
            centroid = last;
        }
    }

    cout << ans << '\n';

    return 0;
}