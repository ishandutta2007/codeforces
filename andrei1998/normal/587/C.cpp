#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 100005;

void unite (vector <int> &a, vector <int> b, vector <int> &c, int z) {
    c.clear();
    c.resize(a.size() + b.size());

    merge(a.begin(), a.end(),
          b.begin(), b.end(),
          c.begin());

    if (c.size() > z)
        c.resize(z);
}

int n, m, q;

vector <int> graph[NMAX];
vector <int> people[NMAX];

int father[18][NMAX];
vector <int> dp[18][NMAX];

int h[NMAX];

void dfs (int node) {
    dp[0][node] = people[node];
    if (dp[0][node].size() > 10)
        dp[0][node].resize(10);

    for (int i = 1; i < 18; ++ i) {
        father[i][node] = father[i - 1][father[i - 1][node]];
        unite(dp[i - 1][node], dp[i - 1][father[i - 1][node]], dp[i][node], 10);
    }

    for (auto it: graph[node])
        if (it != father[0][node]) {
            father[0][it] = node;
            h[it] = 1 + h[node];

            dfs(it);
        }
}

inline void query (vector <int> &ans, int a, int b, int z) {
    ans.clear();
    if (h[a] > h[b])
        swap(a, b);

    for (int i = 17; i >= 0; -- i)
        if (h[b] - (1 << i) >= h[a]) {
            unite(dp[i][b], ans, ans, z);
            b = father[i][b];
        }

    if (a == b) {
        unite(dp[0][a], ans, ans, z);
        return ;
    }

    for (int i = 17; i >= 0; -- i)
        if (father[i][a] != father[i][b]) {
            unite(dp[i][a], ans, ans, z);
            unite(dp[i][b], ans, ans, z);

            a = father[i][a];
            b = father[i][b];
        }

    unite(dp[0][a], ans, ans, z);
    unite(dp[0][b], ans, ans, z);
    unite(dp[0][father[0][b]], ans, ans, z);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> n >> m >> q;

    int a, b;
    for (int i = 1; i < n; ++ i) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= m; ++ i) {
        cin >> a;
        people[a].push_back(i);
    }

    dfs(1);

    int z;
    vector <int> aux;

    int i;
    while (q --) {
        cin >> a >> b >> z;
        query(aux, a, b, z);

        cout << aux.size();
        for (i = 0; i < aux.size(); ++ i)
            cout << ' ' << aux[i];
        cout << '\n';
    }

    return 0;
}