#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

const int maxn = 1e3 + 5;

ld f[maxn][maxn], nf[maxn][maxn];

int main() {
    //srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<int> a;
    a.pb(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            f[i][j] = a[i] < a[j];
        }
    }

    auto norm = [](ld &x) {
        if (x < 1e-100) {
            x = 0.0;
        }
    };

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }

        for (int j = 1; j <= m; j++) {
            nf[i][u] = nf[i][v] = 0.0;
            nf[u][i] = nf[v][i] = 0.0;
        }

        for (int j = 1; j < u; j++) {
            nf[j][u] = (f[j][u] + f[j][v]) / 2.0;
            norm(nf[j][u]);
            nf[j][v] = (f[j][v] + f[j][u]) / 2.0;
            norm(nf[j][v]);
        }

        for (int j = u + 1; j < v; j++) {
            nf[u][j] = (f[u][j] + 1.0 - f[j][v]) / 2.0;
            norm(nf[u][j]);
            nf[j][v] = (f[j][v] + 1.0 - f[u][j]) / 2.0;
            norm(nf[j][v]);
        }

        for (int j = v + 1; j <= n; j++) {
            nf[u][j] = (f[u][j] + f[v][j]) / 2.0;
            norm(nf[u][j]);

            nf[v][j] = (f[v][j] + f[u][j]) / 2.0;
            norm(nf[v][j]);
        }

        nf[u][v] = 0.5;

        for (int j = 1; j <= n; j++) {
            f[j][u] = nf[j][u];
            f[j][v] = nf[j][v];
            f[u][j] = nf[u][j];
            f[v][j] = nf[v][j];
        }
    }


    ld ans = 0.0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += 1.0 - f[i][j];
        }
    }

    cout.precision(10);
    cout << fixed << ans << endl;

    return 0;
}