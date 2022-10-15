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
    int n, s, k;
    while (cin >> n >> s >> k) {
        int a[n + 1];
        int f[n + 1];
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        multiset<int> values;
        multiset<int> mins;
        const int INF = (int)1e+9 + 7;
        f[0] = 0;
        for (int l = 0, r = 0, i = 1; i <= n; ++i) {
            if (i - k >= r) {
                mins.insert(f[r++]);
            }
            values.insert(a[i]);
            while (l < r && *values.rbegin() - *values.begin() > s) {
                mins.erase(mins.find(f[l]));
                ++l;
                values.erase(values.find(a[l]));
            }
            f[i] = (mins.size() == 0? INF : *mins.begin()) + 1;
        }
        cout << (f[n] >= INF? -1 : f[n]) << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}