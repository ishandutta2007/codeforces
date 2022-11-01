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


//-----------------------------------------------------------------------------
const int maxn = 3e5 + 5;

map<int, vector<pair<int,int>>> f, g;


int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    // gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);


    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        f[x + y].pb(mp(x, i));
        g[x - y].pb(mp(x, i));
    }

    for (auto &kv : f) {
        sort(kv.snd.begin(), kv.snd.end());
    }
    for (auto &kv : g) {
        sort(kv.snd.begin(), kv.snd.end());
    }

    int x = 0, y = 0;
    int dx = 1, dy = 1;
    int p = 0;

    vector<ll> ans(k, 1e18);
    ll currT = 0;

    while (true) {
        int t = 1e9;
        if (dx == 1) {
            chmin(t, n - x);
        } else {
            chmin(t, x);
        }

        if (dy == 1) {
            chmin(t, m - y);
        } else {
            chmin(t, y);
        }


        int nx = x + dx * t, ny = y + dy * t;
        //cout << x << " " << y << endl;


        if (!p) {
            auto v = g[x - y];

            for (auto w : v) {
                chmin(ans[w.snd], currT + abs(w.fst - x));
            }
            g[x - y].clear();
        } else {
            auto v = f[x + y];
            if (dx == -1) {
                reverse(v.begin(), v.end());
            }
            for (auto w : v) {
                chmin(ans[w.snd], currT + abs(w.fst - x));
            }
            f[x + y].clear();
        }


        if ((nx == 0 || nx == n) && (ny == 0 || ny == m)) {
            break;
        }

        currT += t;
        p ^= 1;
        if (nx == 0 || nx == n) {
            dx = -dx;
        } else {
            dy = -dy;
        }

        x = nx, y = ny;
    }

    //cout << ans << endl;

    for (int i = 0; i < k; i++) {
        if (ans[i] > 1e17) {
            printf("-1\n");
        } else {
            printf("%lld\n", ans[i]);
        }
    }



    return 0;
}