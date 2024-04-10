#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const ll INF = 1e18;

int n;
ll b;
vector<int> c, d;
vector<vector<int>> g;
vector<vector<ll>> dp0, dp1;

void init(int n) {
    c.resize(n);
    d.resize(n);
    g.resize(n);
    dp0.resize(n);
    dp1.resize(n);
}

vector<ll> prod(vector<ll> &a, vector<ll> &b) {
    int n = sz(a);
    int m = sz(b);
    vector<ll> ans(n + m - 1, INF);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i + j] = min(ans[i + j], a[i] + b[j]);
        }
    }
    return ans;
}

void dfs(int v) {
    vector<ll> tmp0 = {0};
    vector<ll> tmp1 = {0};
    for (int u : g[v]) {
        dfs(u);
        tmp0 = prod(tmp0, dp0[u]);
        tmp1 = prod(tmp1, dp1[u]);
    }

    dp0[v].resize(sz(tmp0) + 1);
    dp1[v].resize(sz(tmp0) + 1);

    for (int i = 0; i < sz(dp0[v]); ++i) {
        dp0[v][i] = INF;
        if (i < sz(tmp0)) {
            dp0[v][i] = min(dp0[v][i], tmp0[i]);
            dp1[v][i] = min(dp0[v][i], tmp0[i]);
        }
        if (i > 0) {
            dp0[v][i] = min(dp0[v][i], c[v] + tmp0[i - 1]);
            dp1[v][i] = min(dp0[v][i], d[v] + tmp1[i - 1]);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;
    init(n);

    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> d[i];
        d[i] = c[i] - d[i];
        if (i > 0) {
            int u;
            cin >> u;
            --u;
            g[u].push_back(i);
        }
    }

    dfs(0);
    int k = 0;
    for (; k <= n && dp1[0][k] <= b; ++k);

    // for (int j = 0; j < n; ++j) {
    //     cout << j << endl;
    //     for (int i = 0; i < sz(dp1[j]); ++i)
    //         cout << dp1[j][i] << " ";
    //     cout << endl << endl;
    // }
        
    --k;
    cout << k << endl;
}