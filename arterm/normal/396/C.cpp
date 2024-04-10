#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define M 600200
#define mod 1000000007ll

int n, depth[M], tin[M], tout[M], tim = 0, f[2][M];
vector<int> g[M];
bool used[M];

inline void add(int &x, int y) {
    x += y;
    while (x < 0)
        x += mod;
    while (x >= mod)
        x -= mod;
}

void add(int t, int at, int c) {
    for (int i = at; i < tim; i |= (i + 1)) {
        add(f[t][i], c);
    }
}

int getSum(int t, int r) {
    int ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
        add(ans, f[t][i]);
    }
    return ans;
}

int getSum(int t, int l, int r) {
    return getSum(t, r) - getSum(t, l - 1);
}

void read() {
    scanf("%d", &n);
    for (int i = 2, x; i <= n; ++i) {
        scanf("%d", &x);
        g[x].push_back(i);
    }
}

void dfs(int v, int deep) {
    depth[v] = deep;
    used[v] = true;
    tin[v] = tim++;
    for (int & to : g[v]) {
        dfs(to, deep + 1);
    }
    tout[v] = tim++;
}

void upd(int v, int x, int y) {
    x = (x + 1ll * depth[v] * y) % mod;
    add(0, tin[v], x);
    add(0, tout[v], -x);
    add(1, tin[v], y);
    add(1, tout[v], -y);
}

void kill() {
    int q, type, v, x, k;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d%d", &v, &x, &k);
            upd(v, x, k);
        }

        if (type == 2) {
            scanf("%d", &v);
            int x = getSum(0, tin[v]);
            int y = getSum(1, tin[v]);
            int ans = (x - 1ll * depth[v] * y) % mod;
            if (ans < 0)
                ans += mod;
            printf("%d\n", ans);
        }
    }
}


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    read();
    dfs(1, 1);
    kill();

    return 0;
}