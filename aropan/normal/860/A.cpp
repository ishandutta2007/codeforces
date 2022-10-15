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

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

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
    set <char> a;
    a.insert('a');
    a.insert('u');
    a.insert('i');
    a.insert('e');
    a.insert('o');
    string s;
    while (cin >> s) {
        char l = 0;
        int k = 0;
        int p = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (a.find(s[i]) != a.end()) {
                k = 0;
                l = 0;
                continue;
            }
            if (l != s[i] && k >= 2) {
                cout << s.substr(p, i - p) << " ";
                p = i;
                l = 0;
                k = 0;
            }
            if (l == 0) {
                l = s[i];
            } else if (l != s[i]) {
                l = -1;
            }
            ++k;
        }
        cout << s.substr(p, s.size() - p) << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}