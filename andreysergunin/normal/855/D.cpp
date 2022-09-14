#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int MAXN = 1e5 + 100;
const int MAXK = 20;

vector<int> g[MAXN];

int used[MAXN];
int tin[MAXN], tout[MAXN];

int p[MAXN];
int tp[MAXN];

int eq[2][MAXK][MAXN];
int up[MAXK][MAXN];

int timer = 0;

void dfs(int v) {
    used[v] = 1;
    tin[v] = ++timer;
    for (int u : g[v]) {
        dfs(u);
    }
    tout[v] = ++timer;
}

int lca(int u, int v) {
    if (up[MAXK - 1][u] != up[MAXK - 1][v]) {
        return -1;
    }
    if (tin[v] <= tin[u] && tout[u] <= tout[v]) {
        return v;
    }

    for (int l = MAXK - 1; l >= 0; --l) {
        int w = up[l][v];
        if (!(tin[w] <= tin[u] && tout[u] <= tout[w])) {
            v = w;
        }
    }

    return p[v];
}


bool ancesstor(int k, int u, int v) {
    if (u == v) {
        return true;
    }
    for (int l = MAXK - 1; l >= 0; --l) {
        if (!eq[k][l][v])
            continue;
        int w = up[l][v];
        if (w == u) {
            return true;
        }
        if (!(tin[w] < tin[u] && tout[u] < tout[w])) {
            v = w;
        }
    }
    return false;
}


int main() {
    //freopen("comb.in", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        p[i] = i;

    for (int i = 0; i < n; ++i) {
        int t, v;
        cin >> v >> t;
        --v;
        if (t == -1)
            continue;
        g[v].push_back(i);
        tp[i] = t;
        p[i] = v;
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
        
    }

    for (int i = 0; i < n; ++i) {
        up[0][i] = p[i];
        eq[0][0][i] = (p[i] == i || tp[i] == 0);
        eq[1][0][i] = (p[i] == i || tp[i] == 1);
    }

    for (int j = 1; j < MAXK; ++j) {
        for (int i = 0; i < n; ++i) {
            up[j][i] = up[j - 1][up[j - 1][i]];
            eq[0][j][i] = eq[0][j - 1][i] && eq[0][j - 1][up[j - 1][i]];
            eq[1][j][i] = eq[1][j - 1][i] && eq[1][j - 1][up[j - 1][i]];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t, u, v;
        cin >> t >> u >> v;
        if (u == v) {
            cout << "NO\n";
            continue;
        }
        --u; --v;
        if (t == 1) {
            if (ancesstor(0, u, v)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            int w = lca(u, v);
            if (w == -1) {
                cout << "NO\n";
                continue;
            }

            if (ancesstor(0, w, u) && ancesstor(1, w, v) && w != v) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}