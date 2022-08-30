#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 105;

vector <pii> res;
vector <int> edg[N];
int b[N][N][N], adj[N], dis[N][N], f[N];
char c[N];
int T, n, ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs0(int u, int fa) {
    if ((int)res.size() >= n) return;
    for (int i = 1; i <= n; i++) {
        if (i == u || i == fa) continue;
        if (b[fa][i][u]) {
            res.emplace_back(i, u);
            dfs0(i, u);
        }
    }
}

void dfs1(int rt, int u, int fa, int dep) {
    dis[rt][u] = dep;
    for (auto v : edg[u]) {
        if (v == fa) continue;
        dfs1(rt, v, u, dep + 1);
    }
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                scanf("%s", c + 1);
                for (int k = 1; k <= n; k++) b[i][i + j][k] = b[i + j][i][k] = c[k] - '0';
            }
        }
        ans = 0;
        for (int _ = 2; _ <= n; _++) {
            res.clear(); res.emplace_back(1, _);
            dfs0(1, _); dfs0(_, 1);
            if ((int)res.size() != n - 1) continue;
            for (int i = 1; i <= n; i++) edg[i].clear();
            for (int i = 1; i <= n; i++) f[i] = i;
            int ok = 1;
            for (auto i : res) {
                int x = find(i.first), y = find(i.second);
                if (x == y) ok = 0;
                f[x] = y;
                edg[i.first].push_back(i.second);
                edg[i.second].push_back(i.first);
            }
            if (!ok) continue;
            for (int i = 1; i <= n; i++) dfs1(i, i, 0, 0);
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    for (int k = 1; k <= n; k++) {
                        if ((dis[i][k] == dis[j][k]) != b[i][j][k]) {
                            ok = 0;
                        }
                    }
                }
            }
            if (ok) {
                ans = 1;
                break;
            }
        }
        if (ans) {
            printf("Yes\n");
            for (auto i : res) {
                print(i.first, ' ');
                print(i.second, '\n');
            }
        } else {
            printf("No\n");
        }
    }
    return 0;
}