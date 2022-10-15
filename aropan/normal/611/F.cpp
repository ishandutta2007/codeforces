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

    int n;
    ll h, w;
    string s;
    while (cin >> n >> h >> w >> s) {
        int answer = 0;
        int k;
        int l, r, t, b, x, y;

        x = y = 0;
        l = r = b = t = 0;
        k = 0;
        for (int i = 0; i < n && w && h; ++i) {
            addmod(k, 1);
            if ((y == l && s[i] == 'L') || (y == r && s[i] == 'R')) {
                addmod(answer, k * h % MOD);
                w -= 1;
            }
            if ((x == b && s[i] == 'D') || (x == t && s[i] == 'U')) {
                addmod(answer, k * w % MOD);
                h -= 1;
            }
            switch (s[i]) {
                case 'L': --y; break;
                case 'R': ++y; break;
                case 'D': --x; break;
                case 'U': ++x; break;
            }
            l = min(l, y);
            r = max(r, y);
            b = min(b, x);
            t = max(t, x);
        }
        if (x == 0 && y == 0 && w && h) {
            cout << -1 << endl;
            continue;
        }
        vector < pair <int, int> > v;
        for (int i = 0; i < n && w && h; ++i) {
            addmod(k, 1);
            if ((y == l && s[i] == 'L') || (y == r && s[i] == 'R')) {
                addmod(answer, k * h % MOD);
                w -= 1;
                v.push_back(make_pair(i, 0));
            }
            if ((x == b && s[i] == 'D') || (x == t && s[i] == 'U')) {
                addmod(answer, k * w % MOD);
                h -= 1;
                v.push_back(make_pair(i, 1));
            }
            switch (s[i]) {
                case 'L': --y; break;
                case 'R': ++y; break;
                case 'D': --x; break;
                case 'U': ++x; break;
            }
            l = min(l, y);
            r = max(r, y);
            b = min(b, x);
            t = max(t, x);
        }
        while (w && h) {
            for (size_t i = 0; i < v.size() && w && h; ++i) {
                if (v[i].second == 0) {
                    addmod(answer, (k + v[i].first + 1) * h % MOD);
                    w -= 1;
                } else {
                    addmod(answer, (k + v[i].first + 1) * w % MOD);
                    h -= 1;
                }
            }
            addmod(k, n);
        }
        cout << answer << "\n";
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}