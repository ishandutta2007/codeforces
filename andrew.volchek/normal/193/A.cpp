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
ostream &operator<<(ostream &s, const pair <U, V> &x) {
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

const int maxn = 55;
char a[maxn][maxn];
int used[maxn][maxn];
int currUsed = 1;
int n, m;
int bx, by;

void dfs(int x, int y) {
    if (x < 0 || x == n || y < 0 || y == m) {
        return;
    }

    if (x == bx && y == by) {
        return;
    }

    if (used[x][y] == currUsed) {
        return;
    }

    if (a[x][y] != '#') {
        return;
    }

    used[x][y] = currUsed;

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
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

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s\n", a[i]);
        for (int j = 0; j < m; j++) {
            cnt += (a[i][j] == '#');
        }
    }

    if (cnt <= 2) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bx = i, by = j;
            int cnt = 0;
            currUsed++;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (x == i && y == j) {
                        continue;
                    }
                    if (a[x][y] == '#' && used[x][y] != currUsed) {
                        cnt++;
                        dfs(x, y);
                    }
                }
            }
            if (cnt > 1) {
                //cout << i << " " << j << endl;
                cout << 1 << endl;
                return 0;
            }
        }
    }


    cout << 2 << endl;

    return 0;
}