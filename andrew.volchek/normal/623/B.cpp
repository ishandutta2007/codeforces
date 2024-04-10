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

const int maxn = 1e6 + 5;
const ll inf = 1e18;
int c[maxn];
ll dpL[maxn], dpR[maxn];
int n;

ll a, b;

ll solve(int x) {
    //cerr << "cand " << x << endl;
    for (int i = 1; i <= n; i++) {
        dpL[i] = dpL[i - 1];

        int o = c[i] % x;
        if (o == 0) {
            dpL[i] = dpL[i - 1];
        } else if (o == 1) {
            dpL[i] = dpL[i - 1] + b;
        } else if (o == x - 1) {
            dpL[i] = dpL[i - 1] + b;
        } else {
            dpL[i] = inf;
        }

        chmin(dpL[i], inf);
    }

    for (int i = n; i >= 1; i--) {
        dpR[i] = dpR[i + 1];

        int o = c[i] % x;
        if (o == 0) {
            dpR[i] = dpR[i + 1];
        } else if (o == 1) {
            dpR[i] = dpR[i + 1] + b;
        } else if (o == x - 1) {
            dpR[i] = dpR[i + 1] + b;
        } else {
            dpR[i] = inf;
        }

        chmin(dpR[i], inf);
    }

    ll s = -a;
    ll res = inf;
    for (int i = 1; i <= n; i++) {
        //cout << i << " " << dpR[i] << " " << dpL[i] << " " <<  dpR[i] + a * i + s << endl;
        chmin(res, dpR[i] + a * i + s);
        chmin(s, dpL[i] - a * (i + 1));
    }

    return res;
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

    set<int> cand;

    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        scanf("%d", c + i);
    }

    for (int dx = -1; dx <= 1; dx++) {
        int x = c[1] + dx;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                cand.insert(i);
                cand.insert(x / i);
            }

            while (x % i == 0) {
                x /= i;
            }
        }

        if (x > 1) {
            cand.insert(x);
        }

        x = c[n] + dx;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                cand.insert(i);
                cand.insert(x / i);
            }

            while (x % i == 0) {
                x /= i;
            }
        }

        if (x > 1) {
            cand.insert(x);
        }
    }

    cand.erase(1);
    ll ans = inf;
    for (int x : cand) {
        chmin(ans, solve(x));
    }

    reverse(c + 1, c + n + 1);

    for (int x : cand) {
        chmin(ans, solve(x));
    }

    cout << ans << endl;

    return 0;
}