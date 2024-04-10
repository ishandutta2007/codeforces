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

const int maxn = 1e5 + 5;

pair<ll, ll> a[maxn];
pair<ll, ll> dpL[maxn], dpR[maxn];
int n;

void build() {
    dpL[0] = mp(-1e18, 1e18);
    dpL[1] = mp(a[1].snd, a[1].snd);
    for (int i = 2; i <= n; i++) {
        dpL[i] = dpL[i - 1];
        chmax(dpL[i].fst, a[i].snd);
        chmin(dpL[i].snd, a[i].snd);
    }
    dpL[n + 1] = mp(-1e18, 1e18);
    dpR[n] = mp(a[n].snd, a[n].snd);
    for (int i = n - 1; i >= 1; i--) {
        dpR[i] = dpR[i + 1];
        chmax(dpR[i].fst, a[i].snd);
        chmin(dpR[i].snd, a[i].snd);
    }
}

bool check(ll s) {
    ll xma = -1e18;
    ll xmi = 1e18;

    for (int i = 1; i <= n; i++) {
        chmax(xma, a[i].snd);
        chmin(xmi, a[i].snd);
    }

    if (sqr(abs(xma - xmi)) <= s) {
        return true;
    }

    int l = 1;
    for (int i = 1; i <= n; i++) {

        //chmax(l, i);
        while (sqr(abs(a[l].fst - a[i].fst)) > s) {
            l++;
        }

        ll xma = max(0LL, max(dpL[l - 1].fst, dpR[i + 1].fst));
        ll xmi = min(0LL, min(dpL[l - 1].snd, dpR[i + 1].snd));

        ll val = 0;

        if (!(l == 1 && i == n)) {
            chmax(val, sqr(xma - xmi));
            chmax(val, sqr(xma) + sqr(a[i].fst));
            chmax(val, sqr(xmi) + sqr(a[i].fst));
            chmax(val, sqr(xma) + sqr(a[l].fst));
            chmax(val, sqr(xmi) + sqr(a[l].fst));
        } else {
            return true;
        }

        if (val <= s) {
            return true;
        }
    }

    int r = n;
    for (int i = n; i >= 1; i--) {

        //chmin(r, i);
        while (sqr(abs(a[r].fst - a[i].fst)) > s) {
            r--;
        }

        ll xma = max(0LL, max(dpL[i - 1].fst, dpR[r + 1].fst));
        ll xmi = min(0LL, min(dpL[i - 1].snd, dpR[r + 1].snd));

        ll val = 0;
        if (!(r == n && i == 1)) {
            chmax(val, sqr(xma - xmi));
            chmax(val, sqr(xma) + sqr(a[i].fst));
            chmax(val, sqr(xmi) + sqr(a[i].fst));
            chmax(val, sqr(xma) + sqr(a[r].fst));
            chmax(val, sqr(xmi) + sqr(a[r].fst));
        } else {
            return true;
        }

        if (val <= s) {
            return true;
        }
    }

    return false;
}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[i] = mp(x, y);
    }

    ll ans = 1e18;

    for (int i = 0; i < 2; i++) {

        sort(a + 1, a + n + 1);

        build();

        ll lo = -1, hi = sqr(2e8) + 5;

        while (hi - lo > 1) {
            ll mid = (lo + hi) >> 1;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        chmin(ans, hi);

        for (int j = 1; j <= n; j++) {
            swap(a[j].fst, a[j].snd);
        }
    }

    //cout << check(0) << endl;
    cout << ans << endl;

    return 0;
}