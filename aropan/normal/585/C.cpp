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

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    ll a, b;
    while (cin >> a >> b) {
        if (gcd(a, b) != 1) {
            cout << "Impossible" << endl;
            continue;
        }
        char c = a > b? 'A' : 'B';
        if (a > b) {
            swap(a, b);
        }
        while (a != 1) {
            cout << b / a << c;
            ll x = a;
            a = b % a;
            b = x;
            c = 1 - (c - 'A') + 'A';
        }
        cout << b - 1 << c << endl;
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}