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

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n;
    while (cin >> n) {
        vector < int > v;
        for (int i = 0; i < n; ++i) {
            string c;
            cin >> c;
            int x = 0;
            switch (c[0]) {
                case 'R': x |= 1 << 5; break;
                case 'G': x |= 1 << 6; break;
                case 'B': x |= 1 << 7; break;
                case 'W': x |= 1 << 8; break;
                case 'Y': x |= 1 << 9; break;
            }
            x |= 1 << (c[1] - '1');
            v.push_back(x);
            //cout << x << endl;
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        int ans = 10;
        for (int i = 0; i < (1 << 10); ++i) {
            int res = 0;
            for (int j = 0; j < 10; ++j) {
                res += (i & (1 << j)) != 0;
            }
            if (res >= ans) {
                continue;
            }
            int f[1024];
            memset(f, 0, sizeof(f));
            for (size_t j = 0; j < v.size(); ++j) {
                int x = i & v[j];
                if (f[x]) {
                    res = -1;
                    break;
                }
                f[x] = true;
            }
            if (res != -1) {
                ans = res;
            }
        }
        cout << ans << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}