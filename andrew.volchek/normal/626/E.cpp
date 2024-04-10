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

const int maxn = 2e5 + 5;
ll a[maxn];
ll s[maxn];
int n;

ll get(int l, int r) {
    if (l > r) {
        return 0;
    }
    return s[r] - (l ? s[l - 1] : 0);
}

bool le(const pair<ll, ll> &u, const pair<ll, ll> &v) {
    return u.fst * v.snd < v.fst * u.snd;
}

pair<ll, ll> getOdd(int pos, bool restore = false) {
    int lo = -1, hi = min(pos, n - 1 - pos);
    while (hi - lo > 1) {
        int mid = (lo + hi) >> 1;

        pair<ll, ll> x = mp(a[pos] + get(pos - mid, pos - 1) + get(n - mid, n - 1) - a[pos] * (1 + mid * 2), 1 + mid * 2);
        pair<ll, ll> y = mp(a[pos] + get(pos - mid - 1, pos - 1) + get(n - mid - 1, n - 1) - a[pos] * (1 + mid * 2 + 2), 1 + mid * 2 + 2);

        if (le(y, x)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (restore) {
        cout << 1 + hi * 2 << endl;
        for (int i = pos - hi; i < pos; i++) {
            cout << a[i] << " ";
        }
        cout << a[pos] << " ";
        for (int i = n - hi; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        exit(0);
    }

    pair<ll, ll> x = mp(a[pos] + get(pos - hi, pos - 1) + get(n - hi, n - 1) - a[pos] * (1 + hi * 2), 1 + hi * 2);
    return x;
}

pair<ll, ll> getEven(int pos, bool restore = false) {
    int lo = -1, hi = min(pos, n - 1 - (pos + 1));

    while (hi - lo > 1) {
        int mid = (lo + hi) >> 1;

        pair<ll, ll> x = mp(2LL * (a[pos] + a[pos + 1] + get(pos - mid, pos - 1) + get(n - mid, n - 1)) - (a[pos] + a[pos + 1]) * (2 + mid * 2),
                2LL * (2 + mid * 2));
        pair<ll, ll> y = mp(2LL * (a[pos] + a[pos + 1] + get(pos - mid - 1, pos - 1) + get(n - mid - 1, n - 1)) - (a[pos] + a[pos + 1]) * (2 + mid * 2 + 2),
                2LL * (2 + mid * 2 + 2));
        if (le(y, x)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (restore) {
        cout << 2 + hi * 2 << endl;
        for (int i = pos - hi; i < pos; i++) {
            cout << a[i] << " ";
        }
        cout << a[pos] << " " << a[pos + 1] << " ";
        for (int i = n - hi; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        exit(0);
    }

    pair<ll, ll> x = mp(2LL * (a[pos] + a[pos + 1] + get(pos - hi, pos - 1) + get(n - hi, n - 1)) - (a[pos] + a[pos + 1]) * (2 + hi * 2),
            2LL * (2 + hi * 2));

    return x;
};

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

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }

    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        s[i] = a[i];
        if (i) {
            s[i] += s[i - 1];
        }
    }


    pair<ll, ll> ansOdd(-1, 1), ansEven(-1, 1);
    int oddPos, evenPos;

    for (int i = 0; i < n; i++) {
        auto r = getOdd(i);
        if (le(ansOdd, r)) {
            ansOdd = r;
            oddPos = i;
        }

        if (i + 1 < n) {
            auto r = getEven(i);
            if (le(ansEven, r)) {
                ansEven = r;
                evenPos = i;
            }
        }
    }

    if (le(ansOdd, ansEven)) {
        getEven(evenPos, true);
    } else {
        getOdd(oddPos, true);
    }


    return 0;
}