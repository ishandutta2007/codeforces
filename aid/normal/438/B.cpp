#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dsu {
    int p, r;
};

const int MAXN = 100 * 1000 + 5;
pair<int, int> a[MAXN];
Dsu dsu[MAXN];
char used[MAXN];
vector<int> g[MAXN];

int get(int v) {
    return dsu[v].p == v? v : dsu[v].p = get(dsu[v].p);
}
int getSize(int v) {
    v = get(v);
    return dsu[v].r;
}

void unite(int v, int u) {
    v = get(v);
    u = get(u);
    if(dsu[v].r < dsu[u].r)
        swap(v, u);
    dsu[u].p = v;
    dsu[v].r += dsu[u].r;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].first *= -1;
        a[i].second = i;
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0; i < n; i++) {
        dsu[i].p = i;
        dsu[i].r = 1;
    }
    sort(a, a + n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int v = a[i].second, w = -a[i].first;
        for(size_t j = 0; j < g[v].size(); j++)
            if(used[g[v][j]] && get(g[v][j]) != get(v)) {
                ans += (long long)w * getSize(g[v][j]) * getSize(v);
                unite(g[v][j], v);
            }
        used[v] = true;
    }
    cout.setf(ios::fixed);
    cout.precision(12);
    cout << (long double)(2 * ans) / ((long long)n * (n - 1)) << '\n';
    return 0;
}