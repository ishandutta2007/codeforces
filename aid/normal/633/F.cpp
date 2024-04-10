#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN];
vector<int> g[MAXN];
vector<long long> pref0[MAXN], suff0[MAXN], pref1[MAXN], suff1[MAXN];

void dfs0(int v, int p) {
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] == p) {
            g[v].erase(g[v].begin() + i);
            break;
        }
    int k = g[v].size();
    pref0[v].resize(k + 1);
    suff0[v].resize(k + 1);
    pref1[v].resize(k + 1);
    suff1[v].resize(k + 1);
    pref0[v][0] = a[v];
    pref1[v][0] = a[v];
    for(int i = 0; i < k; i++) {
        int u = g[v][i];
        dfs0(u, v);
        pref0[v][i + 1] = max(pref0[v][i], a[v] + pref0[u].back());
        pref1[v][i + 1] = max(pref1[v][i], max(pref0[v][i] + pref0[u].back(),
                                               pref1[u].back()));
    }
    suff0[v][k] = a[v];
    suff1[v][k] = a[v];
    for(int i = k - 1; i >= 0; i--) {
        int u = g[v][i];
        suff0[v][i] = max(suff0[v][i + 1], a[v] + suff0[u][0]);
        suff1[v][i] = max(suff1[v][i + 1], max(suff0[v][i + 1] + suff0[u][0],
                                               suff1[u][0]));
    }
}

long long max2(long long a, long long b, long long c) {
    if(a < b) {
        if(a < c)
            return b + c;
        else
            return a + b;
    }
    else {
        if(b < c)
            return a + c;
        else
            return a + b;
    }
}

long long dfs1(int v, long long dp0Up, long long dp1Up) {
    long long res = pref1[v].back();
    int k = g[v].size();
    for(int i = 0; i < k; i++) {
        int u = g[v][i];
        long long cur = max(max(pref1[v][i], suff1[v][i + 1]),
                            max(dp1Up, max2(pref0[v][i],
                                            suff0[v][i + 1], dp0Up) - a[v]));
        res = max(res, pref1[u].back() + cur);
        long long nxt0 = a[u] + max(dp0Up, max(pref0[v][i], suff0[v][i + 1])),
            nxt1 = max(max(dp1Up, cur), nxt0);
        res = max(res, dfs1(u, nxt0, nxt1));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs0(0, -1);
    cout << dfs1(0, a[0], a[0]) << '\n';
    return 0;
}