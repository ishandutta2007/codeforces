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

typedef pair <ld, ld> segm;

#define L first
#define R second

segm g(ld a, ld l, ld r)
{
    l *= a;
    r *= a;
    if (l > r) {
        swap(l, r);
    }
    return segm(l, r);
}

vector <segm> f(ld a, ld b, ld c)
{
    vector <segm> v;
    v.push_back(g(a - c, b - c, b + c));
    v.push_back(g(a + c, b - c, b + c));
    v.push_back(g(b - c, a - c, a + c));
    v.push_back(g(b + c, a - c, a + c));
    return v;
}

bool check(vector <segm> &a, vector <segm> &b)
{
    for (auto& i : a) {
        for (auto& j : b) {
            if (min(i.R, j.R) - max(i.L, j.L) > 0) {
                return true;
            }
        }
    }
    return false;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    #endif
    ld a[4];
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
    }

    ld INF= 1e+10;
    ld l = 0, r = INF;
    for (int i = 0; i < 10000; ++i) {
        ld c = (l + r) / 2;
        vector <segm> fs = f(a[0], a[3], c);
        vector <segm> sc = f(a[1], a[2], c);
        if (check(fs, sc)) {
            r = c;
        } else {
            l = c;
        }
    }
    cout.precision(10);
    cout << fixed << r << endl;

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}