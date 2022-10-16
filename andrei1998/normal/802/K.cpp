#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

vector<int> graph[MAXN];
pair<int, int> edge[MAXN - 1];
int k;

int dp_anywhere[MAXN], dp_initial[MAXN];

void DFS(int node, int parent) {
    vector<int> sons;
    for (const int& e: graph[node]) {
        const int son = edge[e].first ^ node;
        const int cost = edge[e].second;

        if (son == parent) {
            continue;
        }
        DFS(son, node);

        dp_initial[son] += cost;
        dp_anywhere[son] += cost;
        sons.push_back(son);
    }

    sort(begin(sons), end(sons), [](const int& x, const int& y) {
        return dp_initial[x] > dp_initial[y];
    });

    for (int i = 0; i < k && i < (int)sons.size(); ++i) {
        dp_initial[node] += dp_initial[sons[i]];
    }

    dp_anywhere[node] = dp_initial[node];
    int add = ((int)sons.size() > k) ? dp_initial[sons[k]] : 0;
    for (int i = 0; i < (int)sons.size(); ++i) {
        dp_anywhere[node] = max(dp_anywhere[node], dp_initial[node] - (i < k ? dp_initial[sons[i]] - add : 0) + dp_anywhere[sons[i]]);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n >> k; --k;
    for (int i = 0; i < n - 1; ++i) {
        int x, y, c; cin >> x >> y >> c;
        edge[i].first = x ^ y;
        edge[i].second = c;
        graph[x].push_back(i);
        graph[y].push_back(i);
    }

    DFS(0, -1);
    cout << dp_anywhere[0] << '\n';
}