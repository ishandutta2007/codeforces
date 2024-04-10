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
    int d, g, v;
    TState(int d = 0, int g = 0, int v = 0) : d(d), g(g), v(v) { }
};

const int MOD = (int)1e+9 + 7;

const int MAXN = 203;
const int MAXK = 1003;
const int MAXA = 503;
const int MAXD = MAXN / 2 * MAXA + MAXK * 2;
const int MAXG = MAXN / 2;
//int _f[MAXD][MAXG];
int _p[MAXD][MAXG];
//int (*f)[MAXG];
int (*p)[MAXG];

int a[MAXN];
int s[MAXN];

int n, k;

vector <TState> v, q;

void addmod(int &x, const int d)
{
    x += d;
    if (x >= MOD) {
        x -= MOD;
    }
}

int add(int i, int d, int g, int v)
{
    if (n - i < g) {
        return 1;
    }

    if (d - (s[i + g - 1] - s[i - 1]) < -k) {
        return 2;
    }

    int& index = p[d][g];
    if (index == 0) {
        q.push_back({d, g, v});
        index = q.size();
    } else {
        addmod(q[index - 1].v, v);
    }
    return 0;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    while (cin >> n >> k) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);

        s[0] = a[0];
        for (int i = 1; i < n; ++i) {
            s[i] = s[i - 1] + a[i];
        }

        //memset(_f, 0, sizeof(_f));
        memset(_p, 0, sizeof(_p));

        //f = _f + MAXK;
        p = _p + MAXK;

        //f[0][0] = 1;
        q.clear();
        v.clear();
        add(0, 0, 0, 1);

        for (int i = 0; i < n; ++i) {
            v.swap(q);

            q.clear();
            for (auto& s : v) {
                p[s.d][s.g] = 0;
            }

            for (auto& s : v) {
                assert(0 <= s.g && s.g <= n - i);
                assert(-k <= s.d && s.d < MAXD - MAXK);
                //cout << i << " " << s.d << " " << s.g << " = " << s.v << endl;
                add(i + 1, s.d, s.g, s.v * (ll)(s.g + 1) % MOD);
                add(i + 1, s.d + a[i], s.g + 1, s.v);
                if (s.g > 0) {
                    add(i + 1, s.d - a[i], s.g - 1, s.v * (ll)s.g % MOD);
                }
            }
        }
        int ans = 0;
        for (auto& s : q) {
            //cout << s.d << " " << s.g << " = " << s.v << endl;
            assert(s.g == 0);
            assert(-k <= s.d && s.d <= 0);
            addmod(ans, s.v);
        }
        cout << ans << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}