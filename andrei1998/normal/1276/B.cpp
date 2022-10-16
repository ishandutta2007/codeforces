#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int NMAX = 500000 + 5;

int N, M, A, B;
vector <int> graph[NMAX];

void dfs(const int node, vector <bool>& vis, int& sz, bool& from_A, bool& from_B) {
    sz += 1;
    vis[node] = true;
    for (const int it : graph[node]) {
        if (!vis[it]) {
            if (it == A) {
                from_A = true;
                continue;
            }
            if (it == B) {
                from_B = true;
                continue;
            }
            dfs(it, vis, sz, from_A, from_B);
        }
    }
}

lint solve() {
    vector <bool> vis(N + 1, false);
    int all_nodes_only_A = 0, all_nodes_only_B = 0;
    for (int i = 1; i <= N; ++i) {
        if (!vis[i] && i != A && i != B) {
            int sz = 0;
            bool from_A = 0, from_B = 0;
            dfs(i, vis, sz, from_A, from_B);
            if (from_A && !from_B) {
                all_nodes_only_A += sz;
            } else if (!from_A && from_B) {
                all_nodes_only_B += sz;
            }
        }
    }
    return 1LL * all_nodes_only_A * all_nodes_only_B;
}

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    int T = 0;
    cin >> T;
    while (T--) {
        cin >> N >> M >> A >> B;
        for (int i = 1; i <= N; ++i) {
            graph[i].clear();
        }
        for (int i = 1; i <= M; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cout << solve() << '\n';
    }
    return 0;
}