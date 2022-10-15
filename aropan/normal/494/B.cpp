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
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 2 * 1e+5 + 7;
const int MOD = 1e+9 + 7;

int f[MAXN];
int g[MAXN];
int h[MAXN];
int k[MAXN];

void add(int &x, const int d)
{
    x += d;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    string s, t;
    while (cin >> s >> t) {
        string c = t + "@" + s;
        int n = c.size();
        memset(k, 0, sizeof(k));

        k[0] = 0;
        for (int i = 1; i < n; ++i) {
            int x = k[i - 1];
            while (x && c[i] != c[x]) x = k[x - 1];
            x += c[i] == c[x];
            k[i] = x;
        }
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        memset(h, 0, sizeof(h));
        n = s.size();
        int p = 0;
        int m = t.size();
        for (int i = 1; i <= n; ++i) {
            add(g[i], g[i - 1]);
            add(h[i], h[i - 1]);
            if (k[m + i] == m) {
                p = i - m + 1;
            }
            if (p) {
                add(f[i], h[p - 1]);
                add(f[i], p);
            }

            add(g[i], f[i]);
            add(h[i], g[i]);
        }
        cout << g[n] << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}