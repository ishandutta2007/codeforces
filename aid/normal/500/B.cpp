#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 305;
int p[MAXN], ans[MAXN], g[MAXN][MAXN], n;
char used[MAXN];
vector<int> pos[MAXN], val[MAXN];

void dfs(int v, int m) {
    used[v] = true;
    pos[m].push_back(v);
    val[m].push_back(p[v]);
    for(int i = 0; i < n; i++)
        if(!used[i] && g[v][i])
            dfs(i, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    int m = 0;
    for(int i = 0; i < n; i++)
        if(!used[i]) {
            dfs(i, m);
            m++;
        }
    for(int i = 0; i < m; i++) {
        sort(val[i].begin(), val[i].end());
        sort(pos[i].begin(), pos[i].end());
        for(size_t j = 0; j < pos[i].size(); j++)
            ans[pos[i][j]] = val[i][j];
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}