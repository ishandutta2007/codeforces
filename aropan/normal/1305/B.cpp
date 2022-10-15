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
    string s;
    while (cin >> s) {
        vector<vector<int>> ans;
        for (;;) {
            int n = s.size();
            vector<int> a;
            vector<int> b;
            for (int i = 0, j = n - 1; i < j; ++i, --j) {
                while (i < j && s[i] != '(') {
                    ++i;
                }
                while (i < j && s[j] != ')') {
                    --j;
                }
                if (i == j) {
                    break;
                }
                a.push_back(i);
                b.push_back(j);
            }
            reverse(all(b));
            for (auto x : b) {
                a.push_back(x);
            }
            if (a.size() == 0) {
                break;
            }
            ans.push_back(a);
            reverse(all(a));
            for (auto x : a) {
                s.erase(s.begin() + x);
            }
        }
        cout << ans.size() << "\n";
        for (auto a : ans) {
            cout << a.size() << "\n";
            for (int i = 0; i < (int)a.size(); ++i) {
                if (i) {
                    cout << " ";
                }
                cout << a[i] + 1;
            }
            cout << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}