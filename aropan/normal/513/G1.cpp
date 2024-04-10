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

const int MAXN = 103;
int n, m;
int p[MAXN];
ld a, b;

void rec(int m)
{
    if (m == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (p[i] > p[j]) {
                    a += 1;
                }
            }
        }
        b += 1;
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            reverse(p + i, p + j + 1);
            rec(m - 1);
            reverse(p + i, p + j + 1);
        }
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    #endif

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    a = b = 0;
    rec(m);
    cout.precision(10);
    cout << a / b << endl;

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}