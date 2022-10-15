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

bool move(string *s, int d)
{
    int n = s[0].size();
    bool res = false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i][j] = j + d < n? s[i][j + d] : '.';
            res |= s[i][j] != '.';
        }
    }
    return res;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int t;
    cin >> t;
    for (int T = 0; T < t; ++T) {
        int n, k;
        cin >> n >> k;
        string s[3];
        bool y[3];
        for (int i = 0; i < 3; ++i) {
            cin >> s[i];
            y[i] = s[i][0] == 's';
            s[i][0] = '.';
        }
        bool ok = true;
        for (;;) {
            if (!move(s, 1)) { break; }
            for (int i = 0; i < 3; ++i) { y[i] &= s[i][0] == '.'; }
            ok = y[0] | y[1] | y[2];
            if (!ok) { break; }

            y[0] |= y[1];
            y[2] |= y[1];
            y[1] |= y[0] || y[2];
            for (int i = 0; i < 3; ++i) { y[i] &= s[i][0] == '.'; }
            ok = y[0] | y[1] | y[2];

            if (!ok || !move(s, 2)) { break; }
            for (int i = 0; i < 3; ++i) { y[i] &= s[i][0] == '.'; }
            ok = y[0] | y[1] | y[2];
            if (!ok) { break; }
        }
        cout << (ok? "YES" : "NO") << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}