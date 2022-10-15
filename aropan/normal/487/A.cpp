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

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int hy, ay, dy, hm, am, dm, ch, ca, cd;
    while (cin >> hy >> ay >> dy >> hm >> am >> dm >> ch >> ca >> cd) {
        int ans = (int)2e+9 + 7;
        for (int i = max(dm + 1, ay); i <= max(ay, hm + dm); ++i) {
            for (int j = dy; j <= max(dy, am); ++j) {
                int k = hy - max(0, am - j) * ((hm - 1) / (i - dm) + 1);
                int res = (i - ay) * ca + (j - dy) * cd + max(0, -k + 1) * ch;
                ans = min(ans, res);
            }
        }
        cout << ans << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}