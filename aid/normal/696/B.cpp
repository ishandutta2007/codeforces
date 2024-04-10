#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int ts[MAXN], ans[MAXN];
vector<int> g[MAXN];

void dfs0(int v) {
    ts[v] = 1;
    for(size_t i = 0; i < g[v].size(); i++) {
        dfs0(g[v][i]);
        ts[v] += ts[g[v][i]];
    }
}

void dfs1(int v) {
    int x = 0;
    for(size_t i = 0; i < g[v].size(); i++)
        x += ts[g[v][i]];
    for(size_t i = 0; i < g[v].size(); i++) {
        ans[g[v][i]] = ans[v] + x - ts[g[v][i]] + 2;
        dfs1(g[v][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    dfs0(0);
    ans[0] = 2;
    dfs1(0);
    for(int i = 0; i < n; i++)
        cout << ans[i] / 2 << '.' << ((ans[i] & 1)? '5' : '0') << ' ';
    cout << '\n';
    return 0;
}