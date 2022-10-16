#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 105, MAXV = 10 * 1000 + 5;
int a[MAXN], id[MAXV], p[MAXV], used[MAXV], pr[MAXV], gs;
char c[MAXN][MAXN];
vector<int> g[MAXV];

void fact(int x, int pos) {
    for(int i = 2; i * i <= x; i++)
        while(!(x % i)) {
            id[gs] = pos;
            p[gs] = i;
            gs++;
            x /= i;
        }
    if(x > 1) {
        id[gs] = pos;
        p[gs] = x;
        gs++;
    }
}

bool dfs(int v, int col) {
    used[v] = col;
    for(size_t i = 0; i < g[v].size(); i++)
        if(pr[g[v][i]] == -1) {
            pr[g[v][i]] = v;
            return true;
        }
    for(size_t i = 0; i < g[v].size(); i++)
        if(used[pr[g[v][i]]] != col && dfs(pr[g[v][i]], col)) {
            pr[g[v][i]] = v;
            return true;
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        fact(a[i], i);
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        c[x][y] = true;
        c[y][x] = true;
    }
    for(int i = 0; i < gs; i++)
        if(!(id[i] & 1))
            for(int j = 0; j < gs; j++)
                if((id[j] & 1) && c[id[i]][id[j]] && p[i] == p[j])
                    g[i].push_back(j);
    int ans = 0;
    for(int i = 0; i < gs; i++) {
        used[i] = -1;
        pr[i] = -1;
    }
    for(int i = 0; i < gs; i++)
        if(!(id[i] & 1))
            ans += dfs(i, i);
    cout << ans << '\n';
    return 0;
}