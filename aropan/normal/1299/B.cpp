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

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#define idbg(x) #x " = " << x
#include "pretty_print.h"
#else
#define dbg(x)
#define idbg(x) ""
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }


vector<pair<int, int>> norm(const vector<pair<int, int>>& a) {
    int n = a.size();
    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < a[m]) {
            m = i;
        }
    }
    vector<pair<int ,int>> ret;
    for (int i = 0; i < n; ++i) {
        ret.push_back(a[(i + m) % n]);
    }
    for (int i = n - 1; i >= 0; --i) {
        ret[i].first -= ret[0].first;
        ret[i].second -= ret[0].second;
    }
    return ret;
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
        vector<pair<int, int>> a(n);
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
            b[i] = {-a[i].first, -a[i].second};
        }
        cout << (norm(a) == norm(b)? "YES" : "NO") << endl;
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}