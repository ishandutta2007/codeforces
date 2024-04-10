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


const int maxn = 1005;
int a[maxn][maxn];
int used[maxn][maxn];
int b[maxn][maxn];
int ver = 1;

const int dirs[8][2] = {
        1, 0,
        0, 1,
        -1, 0,
        0, -1,
        1, 1,
        -1, -1,
        -1, 1,
        1, -1,
};

int n, m;
auto valid = [&](int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
};


void dfs(int x, int y) {
    b[x][y] = -1;
    for (int i = 0; i < 4; i++) {
        int cx = x + dirs[i][0];
        int cy = y + dirs[i][1];

        if (valid(cx, cy) && b[cx][cy] == ver) {
            dfs(cx, cy);
        }
    }
}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    // gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif


    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            scanf("%c", &c);
            a[i][j] = c - '0';
        }
        scanf("\n");
    }


    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (used[i][j]) {
                continue;
            }

            if (a[i][j]) {
                continue;
            }

            used[i][j] = 1;
            vector<pair<int,int>> cycle;
            bool good = true;


            queue<pair<int,int>> q;
            q.push(mp(i, j));
            ver++;

            while (!q.empty()) {
                int x = q.front().fst;
                int y = q.front().snd;
                q.pop();

                for (int i = 0; i < 8; i++) {
                    int cx = x + dirs[i][0];
                    int cy = y + dirs[i][1];

                    if (!valid(cx, cy)) {
                        good = false;
                        continue;
                    }

                    if (used[cx][cy]) {
                        continue;
                    }

                    if (a[cx][cy] == 0) {
                        used[cx][cy] = 1;
                        q.push(mp(cx, cy));
                    } else {
                        if (b[cx][cy] != ver) {
                            b[cx][cy] = ver;
                            cycle.pb(mp(cx, cy));
                        }
                    }
                }
            }

            for (auto p : cycle) {
                int cnt = 0;
                for (int i = 0; i < 4; i++) {
                    int cx = p.fst + dirs[i][0];
                    int cy = p.snd + dirs[i][1];
                    if (valid(cx, cy) && b[cx][cy] == ver) {
                        cnt++;
                    }
                }
                good &= cnt == 2;
            }

            int comp = 0;
            for (auto p : cycle) {
                if (b[p.fst][p.snd] == ver) {
                    comp++;
                    dfs(p.fst, p.snd);
                }
            }

            good &= comp == 1;

            if (good) {
                chmax(ans, (int)cycle.size());
            }
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            if (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] == 4) {
                chmax(ans, 4);
            }
        }
    }

    cout << ans << endl;

    return 0;
}