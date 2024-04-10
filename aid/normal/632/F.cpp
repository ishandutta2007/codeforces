#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2505;
int a[MAXN][MAXN], p[MAXN], ts[MAXN];
pair<int, pair<int, int> > e[MAXN * MAXN];
vector<int> comp[MAXN];

int get(int x) {
    return p[x] == x? x : p[x] = get(p[x]);
}

void unite(int x, int y) {
    if(ts[x] < ts[y])
        swap(x, y);
    p[y] = x;
    ts[x] += ts[y];
    for(size_t i = 0; i < comp[y].size(); i++)
        comp[x].push_back(comp[y][i]);
    comp[y].clear();
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    bool bad = false;
    for(int i = 0; i < n; i++)
        if(a[i][i] > 0)
            bad = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] != a[j][i])
                bad = true;
    if(bad) {
        printf("NOT MAGIC\n");
        return 0;
    }
    int m = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            e[m++] = make_pair(a[i][j], make_pair(i, j));
    sort(e, e + m);
    for(int i = 0; i < n; i++) {
        p[i] = i;
        ts[i] = 1;
        comp[i].push_back(i);
    }
    for(int i = 0; i < m; i++) {
        int w = e[i].first, v = e[i].second.first, u = e[i].second.second;
        v = get(v);
        u = get(u);
        if(v == u)
            continue;
        for(size_t ii = 0; ii < comp[v].size(); ii++)
            for(size_t jj = 0; jj < comp[u].size(); jj++)
                if(a[comp[v][ii]][comp[u][jj]] != w) {
                    printf("NOT MAGIC\n");
                    return 0;
                }
        unite(v, u);
    }
    printf("MAGIC\n");
    return 0;
}