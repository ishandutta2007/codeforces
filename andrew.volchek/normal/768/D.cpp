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

const int maxn = 1005;
ld f[maxn], nf[maxn];

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
    int k, q;
    cin >> k >> q;

    const ld eps = 1e-7;
    vector<pair<int,int>> a(q);
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i].fst;
        a[i].snd = i;
    }
    sort(a.begin(), a.end());

    f[0] = 1;
    int ptr = 0;
    for (int i = 0; ptr < a.size(); i++) {
        for (int j = 0; j <= k; j++) {
            nf[j] += f[j] * 1. * j / k;
            nf[j + 1] += f[j] * 1. * (k - j) / k;
        }
        for (int j = 0; j <= k; j++) {
            f[j] = nf[j];
            nf[j] = 0;
        }
        while (ptr < a.size() && (a[ptr].fst - eps) / 2000.0 < f[k]) {
            ans[a[ptr].snd] = i + 1;
            ptr++;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }



    return 0;
}