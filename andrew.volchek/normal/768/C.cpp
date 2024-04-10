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

const int maxn = 1024;
int f[maxn], g[maxn];

int main() {

    srand(134);

retry:
#ifdef LOCAL
    //gen();
    //return 0;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("identification.in", "r", stdin);
    //freopen("identification.out", "w", stdout);
#endif

    int n, k, x;
    cin >> n >> k >> x;

    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        f[y]++;
    }

    while (k--) {
        int w = 0;
        for (int i = 0; i < maxn; i++) {
            if (!f[i]) {
                continue;
            }

            if (w & 1) {
                g[i] += (f[i] >> 1) + (f[i] & 1);
                g[i ^ x] += f[i] >> 1;
            } else {
                g[i] += (f[i] >> 1) ;
                g[i ^ x] += (f[i] >> 1) + (f[i] & 1);
            }

            w += f[i];
        }
        for (int i = 0; i < maxn; i++) {
            f[i] = g[i];
            g[i] = 0;
        }
    }

    int mi = 1e9, ma = -1e9;
    for (int i = 0; i < maxn; i++) {
        if (f[i]) {
            chmin(mi, i);
            chmax(ma, i);
        }
    }
    cout << ma << " " << mi << endl;

    return 0;
}