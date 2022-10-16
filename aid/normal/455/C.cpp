#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dsu {
    int p, r, d, d0;
};

const int MAXN = 300 * 1000 + 5;
Dsu dsu[MAXN];
char used[MAXN];
vector<int> g[MAXN];

int get(int x) {
    return x == dsu[x].p? x : dsu[x].p = get(dsu[x].p);
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(x == y)
        return;
    if(dsu[y].r > dsu[x].r)
        swap(x, y);
    dsu[y].p = x;
    dsu[x].r += dsu[y].r;
    dsu[x].d = max(max(dsu[x].d, dsu[y].d), dsu[x].d0 + dsu[y].d0 + 1);
    if(dsu[x].d0 == dsu[y].d0)
        dsu[x].d0++;
    else
        dsu[x].d0 = max(dsu[x].d0, dsu[y].d0);
}

void dfs(int v, int p, int dep, vector< pair<int, int> > &a) {
    a.push_back(make_pair(v, dep));
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p)
            dfs(g[v][i], v, dep + 1, a);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++) {
        dsu[i].p = i;
        dsu[i].r = 1;
    }
    for(int i = 0; i < n; i++)
        if(!used[i]) {
            vector< pair<int, int> > a;
            dfs(i, -1, 0, a);
            int v = 0;
            for(size_t j = 1; j < a.size(); j++)
                if(a[j].second > a[v].second)
                    v = j;
            v = a[v].first;
            a.clear();
            dfs(v, -1, 0, a);
            int u = 0;
            for(size_t j = 1; j < a.size(); j++)
                if(a[j].second > a[u].second)
                    u = j;
            int len = a[u].second;
            u = a[u].first;
            vector< pair<int, int> > b;
            dfs(u, -1, 0, b);
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            int w = 0;
            used[a[0].first] = true;
            for(size_t j = 1; j < a.size(); j++) {
                if(max(a[j].second, b[j].second) < max(a[w].second, b[w].second))
                    w = j;
                unite(a[j].first, a[j - 1].first);
                used[a[j].first] = true;
            }
            int x = get(i);
            dsu[x].d = len;
            dsu[x].d0 = max(a[w].second, b[w].second);
        }
    for(int i = 0; i < q; i++) {
        int qq;
        cin >> qq;
        if(qq == 1) {
            int x;
            cin >> x;
            x--;
            x = get(x);
            cout << dsu[x].d << '\n';
        }
        else {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            unite(x, y);
        }
    }
    return 0;
}