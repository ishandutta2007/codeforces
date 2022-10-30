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

//-----------------------------------------------------------------------------

const int maxn = 1505;

int a[maxn][maxn];
pair<int,int> prv[maxn][maxn];

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
    int sx, sy;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            scanf("%c", &c);
            if (c == 'S') {
                sx = i, sy = j;
            } else if (c == '#') {
                a[i][j] = 1;
            }
        }
        scanf("\n");
    }

    queue<pair<int,int>> q;
    q.push(mp(sx, sy));
    a[sx][sy] = 2;
    prv[sx][sy] = mp(sx, sy);

    while (!q.empty()) {
        int x = q.front().fst;
        int y = q.front().snd;
        q.pop();

        const int dirs[4][2] = {
                1, 0,
                -1, 0,
                0, 1,
                0, -1,
        };

        for (int i = 0; i < 4; i++) {
            int cx = x + dirs[i][0];
            int cy = y + dirs[i][1];

            int dx = cx % n;
            if (dx < 0) {
                dx += n;
            }

            int dy = cy % m;
            if (dy < 0) {
                dy += m;
            }

            if (a[dx][dy] == 0) {
                a[dx][dy] = 2;
                prv[dx][dy] = mp(cx, cy);
                q.push(mp(cx, cy));
            } else if (a[dx][dy] == 2) {
                if (prv[dx][dy].fst != cx || prv[dx][dy].snd != cy) {
                    //cout << mp(dx, dy) << " " << mp(cx, cy) << " " << prv[dx][dy] << endl;
                    cout << "Yes" << endl;
                    return 0;
                }
            }


        }
    }

    cout << "No" << endl;

    return 0;
}