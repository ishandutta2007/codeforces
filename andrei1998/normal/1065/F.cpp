#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1E6 + 5;

vector <int> tree[NMAX];
vector <int> graph[NMAX];
vector <int> graph_inv[NMAX];

int N, K;
int stk[NMAX];
int sz;

void dfs_find(int node) {
    stk[++sz] = node;
    const int ft = stk[max(1, sz - K)];
    if (tree[node].empty()) {
        graph[node].push_back(ft);
        graph_inv[ft].push_back(node);
    }
    for (auto it: tree[node])
        dfs_find(it);
    --sz;
}

bool vis[NMAX];
void dfs1(int node) {
    vis[node] = true;
    for (auto it: graph[node])
        if (!vis[it])
            dfs1(it);
    stk[sz--] = node;
}

int which_comp[NMAX];
int s[NMAX];

void dfs2(int node, int comp) {
    vis[node] = true;
    if (tree[node].empty())
        ++s[comp];
    which_comp[node] = comp;
    for (auto it: graph_inv[node])
        if (!vis[it])
            dfs2(it, comp);
}

int dp[NMAX];
vector <int> graph_fin[NMAX];

void dfs_calc(int node) {
    vis[node] = true;
    for (auto it: graph_fin[node]) {
        if (!vis[it]) {
            dfs_calc(it);
        }
        dp[node] = max(dp[node], dp[it]);
    }
    dp[node] += s[node];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 2; i <= N; ++i) {
        int a, b = i;
        cin >> a;
        tree[a].push_back(b);
        graph[a].push_back(b);
        graph_inv[b].push_back(a);
    }

    dfs_find(1);

    sz = N;
    for (int i = 1; i <= N; ++i)
        if (!vis[i])
            dfs1(i);

    for (int i = 1; i <= N; ++i)
        vis[i] = false;

    int comps = 0;
    for (int i = 1; i <= N; ++i) {
        const int node = stk[i];
        if (!vis[node])
            dfs2(node, ++comps);
    }

    for (int i = 1; i <= N; ++i)
        vis[i] = false;

    for (int i = 1; i <= N; ++i) {
        const int a = which_comp[i];
        for (auto it: graph[i]) {
            const int b = which_comp[it];
            if (a != b) {
                graph_fin[a].push_back(b);
            }
        }
    }

    dfs_calc(which_comp[1]);
    cout << dp[which_comp[1]] << endl;
    return 0;
}