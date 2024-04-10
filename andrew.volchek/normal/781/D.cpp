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
#include <future>

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

const ld pi = acos(-1.0);

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


//--------------------------------------------------------------------------

const int maxn = 505;
struct M {
    bitset<maxn> rows[maxn];
    bitset<maxn> cols[maxn];
    void set(int i, int j, int x) {
        rows[i][j] = x;
        cols[j][i] = x;
    }
    int get(int i, int j) {
        return rows[i][j];
    }
    M operator * (const M& rhs) const {
        M res;
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                res.set(i, j, (rows[i] & rhs.cols[j]).count() > 0);
            }
        }
        return res;
    }
};

M a[65][2];


int main(int argc, char* argv[]) {

    srand(134);

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //gen();
    //return 0;

#else
    //freopen("identification.in", "r", stdin);
    //freopen("identification.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[0][w].set(u, v, 1);
    }

    for (int i = 1; i < 65; i++) {
        a[i][0] = a[i - 1][0] * a[i - 1][1];
        a[i][1] = a[i - 1][1] * a[i - 1][0];
    }

    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            if (a[63][0].get(i, j)) {
                cout << -1 << endl;
                return 0;
            }
        }
    }


    vector<int> s;
    for (int i = 1; i <= n; i++) {
        s.pb(i);
    }
    ll ans = 0;
    int p = 0;
    for (int i = 62; i >= 0; i--) {
        set<int> ns;
        for (int v : s) {
            for (int j = 1; j <= n; j++) {
                if (a[i][p].get(v, j)) {
                    ns.insert(j);
                }
            }
        }
        if (ns.size()) {
            p = 1 - p;
            ans |= 1LL << i;
            s = vector<int>(ns.begin(), ns.end());
        }
    }

    if (ans > 1000000000LL * 1000000000LL) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;


    return 0;
}