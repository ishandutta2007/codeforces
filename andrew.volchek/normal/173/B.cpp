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
#define ld double
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
ostream operator << (ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1055;
char a[maxn][maxn];
vector<pair<int,int>> g[maxn * maxn];

int d[maxn * maxn][2];

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
    auto enc = [&](int x, int y) {
        return x * (m + 2) + y;
    };

    for (int i = 0; i < n; i++) {
        scanf("%s\n", a[i] + 1);
        a[i][0] = a[i][m + 1] = '.';
    }

    a[0][0] = '#';
    a[n - 1][m + 1] = '#';

    for (int i = 0; i < n; i++) {
        int prv = -1;
        for (int j = 0; j <= m + 1; j++) {
            if (a[i][j] == '.') {
                continue;
            }

            if (prv != -1) {
                g[prv].pb(mp(enc(i, j), 0));
                g[enc(i, j)].pb(mp(prv, 0));
            }
            prv = enc(i, j);
        }
    }

    for (int i = 0; i <= m + 1; i++) {
        int prv = -1;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == '.') {
                continue;
            }

            if (prv != -1) {
                g[prv].pb(mp(enc(j, i), 1));
                g[enc(j, i)].pb(mp(prv, 1));
            }
            prv = enc(j, i);
        }
    }


    deque<pair<int,int>> q;
    const int inf = 1e9;
    for (int i = 0; i < maxn * maxn; i++) {
        for (int j = 0; j < 2; j++) {
            d[i][j] = inf;
        }
    }

    d[enc(0, 0)][0] = 0;
    q.push_front(mp(enc(0, 0), 0));

    while (!q.empty()) {
        int v = q.front().fst;
        int di = q.front().snd;
        q.pop_front();

        for (auto to : g[v]) {
            if (d[to.fst][to.snd] != inf) {
                continue;
            }

            d[to.fst][to.snd] = d[v][di] + (di != to.snd);
            if (di != to.snd) {
                q.push_back(mp(to.fst, to.snd));
            } else {
                q.push_front(mp(to.fst, to.snd));
            }
        }
    }


    int ans = d[enc(n - 1, m + 1)][0];

    if (ans == inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}