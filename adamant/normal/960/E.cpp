#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 5e5 + 42, mod = 1e9 + 7;

vector<int> g[maxn];

int n;
int arr[maxn];
int sum[maxn][2];
int sz[maxn][2];
int ans;

void normalize(int &x) {
    x %= mod;
    if(x < 0) {
        x += mod;
    }
}

void dfs(int v = 0, int p = 0) {
    sum[v][0] += arr[v];
    sz[v][0] = 1;
    ans += arr[v];
    normalize(ans);
    for(auto u: g[v]) {
        if(u != p) {
            dfs(u, v);
            ans += 2 * (sum[v][0] * sz[u][1] % mod + sum[v][1] * sz[u][0] % mod);
            
            normalize(ans);
            int t0 = sum[u][1] + arr[v] * sz[u][1];
            int t1 = sum[u][0] - arr[v] * sz[u][0];
            normalize(t0);
            normalize(t1);
            ans += 2 * (sum[u][1] * sz[v][0] % mod + sum[u][0] * sz[v][1] % mod);
            normalize(ans);
            sum[v][0] += t0;
            sum[v][1] += t1;
            sz[v][0] += sz[u][1];
            sz[v][1] += sz[u][0];
            normalize(sum[v][0]);
            normalize(sum[v][1]);
        }
    }
    //cout << v << endl;
}


signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int u[n], v[n];
    for(int i = 0; i < n - 1; i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    dfs();
    cout << ans << endl;
    return 0;
}