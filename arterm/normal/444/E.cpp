#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define M 3030

int n, sum, x[M], bound;
vector<int> g[M], w[M];
bool u[M];

void read() {
    cin >> n;
    for (int i = 1, x, y, z; i < n; ++i) {
        cin >> x >> y >> z;
        g[x].push_back(y);
        g[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        sum += x[i];
    }
}

void dfs(int v, int & vert, int & cap) {
    u[v] = true;
    vert += 1;
    cap += x[v];
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int to = g[v][i];
        int we = w[v][i]; 
        if (!u[to] && we < bound)
            dfs(to, vert, cap);
    }
}

bool pos() {
    fill(u, u + M, false);
    for (int i = 1, vert, cap; i <= n; ++i)
        if (!u[i]) {
            vert = cap = 0;
            dfs(i, vert, cap);
            if (vert > sum - cap)
                return false;
        }
    return true;
}

void bin() {
    int l = 0, r = 10100;
    while (l < r) {
        bound = (l + r) / 2 + 1;
        if (pos()) 
            l = bound;
        else
            r = bound - 1;
    }

    cout << l << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    bin();

    return 0;
}