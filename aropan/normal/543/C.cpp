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

#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__)
#define INT64 "%I64d"
#define UNS64 "%I64u"
#else
#define INT64 "%lld"
#define UNS64 "%llu"
#endif

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int f[1 << 20];
int g[1 << 20];

inline void upd_min(int &x, int m)
{
    if (m < x) {
        x = m;
    }
}

inline void upd_max(int &x, int m)
{
    if (m > x) {
        x = m;
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    #endif
    int n, m;
    cin >> n >> m;
    vector <string> a(n);
    vector < vector <int> > c(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
        }
    }
    const int INF = 0x7f7f7f7f;
    memset(f, INF, sizeof(f));
    f[0] = 0;
    for (int j = 0; j < m; ++j) {
        for (char v = 'a'; v <= 'z'; ++v) {
            int _k = 0;
            int _c = 0;
            int _m = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i][j] == v) {
                    _k |= 1 << i;
                    _c += c[i][j];
                    upd_max(_m, c[i][j]);
                }
            }
            if (!_k) {
                continue;
            }
            for (int k = 0; k < (1 << n); ++k) {
                if (f[k] != INF) {
                    upd_min(f[k | _k], f[k] + _c - _m);
                }
            }
        }
    }
    vector <int> C(n);
    for (int i = 0; i < n; ++i) {
        C[i] = *min_element(c[i].begin(), c[i].end());
    }
    int answer = INF;
    for (int k = 0; k < (1 << n); ++k) {
        if (f[k] == INF) {
            continue;
        }
        int res = f[k];
        for (int i = 0; i < n; ++i) {
            if ((1 << i) & k) {
                continue;
            }
            res += C[i];
        }
        answer = min(answer, res);
    }
    cout << answer << endl;

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}