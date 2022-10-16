#include <iostream>
#include <algorithm>
#include <vector>

#define NMAX 200015
using namespace std;

vector <int> graph[NMAX];

int sz[NMAX];
int h[NMAX];

int dp_max[NMAX];
int dp_min[NMAX];

void dfs (int node) {
    if (graph[node].empty()) {
        dp_min[node] = dp_max[node] = sz[node] = 1;

        return ;
    }

    for (auto it: graph[node]) {
        h[it] = h[node] ^ 1;
        dfs(it);

        sz[node] += sz[it];
    }

    //cout << "dfs(" << node << ")" << endl;

    if (!h[node]) {
        //cout << "face maxim " << endl;

        for (auto it: graph[node])
            dp_max[node] = max(dp_max[node], sz[node] - dp_max[it] + 1);
        for (auto it: graph[node])
            dp_min[node] += dp_min[it];

        //cout << "vine " << dp_max[node] << ' ' << dp_min[node] << endl;
    }
    else {
        //cout << "face minim " << endl;

        for (auto it: graph[node])
            dp_max[node] += (sz[it] - dp_max[it] + 1);

        dp_min[node] = NMAX;
        for (auto it: graph[node])
            dp_min[node] = min(dp_min[node], dp_min[it]);

        //cout << "vine " << dp_max[node] << ' ' << dp_min[node] << endl;
    }
}

int main()
{
    int n = 0;
    cin >> n;

    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;

        graph[a].push_back(b);
    }

    dfs(1);

    cout << dp_max[1] << ' ' << dp_min[1] << '\n';
    return 0;
}