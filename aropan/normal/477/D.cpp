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


const int MAXN = 5003;
const int MOD = (int)1e+9 + 7;
const int INF = (int)1e+9 + 6;

int f[MAXN][MAXN];
string s;
int n;

int c[MAXN][MAXN];
int g[MAXN][MAXN];

void mini(int &x, const int v) {
    if (x > v) {
        x = v;
    }
}


void add(int &x, const int d) {
    x += d;
    if (x >= MOD) {
        x -= MOD;
    }
}


bool check(int i, int j, int l)
{
    if (f[i][j] >= l) {
        return true;
    }
    if (j + f[i][j] >= n) {
        return false;
    }
    return s[i + f[i][j]] < s[j + f[i][j]];
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    while (cin >> s) {
        n = s.size();

        memset(f, 0, sizeof(f));
        memset(c, 0, sizeof(c));
        memset(g, 0, sizeof(g));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = s[i] == s[j]? f[i + 1][j + 1] + 1 : 0;
            }
        }

        c[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            if (i) {
                for (int j = 0; j <= i; ++j) {
                    add(c[j][i], c[j][i - 1]);
                }
            }
            if (i + 1 < n && s[i + 1] == '1') {
                for (int j = 0; j <= i; ++j) {
                    int l = i - j  + 1;
                    if (!check(j, i + 1, l)) {
                        l += 1;
                    }
                    if (i + l < n) {
                        add(c[i + 1][i + l], c[j][i]);
                    }
                }
            }
        }

        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                g[j][i] = INF;
            }
        }

        g[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            if (i) {
                for (int j = 0; j < i; ++j) {
                    mini(g[j][i], g[j][i - 1]);
                }
            }
            if (i + 1 < n && s[i + 1] == '1') {
                for (int j = 0; j <= i; ++j) {
                    if (g[j][i] != INF) {
                        int l = i - j  + 1;
                        if (!check(j, i + 1, l)) {
                            l += 1;
                        }
                        if (i + l < n) {
                            mini(g[i + 1][i + l], g[j][i] + 1);
                        }
                    }
                }
            }
        }
        {
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                add(ans, c[i][n - 1]);
            }
            cout << ans << endl;
        }
        {
            int ans = -1;
            for (int i = n - 1; i >= 0; --i) {
                if (g[i][n - 1] == INF) {
                    continue;
                }
                if (n - i < 25) {
                    int res = 0;
                    for (int j = i; j < n; ++j) {
                        res *= 2;
                        res += s[j] - '0';
                    }
                    res += g[i][n - 1];
                    if (ans == -1 || res < ans) {
                        ans = res;
                    }
                } else {
                    if (ans != -1) {
                        break;
                    }
                    int res = 0;
                    for (int j = i; j < n; ++j) {
                        res *= 2;
                        res += s[j] - '0';
                        res %= MOD;
                    }
                    res += g[i][n - 1];
                    ans = res;
                    break;
                }
            }
            cout << ans % MOD << endl;
        }
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}