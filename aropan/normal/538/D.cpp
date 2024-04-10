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

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    char ans[2 * n][2 * n];

    int a[n][n];
    memset(a, 0, sizeof(a));
    for (int dx = -n + 1; dx < n; ++dx) {
        for (int dy = -n + 1; dy < n; ++dy) {
            bool ok =  true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (s[i][j] == 'o') {
                        int x = i + dx;
                        int y = j + dy;
                        ok &= x < 0 || y < 0 || n <= x || n <= y || s[x][y] != '.';
                    }
                }
            }
            ans[dx + n - 1][dy + n - 1] = ok? 'x' : '.';
            if (ok) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (s[i][j] == 'o') {
                            int x = i + dx;
                            int y = j + dy;
                            if (x < 0 || y < 0 || n <= x || n <= y) {
                                continue;
                            }
                            a[x][y] += 1;
                        }
                    }
                }
            }
        }
    }
    ans[n - 1][n - 1] = 'o';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'x' && a[i][j] == 0) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for (int i = 0; i < n + n - 1; ++i) {
        for (int j = 0; j < n + n - 1; ++j) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}