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

struct TState {
    int r, g, b;
    TState(int r = 0, int g = 0, int b = 0) : r(r), g(g), b(b) { }
};

const int MAXN = 202;

bool f[MAXN][MAXN][MAXN];
queue <TState> q;

void add(const TState s) {
    if (f[s.r][s.g][s.b]) {
        return;
    }
    f[s.r][s.g][s.b] = true;
    q.push(s);
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
        string s;
        cin >> s;
        memset(f, 0, sizeof(f));

        int r, g, b;
        r = g = b = 0;
        for (auto& c : s) {
            switch (c) {
                case 'R': r += 1; break;
                case 'G': g += 1; break;
                case 'B': b += 1; break;
            }
        }
        add({r, g, b});
        while (q.size()) {
            TState s = q.front();
            //cout << s.r << " " << s.g << " " << s.b << endl;
            q.pop();
            if (s.r > 1) { add({s.r - 1, s.g, s.b}); }
            if (s.g > 1) { add({s.r, s.g - 1, s.b}); }
            if (s.b > 1) { add({s.r, s.g, s.b - 1}); }
            if (s.r > 0 && s.g > 0) { add({s.r - 1, s.g - 1, s.b + 1}); }
            if (s.r > 0 && s.b > 0) { add({s.r - 1, s.g + 1, s.b - 1}); }
            if (s.g > 0 && s.b > 0) { add({s.r + 1, s.g - 1, s.b - 1}); }
        }
        if (f[0][0][1]) { cout << "B"; }
        if (f[0][1][0]) { cout << "G"; }
        if (f[1][0][0]) { cout << "R"; }
        cout << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}