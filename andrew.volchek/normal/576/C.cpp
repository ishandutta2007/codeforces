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

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
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
ostream operator << (ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1e6 + 5;
pair<pair<int,int>, int> a[maxn];

void rec(int l, int r, int p) {
    if (l == r) {
        return;
    }

    int c = (l + r) >> 1;
    if (p) {
        nth_element(a + l, a + c, a + r + 1,
                    [&](const pair<pair<int,int>, int> &u, const pair<pair<int,int>, int> &v) {
                        return mp(u.fst.fst, u.snd) < mp(v.fst.fst, v.snd);
                    });
    } else {
        nth_element(a + l, a + c, a + r + 1,
                    [&](const pair<pair<int,int>, int> &u, const pair<pair<int,int>, int> &v) {
                        return mp(u.fst.snd, u.snd) < mp(v.fst.snd, v.snd);
                    });
    }

    rec(l, c, 1 - p);
    rec(c + 1, r, 1 - p);
}

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif


    int n;
    scanf("%d", &n);
    //n = 1e6;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        //x = rand() % 1000000, y = rand() % 1000000;
        a[i] = mp(mp(x, y), i + 1);
    }

    rec(0, n - 1, 0);

    ll len = 0;
    for (int i = 0; i < n; i++) {
        len += abs(a[i].fst.fst - a[(i + 1) % n].fst.fst);
        len += abs(a[i].fst.snd - a[(i + 1) % n].fst.snd);
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }

        printf("%d", a[i].snd);
    }


    return 0;
}