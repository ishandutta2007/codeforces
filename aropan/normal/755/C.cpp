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
#include <iomanip>
#include <numeric>

using namespace std;

#define snd second
#define fst first

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int MAXN = 1e+5 + 7;

int nxt[MAXN];

int mfind(int x) {
    nxt[x] = nxt[x] == x? x : mfind(nxt[x]);
    return nxt[x];
}

bool munion(int a, int b) {
    a = mfind(a);
    b = mfind(b);
    if (a == b) {
        return false;
    }
    if (rand() & 1) {
        swap(a, b);
    }
    nxt[a] = b;
    return true;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
#endif
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            nxt[i] = i;
        }
        int answer = n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (munion(i, x - 1)) {
                answer -= 1;
            }
        }
        cout << answer << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}