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
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, const T y) {
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

bool le(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.fst * b.snd < a.snd * b.fst;
}

bool eq(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return !le(a, b) && !le(b, a);
}

vector<pair<ll, ll>> a;
ld T;

bool check(ld c) {
    vector<ld> pref(a.size());
    for (int i = 0; i < a.size(); i++) {
        pref[i] = a[i].fst;
        if (i) {
            pref[i] += pref[i - 1];
        }
    }

    int n = a.size();
    vector<int> lb(n), rb(n);

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && eq(a[i], a[j])) {
            j++;
        }

        for (int h = i; h < j; h++) {
            lb[h] = i;
            rb[h] = j - 1;
        }
        i = j - 1;
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [](int u, int v) {
        return mp(a[u].snd, a[u].fst) < mp(a[v].snd, a[v].fst);
    });


    ld ma = -1e30;

    for (int i = 0; i < n; i++) {
        ld cma = -1e30;
        int j = i;
        while (j < n && a[ord[i]].snd == a[ord[j]].snd) {
            j++;
        }

        for (int h = i; h < j; h++) {
            int x = ord[h];
            ld val = a[x].snd * (1.0 - c * pref[rb[x]] / T);
            ld val2 = a[x].snd * (1.0 - c * (pref[lb[x]] - a[lb[x]].fst + a[x].fst) / T);

            if (ma > val) {
                return true;
            }

            chmax(cma, val2);
        }

        chmax(ma, cma);

        i = j - 1;
    }


    sort(ord.begin(), ord.end(), [](int u, int v) {
        return mp(a[u].snd, -a[u].fst) < mp(a[v].snd, -a[v].fst);
    });


    ma = -1e30;

    for (int i = 0; i < n; i++) {
        ld cma = -1e30;
        int j = i;
        while (j < n && a[ord[i]].snd == a[ord[j]].snd) {
            j++;
        }

        for (int h = i; h < j; h++) {
            int x = ord[h];
            ld val = a[x].snd * (1.0 - c * pref[rb[x]] / T);
            ld val2 = a[x].snd * (1.0 - c * (pref[lb[x]] - a[lb[x]].fst + a[x].fst) / T);

            if (ma > val) {
                return true;
            }

            chmax(cma, val2);
        }

        chmax(ma, cma);

        i = j - 1;
    }



    return false;
}

int main() {

    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("hovels.in", "r", stdin);
    //freopen("hovels.out", "w", stdout);
#endif


    int n;
    scanf("%d", &n);


    a.resize(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i].snd = x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i].fst = x;
        T += x;
    }

    sort(a.begin(), a.end(), [&](const pair<ll, ll> &a, const pair<ll, ll> &b) {
        return le(a, b);
    } );


    ld lo = 0.0, hi = 1;
    for (int i = 0; i < 40; i++) {
        ld mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout.precision(20);
    cout << fixed << lo << endl;


    return 0;
}