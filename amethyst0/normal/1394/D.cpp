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
typedef double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10;
vector <int> ed[maxn];
int t[maxn], h[maxn];
ll dp[maxn][2];

void go(int v, int p) {
    vector <pair <ll, int> > g;

    int in = 0;
    int out = 0;
    ll sc = 0;

    for (int u : ed[v]) {
        if (u == p) {
            continue;
        }

        go(u, v);
        if (h[u] > h[v]) {
            out++;
            sc += dp[u][0];
        }
        else if (h[u] < h[v]) {
            in++;
            sc += dp[u][1];
        }
        else {
            out++;
            g.push_back(mp(-dp[u][0] + dp[u][1], u));
            sc += dp[u][0];
        }
    }

    sort(all(g));

    for (int it = 0; it < 2; it++) {
        if (p != -1)
            if (it == 0) {
                in++;
            }
            else {
                out++;
            }

        ll ans = (ll)1e18;

        ll cur = sc;

        for (int i = 0; i <= (int)g.size(); i++) {
            ans = min(ans, cur + max(in + i, out - i) * (ll)t[v]);
            if (i != (int)g.size())
                cur += g[i].first;
        }

        dp[v][it] = ans;

        if (p != -1)
            if (it == 0) {
                in--;
            }
            else {
                out--;
            }
    }
}

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;

        scanf("%d %d", &x, &y);
        x--;
        y--;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    go(0, -1);
    cout << dp[0][0] << '\n';
}