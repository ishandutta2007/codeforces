#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
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
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1007;
const int INF = (int)1e+9 + 7;

char a[MAXN][MAXN];


void flipping(int &n, int &m)
{
    int k = max(n, m);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(a[i][j], a[j][i]);
        }
    }
    swap(n, m);
}


bool full(int x1, int y1, int x2, int y2, char c = 'X')
{
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if (a[i][j] != c) {
                return false;
            }
        }
    }
    return true;
}

int solve(int n, int m, bool flip)
{
    if (flip) {
        flipping(n, m);
    }

    bool ok = true;
    for (int iter = 0; iter < 2; ++iter) {
        for (int i = 0; i < n; ++i) {
            int c = 0;
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'X') {
                    if (j && a[i][j - 1] != 'X' && c) {
                        ok = false;
                    }
                    c += 1;
                }
            }
        }
        flipping(n, m);
    }
    if (!ok) {
        return INF;
    }

    int x, y;
    x = y = -1;
    for (int i = 0; i < n && x == -1; ++i) {
        for (int j = 0; j < m && x == -1; ++j) {
            if (a[i][j] == 'X') {
                x = i;
                y = j;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < y; ++j) {
            if (a[i][j] == 'X') {
                return INF;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i][m] = '.';
    }
    for (int i = 0; i < m; ++i) {
        a[n][i] = '.';
    }

    int b = x;
    while (b < n && a[b][y] == 'X') {

        int r = y;
        while (r + 1 < m && a[x][r + 1] == 'X') r += 1;

        int width = r - y + 1;
        int height = b - x + 1;
        //cout << height << " " << width << endl;

        int t = x, l = y;
        bool ok = true;
        do {
            //cout << "  " << a[t + height][l] << " " << a[t][l + width] << endl;
            if (a[t + height][l] == 'X' && a[t][l + width] == 'X') {
                ok = false;
                break;
            }
            if (a[t + height][l] == 'X') {
                ok &= full(t + height, l, t + height, l + width - 1);
                t += 1;
            } else
            if (a[t][l + width] == 'X') {
                ok &= full(t, l + width, t + height - 1, l + width);
                l += 1;
            } else {
                //cout << "break" << endl;
                break;
            }
            //cout << "  " << t << " " << l << endl;
        } while (ok);
        if (ok) {
            ok &= full(t + height, l, t + height, l + width - 1, '.');
            ok &= full(t, l + width, t + height - 1, l + width, '.');
        }

        if (ok) {
            if (t == x && l == y) {
                return min(width, height);
            } else {
                return width * height;
            }
        }
        b += 1;
    }

    if (flip) {
        flipping(n, m);
    }
    return INF;
}

int main(int /* argc */, char** /* argv */)
{
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n, m;
    while (cin >> n >> m) {
        memset(a, '.', sizeof(a));
        for (int i = 0; i < n; ++i) {
            scanf("%s", a[i]);
        }
        int ans = min(solve(n, m, true), solve(n, m, false));
        cout << (ans == INF? -1 : ans) << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}