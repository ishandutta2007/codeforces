#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;
const int P = 1000000007;

const int V = 100100;

int f[V], s[V];
vector<int> g[V];
set<int> cop;

int fd(int x) {
    if (x != f[x]) f[x] = fd(f[x]);
    return f[x];
}

void U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px == py) return;
    f[py] = px;
    s[px] += s[py];
    cop.erase(py);
}

int del[V], dn, n, m;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        cop.clear();
        for (int i = 1; i <= n; ++i) f[i] = i, s[i] = 1, g[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u < v) swap(u, v);
            g[u].push_back(v);
        }
        cop.clear();
        for (int u = 1; u <= n; ++u) {
            map<int, int> mp;
            for (auto v : cop) {
                mp[v] = 0;
            }
            for (int i = 0; i < g[u].size(); ++i) {
                int v = fd(g[u][i]);
                mp[v]++;
            }
            dn = 0;
            for (auto v : cop) {
                if (mp[v] != s[v]) del[dn++] = v;
            }
            cop.insert(u);
            for (int i = 0; i < dn; ++i) U(del[i], u);
        }
        printf("%d\n", cop.size() - 1);
    }
    return 0;
}

/*
6 11
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6

3 0

*/