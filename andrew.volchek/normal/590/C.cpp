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

const int maxn = 1005;
const int inf = 1e9;
char a[maxn][maxn];
const int dirs[4][2] = {
    1, 0,
    -1, 0,
    0, 1,
    0, -1,
};

int n, m;
bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int d[3][maxn][maxn];

void bfs(char s, int d[maxn][maxn]) {
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == s) {
                d[i][j] = 0;
                q.push(mp(i, j));
            } else {
                d[i][j] = inf;
            }
        }
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int cx = v.fst + dirs[i][0];
            int cy = v.snd + dirs[i][1];
            if (!valid(cx, cy) || a[cx][cy] == '#' || d[cx][cy] != inf) {
                continue;
            }
            d[cx][cy] = d[v.fst][v.snd] + 1;
            q.push(mp(cx, cy));
        }
    }
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

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s\n", a[i]);
    }

    bfs('1', d[0]);
    bfs('2', d[1]);
    bfs('3', d[2]);

    ll ans = inf;

    for (int i = 0; i < 3; i++) {
        ll mm[3] = { inf, inf, inf };
        for (int j = 0; j < n; j++) {
            for (int h = 0; h < m; h++) {
                if (isdigit(a[j][h])) {
                    chmin(mm[a[j][h] - '1'], (ll)d[i][j][h]);
                }
            }
        }

        chmin(ans, max(0LL, mm[0] - 1) +
                max(0LL, mm[1] - 1) +
                max(0LL, mm[2] - 1));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                chmin(ans, 1LL + max(0, d[0][i][j] - 1) +
                                 max(0, d[1][i][j] - 1) +
                                 max(0, d[2][i][j] - 1));
            }
        }
    }

    if (ans > 1e8) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}