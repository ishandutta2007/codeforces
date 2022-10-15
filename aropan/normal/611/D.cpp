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

const int MOD = (int)1e+9 + 7;

int n;
string s;
vector < vector <int> > f, g;

void addmod(int &x, int d)
{
    x += d;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    while (cin >> n >> s) {
        g = f = vector < vector <int> > (n + 1, vector <int> (n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i - 1; j >= 0; --j) {
                f[i][j] = s[i] == s[j]? 1 + f[i + 1][j + 1] : 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (s[j] == '0') {
                    g[i][j] = 0;
                } else {
                    if (j == 0) {
                        g[i][j] = 1;
                    } else {
                        int l = i - j + 1;
                        int i_ = j - 1;
                        int j_ = j - l;
                        if (j_ >= 0) {
                            int x = f[j][j_];
                            if (x >= l || s[j_ + x] > s[j + x]) {
                                ++j_;
                            }
                        }
                        g[i][j] = g[i_][max(j_, 0)];
                    }
                }
                addmod(g[i][j], g[i][j + 1]);
            }
        }
        cout << g[n - 1][0] << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}