#include <bits/stdc++.h>

using namespace std;

const int NMAX = 300000 + 5;

int N, M;
int d[NMAX];
vector <pair <int, int> > graph[NMAX];

vector <int> sol;

bool vis[NMAX];
void dfs(int node, int father, int fatherEdge) {
    vis[node] = true;
    for (auto it: graph[node])
        if (!vis[it.first])
            dfs(it.first, node, it.second);

    if (d[node] == 1) {
        sol.push_back(fatherEdge);
        d[node] ++;
        d[node] %= 2;
        d[father] ++;
        d[father] %= 2;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);

    cin >> N >> M;
    vector <int> dontKnow;
    int sum = 0;
    for (int i = 1; i <= N; ++ i) {
        cin >> d[i];
        if (d[i] == -1)
            dontKnow.push_back(i);
        else
            sum += d[i];
    }
    sum %= 2;

    if (dontKnow.empty() && sum == 1) {
        cout << "-1\n";
        return 0;
    }

    if (sum == 1) {
        d[dontKnow.back()] = 1;
        dontKnow.pop_back();
    }
    for (auto it: dontKnow)
        d[it] = 0;

    for (int i = 1; i <= M; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, i});
        graph[b].push_back({a, i});
    }

    dfs(1, 0, 0);

    cout << sol.size() << '\n';
    for (auto it: sol)
        cout << it << '\n';
    return 0;
}