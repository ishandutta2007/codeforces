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
#define ld double
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


const int maxn = sqrt(2e9) + 5;
const int magic = 79;
int p[maxn];
vector<int> pr;

int brute(int l, int r, int k) {
    int res = 0;
    for (int i = l; i <= r; i++) {
        bool bad = i % k;
        for (int j = 2; j < k; j++) {
            if (i % j == 0) {
                bad = true;
                break;
            }
        }
        res += !bad;
    }
    return res;
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

    for (ll i = 2; i < maxn; i++) {
        if (!p[i]) {
            pr.pb(i);
            for (ll j = i * i; j < maxn; j += i) {
                p[j] = 1;
            }
        }
    }

    int l, r, k;
    cin >> l >> r >> k;

    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    //l = 123, r = 1234567;
    //k = pr[110];


    if (k >= magic) {
        int s = 0;
        for (ll i = 0; i <= r; i += k) {
            bool bad = !(i >= l);
            for (int x : pr) {
                if (x >= k) {
                    break;
                }
                if (i % x == 0) {
                    bad = true;
                    break;
                }
            }
            s += !bad;
        }

        cout << s << endl;
    } else {
        int sz = lower_bound(pr.begin(), pr.end(), k) - pr.begin();
        ll res = 0;
        r /= k;
        l = (l - 1) / k;
        for (int i = 0; i < (1 << sz); i++) {
            int m = 1;
            ll x = 1;
            for (int j = 0; j < sz; j++) {
                if (i & (1 << j)) {
                    m = -m;
                    x *= pr[j];
                    if (x > r) {
                        break;
                    }
                }
            }
            res += (r / x - l / x) * m;
        }
        cout << res << endl;
    }

    return 0;
}