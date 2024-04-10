#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int n;
ll X, Y;
vector < vector <int> > e;
vector < vector <int> > f;

void dfs(int x, int p)
{
    vector <int> v;

    int r = 0;
    for (auto& y : e[x]) {
        if (y == p) {
            continue;
        }
        dfs(y, x);
        r += f[y][0];
        v.push_back(f[y][1] - f[y][0]);
    }
    sort(v.begin(), v.end());

    f[x][0] = r + 1;
    f[x][1] = r;
    if (v.size()) {
        f[x][1] = min(f[x][1], r + v[0]);
        if (v.size() > 1) {
            f[x][0] = min(f[x][0], r + v[0] + v[1] + 1);
        }
    }
    f[x][0] = min(f[x][0], f[x][1] + 1);
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n) {
        cin >> X >> Y;

        f.resize(n);
        e.resize(n);
        for (int i = 0; i < n; ++i) {
            e[i].clear();
            f[i].resize(2);
        }

        vector <int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            swap(p[i], p[rand() % (i + 1)]);
        }

        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            u = p[u - 1];
            v = p[v - 1];
            //u = i;
            //v = rand() % i;

            e[u].push_back(v);
            e[v].push_back(u);
        }
        if (X == Y) {
            cout << (n - 1) * X << endl;
            continue;
        }
        if (X > Y) {
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                if ((int)e[i].size() == n - 1) {
                    ok = false;
                    break;
                }
            }
            cout << (n - 1) * Y + (ok? 0 : X - Y) << endl;
            continue;
        }
        int root = 0;
        dfs(root, -1);
        ll ans = (n - 1) * X + (Y - X) * (f[root][0] - 1);
        cout << ans << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}