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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> void chmin(T &x, const T y) { if (x > y) { x = y; } }
template <typename T> void chmax(T &x, const T y) { if (x < y) { x = y; } }

const int MAXN = 500000;

int a[MAXN * 6];

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1 1" << endl;
        return 0;
    }

    int l = n;
    int r = n + n - 1;
    a[l] = a[r] = 1;
    int st = l, fn = r;
    for (int i = 2; i <= n - 2; ++i) {
        int d = n - i;
        int p = 0;
        if (i % 2 == 0) {
            p = l + d / 2;
        } else {
            p = r + d / 2;
        }
        assert(a[p] == 0);
        assert(a[p - d] == 0);
        a[p] = a[p - d] = i;
        st = min(st, p - d);
        fn = max(fn, p);
    }
    for (int i = st, j = 0; j < 2; ++j) {
        while (a[i]) {
            i += 1;
        }
        a[i] = n;
        fn = max(fn, i);
    }
    assert(n < 3 || fn - st + 1 == 2 * (n - 1));
    if (n > 2) {
        a[++fn] = n - 1;
        a[++fn] = n - 1;
    }

    for (int i = st; i <= fn; ++i) {
        if (st < i) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");

    //int res = 0;
    //for (int i = st; i <= fn; ++i) {
        //for (int j = i + 1; j <= fn; ++j) {
            //if (a[i] == a[j]) {
                //res += (n - a[i]) * abs(j - i + a[i] - n);
            //}
        //}
    //}
    //assert(n < 3 || res == 0);
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}