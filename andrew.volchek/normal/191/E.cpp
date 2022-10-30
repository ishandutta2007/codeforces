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


//-----------------------------------------------------------------------------

const int maxn = 1e5 + 5;
int ft[maxn];

void inc(int i) {
    if (i < 0) {
        return;
    }
    while (i < maxn) {
        ft[i]++;
        i |= (i + 1);
    }
}

int sum(int r) {
    int res = 0;
    while (r >= 0) {
        res += ft[r];
        r = (r & (r + 1)) - 1;
    }
    return res;
}

void clear() {
    fill(ft, ft + maxn, 0);
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
    ll k;
    cin >> n >> k;
    vector<ll> a;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a.pb(x);
    }


    vector<ll> cc;
    cc.pb(0);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        cc.pb(s);
    }

    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    auto get = [&](ll x) {
        int lo = -1, hi = cc.size();
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;
            if (cc[mid] <= x) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    };

    ll lo = -1e16, hi = 1e16;
    while (hi - lo > 1) {
        ll mid = (lo + hi) >> 1;

        ll cnt = 0;
        clear();
        inc(get(0));

        ll s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i];
            ll x = s - mid;
            cnt += sum(get(x));
            inc(get(s));
        }

        if (cnt >= k) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << endl;

    return 0;
}