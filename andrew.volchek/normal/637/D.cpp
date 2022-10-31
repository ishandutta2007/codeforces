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
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

void die() {
    printf("IMPOSSIBLE\n");
    exit(0);
}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("rotor.in", "r", stdin);
    //freopen("rotor.out", "w", stdout);
#endif

    int n;
    ll m, s, d;
    cin >> n >> m >> s >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    set<int> b(a.begin(), a.end());

    if (a[0] - 1 < s) {
        die();
    }

    vector<int> canJumpAfter(n, 0);
    vector<int> parent(n, -1);

    set<int> unknown;
    for (int i = 0; i < n; i++) {
        unknown.insert(i);
    }

    for (int i = 0; i < n; i++) {
        if (i && (!canJumpAfter[i - 1] || (a[i] - a[i - 1] - 2) < s)) {
            continue;
        }

        while (true) {
            auto it = unknown.lower_bound(i);
            if (it == unknown.end()) {
                break;
            }

            if ((a[*it] + 1) - (a[i] - 1) > d) {
                break;
            }

            if (b.count(a[*it] + 1)) {
                unknown.erase(it);
                continue;
            }

            canJumpAfter[*it] = 1;
            parent[*it] = i;

            unknown.erase(it);
        }
    }

    if (!canJumpAfter.back()) {
        die();
    }

    vector<pair<int, int>> ans;

    int v = n - 1;
    int x = m;
    while (v >= 0) {
        if (x != a[v] + 1) {
            ans.pb(mp(0, x - (a[v] + 1)));
        }

        assert(parent[v] != -1);
        int p = parent[v];
        ans.pb(mp(1, (a[v] + 1) - (a[p] - 1)));
        v = p - 1;
        x = a[p] - 1;
    }

    if (x) {
        ans.pb(mp(0, x));
    }

    reverse(ans.begin(), ans.end());

    for (auto x : ans) {
        if (x.fst) {
            printf("JUMP %d\n", x.snd);
        } else {
            printf("RUN %d\n", x.snd);
        }
    }

    return 0;
}