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

int cnt(pair<int,int> a1, int d1, pair<int,int> a2, int d2) {
    pair<int,int> na1(a1.fst + d1, a1.snd);
    pair<int,int> na2(a2.fst + d2, a2.snd);

    return (min(a1, na1) < a2 && a2 < max(a1, na1)) && (min(a2, na2) < na1 && na1 < max(a2, na2));
}

const int maxn = 105;
vector<int> g[maxn];

int used[maxn];
vector<int> order;
void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (used[to] == 1) {
            assert(0);
        } else if (!used[to]) {
            dfs(to);
        }
    }
    order.pb(v);
    used[v] = 2;
}

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

    int n;
    cin >> n;
    vector<pair<int,int>> a;
    vector<int> d;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.pb(mp(x, -i));
        d.pb(y);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt1 = cnt(a[i], d[i], a[j], d[j]);
            int cnt2 = cnt(a[j], d[j], a[i], d[i]);

            if (cnt1 > cnt2) {
                g[i].pb(j);
            } else if (cnt1 < cnt2) {
                g[j].pb(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    reverse(order.begin(), order.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int v = order[i];
        pair<int,int> x = a[v];
        pair<int,int> y = mp(x.fst + d[v], x.snd);

        int cnt = 0;
        for (auto p : a) {
            cnt += min(x, y) < p && p < max(x, y);
        }
        ans += cnt;

        a[v].fst += d[v];
    }

    cout << ans << endl;


    return 0;
}