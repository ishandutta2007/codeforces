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

const int maxn = 1e6 + 5;
int ans[maxn];

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

    int n, m;
    scanf("%d %d", &n, &m);

    vector<pair<ll, ll>> p;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p.pb(mp(x, y));
    }

    fill(ans + 1, ans + 1 + n, 1);

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            ll a = p[i].snd - p[j].snd;
            ll b = p[j].fst - p[i].fst;
            ll c = -a * p[i].fst - b * p[i].snd;

            int cnt = 0;
            for (int k = 0; k < m; k++) {
                if (a * p[k].fst + b * p[k].snd + c == 0) {
                    cnt++;
                }
            }

            if (a != 0 && abs(c) % abs(a) == 0) {
                ll x = -c / a;
                if (1 <= x && x <= n) {
                    chmax(ans[x], cnt);
                }
            }
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += ans[i];
    }

    cout << res << endl;


    return 0;
}