#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

const int N = 111111;
const int mod = 1e9 + 7;

vector<int> g[N];
int d[N][2];
int pr[N];
int sf[N];

int c[N];

void go(int v) {
    for (int i : g[v]) {
        go(i);
    }
    if (c[v] == 1) {
        d[v][0] = 0;
        int x = 1;
        for (int i : g[v]) {
            x = 1LL * x * (d[i][0] + d[i][1]) % mod;
        }
        d[v][1] = x;
    } else {
        int x = 1;
        for (int i : g[v]) {
            x = 1LL * x * (d[i][0] + d[i][1]) % mod;
        }
        d[v][0] = x;
        int n = g[v].size();
        for (int i = 0; i < n; i++) {
            pr[i] = (d[g[v][i]][0] + d[g[v][i]][1]) % mod;
            if (i > 0) {
                pr[i] = 1LL * pr[i] * pr[i - 1] % mod;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            sf[i] = (d[g[v][i]][0] + d[g[v][i]][1]) % mod;
            if (i + 1 < n) {
                sf[i] = 1LL * sf[i] * sf[i + 1] % mod;
            }
        }

        x = 0;
        for (int i = 0; i < n; i++) {
            int t = d[g[v][i]][1];
            if (i > 0) {
                t = 1LL * t * pr[i - 1] % mod;
            }
            if (i + 1 < n) {
                t = 1LL * t * sf[i + 1] % mod;
            }
            x = (x + t) % mod;
        }
        d[v][1] = x;
    }
}

int main() {
    scid(n);
    for (int i = 1; i < n; i++) {
        scid(x);
        g[x].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        sci(c[i]);
    }

    go(0);

    cout << d[0][1];

    return 0;
}