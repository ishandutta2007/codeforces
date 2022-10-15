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
        vector<pair<int, int>> a;
        int x, y;
        x = y = 0;
        for (int i = 0; i < n; ++i) {
            y = 0;
            x = 3 * i;
            a.push_back({x, y});
            a.push_back({x - 1, y});
            a.push_back({x + 1, y});
            a.push_back({x, y - 1});
            a.push_back({x, y + 1});
            if (i == 0) {
                a.push_back({x - 2, y - 0});
                a.push_back({x - 2, y - 1});
                a.push_back({x - 2, y - 2});
                a.push_back({x - 1, y - 2});
                a.push_back({x - 0, y - 2});
            } else {
                int z = y + ((i & 1)? 2 : -2);
                a.push_back({x - 3, z});
                a.push_back({x - 2, z});
                a.push_back({x - 1, z});
                a.push_back({x - 0, z});
            }
        }
        if (n & 1) {
            a.push_back({x + 2, y + 0});
            a.push_back({x + 2, y + 1});
            a.push_back({x + 2, y + 2});
            a.push_back({x + 1, y + 2});
            a.push_back({x + 0, y + 2});
        } else {
            a.push_back({x + 2, y - 0});
            a.push_back({x + 2, y - 1});
            a.push_back({x + 2, y - 2});
            a.push_back({x + 1, y - 2});
            a.push_back({x + 0, y - 2});
        }

#ifdef LOCAL
        set<pair<int, int>> st(all(a));
        for (int y = -3; y <= 3; ++y) {
            for (int x = -3; x <= 3 * n; ++x) {
                cout << (st.count({x, y})? '*' : '.');
            }
            cout << "\n";
        }
#endif

        cout << a.size() << "\n";
        for (auto& [x, y] : a) {
            cout << x << " " << y << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}