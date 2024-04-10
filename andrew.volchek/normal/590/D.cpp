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
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 155;
int a[maxn];
const ll inf = 1e16;
int used[maxn][maxn * maxn];
int cu = 1;

ll dp[maxn][maxn * maxn];
ll ndp[maxn][maxn * maxn];


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

    int n, k, s;
    cin >> n >> k >> s;
    // = 150, k = 75, s = 1e9;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        //a[i] = rand() % 1000000;
    }

    for (int i = 0; i < maxn; i++) {
        fill(dp[i], dp[i] + maxn * maxn, inf);
        fill(ndp[i], ndp[i] + maxn * maxn, inf);
    }

    dp[0][0] = 0;
    vector<pair<int,int>> good;
    good.pb(mp(0, 0));

    for (int i = 0; i < n; i++) {
        cu++;
        for (auto c : good) {
            ndp[c.fst][c.snd] = dp[c.fst][c.snd];
            used[c.fst][c.snd] = cu;
        }

        vector<pair<int,int>> ng;
        for (auto c : good) {
            if (c.fst < k) {
                pair<int,int> nc = c;
                nc.fst++;
                nc.snd += i - c.fst;
                chmin(ndp[nc.fst][nc.snd], dp[c.fst][c.snd] + a[i]);

                if (used[nc.fst][nc.snd] != cu) {
                    used[nc.fst][nc.snd] = cu;
                    ng.pb(nc);
                }
            }
        }

        for (auto c : ng) {
            good.pb(c);
        }

        for (auto c : good) {
            dp[c.fst][c.snd] = ndp[c.fst][c.snd];
            ndp[c.fst][c.snd] = inf;
        }

        ng.clear();
        for (auto c : good) {
            if (n - i + c.fst >= k - 2) {
                ng.pb(c);
            }
        }

        good = ng;
    }

    cerr << good.size() << endl;


    ll ans = inf;
    for (auto p : good) {
        if (p.snd <= s && p.fst == k) {
            chmin(ans, dp[p.fst][p.snd]);
        }
    }

    cout << ans << endl;
    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;

    return 0;
}