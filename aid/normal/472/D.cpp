#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dsu {
    int p, r;
};

const int MAXN = 2005;
int d[MAXN][MAXN];
Dsu dsu[MAXN];
char used[MAXN];
pair<int, pair<int, int> > e[MAXN * MAXN / 2];
vector< pair<int, int> > g[MAXN];

int get(int x) {
    return dsu[x].p == x? x : dsu[x].p = get(dsu[x].p);
}

bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(x == y)
        return false;
    if(dsu[x].r < dsu[y].r)
        swap(x, y);
    dsu[y].p = x;
    dsu[x].r += dsu[y].r;
    return true;
}

bool dfs(int v, int s, int dist) {
    if(dist != d[s][v])
        return false;
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); i++)
        if(!used[g[v][i].first])
            if(!dfs(g[v][i].first, s, dist + g[v][i].second))
                return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int m = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> d[i][j];
            if(i < j)
                e[m++] = make_pair(d[i][j], make_pair(i, j));
        }
    for(int i = 0; i < n; i++) {
        if(d[i][i] != 0) {
            cout << "NO\n";
            return 0;
        }
        for(int j = 0; j < n; j++) {
            if(d[i][j] != d[j][i]) {
                cout << "NO\n";
                return 0;
            }
            if(i != j && d[i][j] == 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        dsu[i].p = i;
        dsu[i].r = 1;
    }
    sort(e, e + m);
    for(int i = 0; i < m; i++)
        if(unite(e[i].second.first, e[i].second.second)) {
            g[e[i].second.first].push_back(make_pair(e[i].second.second, e[i].first));
            g[e[i].second.second].push_back(make_pair(e[i].second.first, e[i].first));
        }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            used[j] = false;
        if(!dfs(i, i, 0)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}