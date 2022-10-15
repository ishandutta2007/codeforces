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

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n) {
        int x[n + 1], y[n + 1];
        x[0] = y[0] = 0;
        string s;
        cin >> s;
        for (int i = 1; i <= n; ++i) {
            x[i] = x[i - 1];
            y[i] = y[i - 1];
            switch (s[i - 1]) {
                case 'R': x[i] += 1; break;
                case 'L': x[i] -= 1; break;
                case 'U': y[i] += 1; break;
                case 'D': y[i] -= 1; break;
            }
        }

        //set <string> m;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (x[i] == x[j + 1] && y[i] == y[j + 1]) {
                    //string c = s.substr(i, j - i + 1);
                    //cout << c << endl;
                    //m.insert(c);
                    ans += 1;
                }
            }
        }
        cout << ans << endl;
        //cout << m.size() << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}