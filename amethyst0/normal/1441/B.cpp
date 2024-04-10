#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
typedef double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)2e5 + 10, mod = 998244353, maxlog = 20;
vector <int> ed[2][maxn];

int dst[maxlog][maxn];

pii ds[2][maxn];

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        /*if (i % 2 == 0) {
            x = i + 2;
            y = i + 1;
        }
        else {
            x = i + 1;
            y = i + 2;
        }*/
        x--;
        y--;
        ed[0][x].push_back(y);
        ed[1][y].push_back(x);
    }

    queue <pii> q;
    q.push(mp(0, 0));

    memset(dst, -1, sizeof dst);
    dst[0][0] = 0;

    while (!q.empty()) {
        int tp = q.front().first;
        int v = q.front().second;
        q.pop();

        for (int u : ed[tp & 1][v]) {
            if (dst[tp][u] == -1) {
                dst[tp][u] = 1 + dst[tp][v];
                q.push(mp(tp, u));
            }
        }

        if (tp != maxlog - 1) {
            for (int u : ed[1 ^ (tp & 1)][v]) {
                if (dst[tp + 1][u] == -1) {
                    dst[tp + 1][u] = 1 + dst[tp][v];
                    q.push(mp(tp + 1, u));
                }
            }
        }
    }

    int s = 0;

    int ans = (int)1e9;

    for (int i = 0; i < maxlog; i++) {
        if (dst[i][n - 1] != -1) {
            ans = min(ans, s + dst[i][n - 1]);
        }

        s += 1 << i;
    }

    ds[0][0] = mp(0, 0);
    set <pair <pii, pii> > f;
    f.insert(mp(ds[0][0], mp(0, 0)));

    for (int i = 1; i < n; i++) {
        ds[0][i] = ds[1][i] = mp((int)1e9, 0);
    }
    
    ds[1][0] = mp((int)1e9, 0);

    while (!f.empty()) {
        int v = f.begin()->second.second;
        int tp = f.begin()->second.first;
        f.erase(f.begin());

        for (int u : ed[tp][v]) {
            if (ds[tp][u] > mp(ds[tp][v].first, ds[tp][v].second + 1)) {
                f.erase(mp(ds[tp][u], mp(tp, u)));
                ds[tp][u] = mp(ds[tp][v].first, ds[tp][v].second + 1);
                f.insert(mp(ds[tp][u], mp(tp, u)));
            }
        }

        for (int u : ed[tp ^ 1][v]) {
            if (ds[tp ^ 1][u] > mp(ds[tp][v].first + 1, ds[tp][v].second + 1)) {
                f.erase(mp(ds[tp ^ 1][u], mp(tp ^ 1, u)));
                ds[tp ^ 1][u] = mp(ds[tp][v].first + 1, ds[tp][v].second + 1);
                f.insert(mp(ds[tp ^ 1][u], mp(tp ^ 1, u)));
            }
        }
    }

    int st = 1;
    int res = 0;

    int best = 0;

    if (ds[1][n - 1] < ds[0][n - 1]) {
        best = 1;
    }

    for (int i = 0; i < ds[best][n - 1].first; i++) {
        res += st;
        st *= 2;
        st %= mod;
        res %= mod;
    }

    res += ds[best][n - 1].second;
    res %= mod;

    if (st >= maxlog) {
        ans = res;
    }

    cout << ans << '\n';
}