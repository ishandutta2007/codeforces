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
ostream& operator << (ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream& operator << (ostream &s, const vector<U> &x) {
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

//-----------------------------------------------------------------------------

ll pw[20];

ll solve(ll r) {
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        if (i <= r) {
            ans++;
        }

        if (i) {
            ans += (10 * i + i) <= r;
        }
    }

    for (int len = 3; len <= 19; len++) {
        for (int j = 1; j < 10; j++) {
            ll x = pw[len - 1] * j + j;

            ll lo = -1, hi = pw[len - 2];
            while (hi - lo > 1) {
                ll mid = (lo + hi) >> 1;
                if (mid * 10 + x <= r) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            ans += lo - (-1);
        }
    }

    return ans;
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

    pw[0] = 1;
    for (int i = 1; i < 20; i++) {
        pw[i] = pw[i - 1] * 10;
    }


    ll l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << endl;


    return 0;
}