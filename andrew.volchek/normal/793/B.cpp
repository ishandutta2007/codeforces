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
#include <future>

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

const ld pi = acos(-1.0);

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


//--------------------------------------------------------------------------
const int maxn = 1005;
char a[maxn][maxn];
int n, m;
bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && a[x][y] != '*';
}
const int dirs[4][2] = {
        1, 0,
        -1, 0,
        0, 1,
        0, -1
};
int dist[maxn][maxn][4];
const int inf = 1e9;
int main() {

    srand(0);

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("brackets.in", "r", stdin);
    //freopen("brackets.out", "w", stdout);
#endif

    scanf("%d %d\n", &n, &m);
    pair<int,int> s, f;
    for (int i = 0; i < n; i++) {
        scanf("%s\n", a[i]);
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                s = mp(i, j);
            }
            if (a[i][j] == 'T') {
                f = mp(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int h = 0; h < 4; h++) {
                dist[i][j][h] = inf;
            }
        }
    }
    queue<pair<int, pair<int,int>>> q;
    for (int i = 0; i < 4; i++) {
        dist[s.fst][s.snd][i] = 0;
        q.push(mp(i, s));
    }
    while (!q.empty()) {
        int x = q.front().snd.fst;
        int y = q.front().snd.snd;
        int d = q.front().fst;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int cx = x + dirs[i][0];
            int cy = y + dirs[i][1];
            if (!valid(cx, cy)) {
                continue;
            }
            if (chmin(dist[cx][cy][i], dist[x][y][d] + (i != d))) {
                q.push(mp(i, mp(cx, cy)));
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (dist[f.fst][f.snd][i] <= 2) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}