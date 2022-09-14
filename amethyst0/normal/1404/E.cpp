#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = 210;
char s[maxn][maxn];

const int maxm = (int)1e5 + 10;

vector <int> ed[maxm];
int g[maxn][maxn], h[maxn][maxn];

bool used[maxm];
int lnk[maxm];

bool dfs(int v) {
    if (used[v]) {
        return false;
    }

    used[v] = true;

    for (int u : ed[v]) {
        if (lnk[u] == -1 || dfs(lnk[u])) {
            lnk[u] = v;
            return true;
        }
    }

    return false;
}

void add(int x, int y) {
    if (x == -1 || y == -1) {
        return;
    }
    ed[x].push_back(y);
}

int main() {
    memset(lnk, -1, sizeof lnk);
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    int psg = 0;
    int psh = 0;

    memset(g, -1, sizeof g);
    memset(h, -1, sizeof h);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && s[i][j] == '#' && s[i + 1][j] == '#') {
                g[i][j] = psg++;
            }

            if (j + 1 < m && s[i][j] == '#' && s[i][j + 1] == '#') {
                h[i][j] = psh++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != 0) {
                add(g[i - 1][j], h[i][j]);
            }

            if (i != 0 && j != 0) {
                add(g[i - 1][j], h[i][j - 1]);
            }

            add(g[i][j], h[i][j]);

            if (j != 0) {
                add(g[i][j], h[i][j - 1]);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < psg; i++) {
        bool ok = false;
        for (int u : ed[i]) {
            if (lnk[u] == -1) {
                lnk[u] = i;
                ok = true;
                break;
            }
        }
        if (ok || dfs(i)) {
            ans++;
            memset(used, 0, sizeof used);
        }
    }

    int tot = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                tot++;
            }
        }
    }

    cout << tot - (psg + psh - ans) << '\n';
}