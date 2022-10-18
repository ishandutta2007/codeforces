#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

const int maxn = 2e5 + 42;

vector<int> g[maxn];

int cnt[maxn][2];
int sum[maxn][2];

void dfs(int v = 0, int p = 0) {
    cnt[v][0] = 1;
    for(auto u: g[v]) {
        if(u != p) {
            dfs(u, v);
            cnt[v][0] += cnt[u][1];
            cnt[v][1] += cnt[u][0];
            sum[v][0] += sum[u][1] + cnt[u][1];
            sum[v][1] += sum[u][0] + cnt[u][0];
        }
    }
}

int tsum[maxn][2];
int tcnt[maxn][2];

int ans = 0;
void dfs_fin(int v = 0, int p = 0) {
    if(v == 0) {
        tsum[v][0] = sum[v][0];
        tsum[v][1] = sum[v][1];
        tcnt[v][0] = cnt[v][0];
        tcnt[v][1] = cnt[v][1];
    }
    if(v != 0) {
        tsum[v][0] = tsum[p][1] + tcnt[p][1] - 2 * cnt[v][0];
        tsum[v][1] = tsum[p][0] + tcnt[p][0] - 2 * cnt[v][1];
        tcnt[v][0] = tcnt[p][1];
        tcnt[v][1] = tcnt[p][0];
    }
    ans += tsum[v][0] / 2 + (tsum[v][1] - tcnt[v][1]) / 2 + tcnt[v][1];
    for(auto u: g[v]) {
        if(u != p) {
            dfs_fin(u, v);
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    dfs();
    dfs_fin();
    cout << ans / 2 << endl;
}