#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int w[MAXN], ts[MAXN], n;
long long c[MAXN];
vector< pair<int, int> > g[MAXN];

void dfs(int v, int p) {
    ts[v] = 1;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i].first, id = g[v][i].second;
        if(id == p)
            continue;
        dfs(u, id);
        ts[v] += ts[u];
    }
    if(p != -1)
        c[p] = (long long)ts[v] * (n - ts[v]) * (n - ts[v] - 1) +
            (long long)(n - ts[v]) * ts[v] * (ts[v] - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(10);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u >> w[i];
        v--;
        u--;
        g[v].push_back(make_pair(u, i));
        g[u].push_back(make_pair(v, i));
    }
    dfs(0, -1);
    long double ans = 0;
    long long k = ((long long)n * (n - 1) * (n - 2)) / 6;
    for(int i = 0; i < n - 1; i++)
        ans += (long double)(c[i] * w[i]) / k;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int r, nw;
        cin >> r >> nw;
        r--;
        ans -= (long double)((w[r] - nw) * c[r]) / k;
        w[r] = nw;
        cout << ans << '\n';
    }
    return 0;
}