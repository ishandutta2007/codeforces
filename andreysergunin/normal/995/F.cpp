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
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int MAXN = 3100;
const int P = 1e9 + 7;

vector<int> g[MAXN];

// adfadf

int par[MAXN];
int p[MAXN][2 * MAXN];
int q[MAXN][2 * MAXN];
int w[MAXN];


void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mul(int &a, int b) {
    ll c = (ll)a * b;
    c %= P;
    a = c;
}

int binPow(int a, int b) {
    if (b == 0) {
        return 1;
    }

    int x = binPow(a, b / 2);
    mul(x, x);

    if (b & 1) {
        mul(x, a);
    }
    return x;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 


    int n, d;
    cin >> n >> d;

    int m = 2 * n;

    for (int i = 1; i < n; ++i) {
        // par[i] = rand() % i + 1;
        cin >> par[i];
        --par[i];
        g[par[i]].push_back(i);
    }

    for (int v = n - 1; v >= 0; --v) {
        w[v] = 1;
        for (int u : g[v]) {
            w[v] += w[u];
        }

        if (w[v] == 1) {
            for (int i = 1; i <= m; ++i) {
                p[v][i] = 1;
                q[v][i] = i;
            }
            continue;
        } 

        for (int i = 1; i <= m; ++i) {
            p[v][i] = 1;
            for (int u : g[v]) {
                mul(p[v][i], q[u][i]);
            }
            q[v][i] = q[v][i - 1];
            add(q[v][i], p[v][i]);
        }
    }

    if (d <= m) {
        cout << q[0][d] << endl;
        return 0;
    }

    vector<int> rev(m + 1);

    for (int i = 1; i <= m; ++i) {
        rev[i] = binPow(i, P - 2);
    }

    int res = 0;

    for (int i = 1; i <= m; ++i) {
        int cur = 1;

        for (int j = 1; j <= m; ++j) {
            if (i == j) {
                continue;
            }

            mul(cur, d - j);
            mul(cur, rev[abs(i - j)]);
            if (i < j) {
                cur = P - cur;
            }
        }

        mul(cur, q[0][i]);

        add(res, cur);
    }

    cout << res << endl;

    
    return 0;
}