#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <tuple>
#include <complex>
#include <numeric>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

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

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 3005;
const int inf = 1e9;
int dp[maxn][maxn];
int pr[maxn][maxn];

struct S {
    int p, s, id;
    S(int p, int s, int id) :p(p), s(s), id(id) {}
    bool operator < (const S &rhs) const {
        return -p + s < -rhs.p + rhs.s;
    }
};

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    // gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n, p, s;
    cin >> n >> p >> s;
    vector<S> a;
    vector<int> pp(n), ss(n);
    for (int i = 0; i < n; i++) {
        cin >> pp[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
    }
    for (int i = 0; i < n; i++) {
        a.pb(S(pp[i], ss[i], i + 1));
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < maxn; i++) {
        fill(dp[i], dp[i] + maxn, -inf);
    }
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == inf) {
                continue;
            }

            if (chmax(dp[i + 1][j], dp[i][j])) {
                pr[i + 1][j] = 0;
            }

            if (chmax(dp[i + 1][j + 1], dp[i][j] + (j >= p ? a[i].s : a[i].p))) {
                pr[i + 1][j + 1] = 1;
            }
        }
    }

    cout << dp[n][p + s] << endl;
    vector<S> b;

    int u = p + s;
    for (int i = n; i > 0; i--) {
        if (pr[i][u] == 0) {

        } else {
            u--;
            b.pb(a[i - 1]);
        }
    }
    reverse(b.begin(), b.end());

    for (int i = 0; i < p + s; i++) {
        if (i == p) {
            cout << endl;
        }
        cout << b[i].id << " ";
    }


    return 0;
}