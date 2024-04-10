#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <numeric>
#include <map>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <random>
#include <sstream>
#include <string>
#include <memory>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const int N = 1e3 + 10;
const int M = 11;

vector<int> g[N];
vector<int> lists;
bool used[N];
int res[N];

int dp[M + 1][N];

void dfs(int v, int par = -1) {
    if (g[v].size() == 1) {
        lists.push_back(v);
    }
    for (auto u : g[v]) {
        if (u != par) {
            dfs(u, v);
        }
    }
}

int tim = 0;
int tin[N], tout[N];

void dfs2(int v, int par = -1) {
    tin[v] = tim++;
    for (auto u : g[v]) {
        if (par != u) {
            dfs2(u, v);
        }
    }
    dp[0][v] = par;
    if (par == -1) {
        dp[0][v] = v;
    }
    tout[v] = tim++;
}

bool upper(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v, int u) {
    if (upper(v, u)) return v;
    if (upper(u, v)) return u;
    for (int i = M; i >= 0; --i) {
        if (!upper(dp[i][v], u)) {
            v = dp[i][v];
        }
    }
    return dp[0][v];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }

    dfs(0);

    size_t shift = lists.size() / 2;
    vector<int> res;
    for (size_t i = 0; i < (1u + lists.size()) / 2; ++i) {
        cout << "? " << lists[i] + 1 << " " << lists[i + shift] + 1 << endl;
        int r;
        cin >> r;
        if (r == lists[i] + 1 || r == lists[i + shift] + 1) {
            cout << "! " << r << endl;
            return;
        }
        res.push_back(r - 1);
    }

    auto cands = res;
    sort(cands.begin(), cands.end());
    cands.resize(unique(cands.begin(), cands.end()) - cands.begin());

    for (auto root : cands) {
        tim = 0;
        dfs2(root);

        for (int i = 1; i <= M; ++i) {
            for (int v = 0; v < n; ++v) {
                dp[i][v] = dp[i - 1][dp[i - 1][v]];
            }
        }


        bool ok = true;
        for (size_t i = 0; i < (1u + lists.size()) / 2; ++i) {
            int lca_ = lca(lists[i], lists[i + shift]);
            if (lca_ != res[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
			cout << "! " << root + 1 << endl;
			return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //    freopen("a.in", "r", stdin);
    solve();
}