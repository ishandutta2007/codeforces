#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long lint;

using namespace std;

const int MAXN = 48;

vector<int> g[MAXN];
vector<int> teams[MAXN];
bool used[MAXN];

void dfs(int v, int tn) {
    used[v] = true;
    teams[tn].push_back(v + 1);
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to, tn);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[--x].push_back(--y);
        g[y].push_back(x);
    }

    int tn = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, tn++);
        }
    }
    vector< vector<int> > byN[4];
    for (int i = 0; i < tn; ++i) {
        if (teams[i].size() > 3) {
            cout << -1;
            return 0;
        }
        byN[teams[i].size()].push_back(teams[i]);
    }
    if (byN[2].size() > byN[1].size() || (byN[1].size() - byN[2].size()) % 3 != 0) {
        cout << -1;
        return 0;
    }
    for (auto t : byN[3]) {
        cout << t[0] << " " << t[1] << " " << t[2] << "\n";
    }
    int t1 = 0;
    for (auto t : byN[2]) {
        cout << t[0] << " " << t[1] << " " << byN[1][t1++][0] << "\n";
    }
    for (; t1 < byN[1].size(); t1 += 3) {
        cout << byN[1][t1][0] << " " << byN[1][t1 + 1][0] << " " << byN[1][t1 + 2][0] << "\n";
    }


    return 0;
}