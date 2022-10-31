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
int dist[maxn][maxn];

const int dirs[4][2] = {
    1, 0,
    0, -1,
    0, 1,
    -1, 0,
};

const char dirsN[4] = {
        'D',
        'L',
        'R',
        'U'
};

int main(int argc, char* argv[]) {

    srand(134);

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //gen();
    //return 0;

#else
    //freopen("identification.in", "r", stdin);
    //freopen("identification.out", "w", stdout);
#endif

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    if (k & 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int sx, sy;

    auto valid = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m && a[x][y] != '*';
    };

    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X') {
                sx = i, sy = j;
            }
            dist[i][j] = 1e9;
        }
    }

    queue<pair<int,int>> q;
    q.push(mp(sx, sy));
    dist[sx][sy] = 0;
    while (!q.empty()) {
        int x = q.front().fst;
        int y = q.front().snd;
        q.pop();
        int cd = dist[x][y];
        for (int i = 0; i < 4; i++) {
            int cx = x + dirs[i][0];
            int cy = y + dirs[i][1];
            if (valid(cx, cy) && dist[cx][cy] > cd + 1) {
                dist[cx][cy] = cd + 1;
                q.push(mp(cx, cy));
            }
        }
    }

    string ans;
    int x = sx, y = sy;
    while (k--) {
        bool found = false;
        for (int i = 0; i < 4; i++) {
            int cx = x + dirs[i][0], cy = y + dirs[i][1];
            if (valid(cx, cy) && dist[cx][cy] <= k) {
                ans += dirsN[i];
                x = cx, y = cy;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    assert(x == sx && y == sy);

    printf("%s\n", ans.c_str());

    return 0;
}