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

const int maxn = 1005;

int a[maxn][maxn];
int sum[maxn][maxn];

int getSum(int x1, int y1, int x2, int y2) {
    x1 = max(1, x1);
    y1 = max(1, y1);
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int b[maxn][maxn];

short rmq[10][10][maxn][maxn];
int pw[maxn];

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

    for (int i = 1; i < maxn; i++) {
        while ((1 << pw[i]) <= i) {
            pw[i]++;
        }
        pw[i]--;
    }

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int e = min(b[i - 1][j], b[i][j - 1]) + 1;
            for (int h = max(1, e - 2); h <= e + 1; h++) {
                if (getSum(i - h + 1, j - h + 1, i, j) == h * h) {
                    b[i][j] = h;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            rmq[0][0][i][j] = b[i][j];
        }
    }

    for (int k = 1; k < 10; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            for (int j = 1; j <= m; j++) {
                rmq[k][0][i][j] = max(rmq[k - 1][0][i][j], rmq[k - 1][0][i + (1 << (k - 1))][j]);
            }
        }
    }

    for (int h = 0; h < 10; h++) {
        for (int k = 1; k < 10; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j + (1 << k) - 1 <= m; j++) {
                    rmq[h][k][i][j] = max(rmq[h][k - 1][i][j], rmq[h][k - 1][i][j + (1 << (k - 1))]);
                }
            }
        }
    }

    auto getMax = [&](int x1, int y1, int x2, int y2) {
        int kx = pw[x2 - x1 + 1], ky = pw[y2 - y1 + 1];
        return max(
                max(rmq[kx][ky][x1][y1], rmq[kx][ky][x2 - (1 << kx) + 1][y1]),
                max(rmq[kx][ky][x1][y2 - (1 << ky) + 1], rmq[kx][ky][x2 - (1 << kx) + 1][y2 - (1 << ky) + 1])
        );
    };

    int q;
    scanf("%d", &q);

    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int lo = 0, hi = min(x2 - x1 + 1, y2 - y1 + 1) + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;

            if (getMax(x1 + mid - 1, y1 + mid - 1, x2, y2) >= mid) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        printf("%d\n", lo);
    }

    return 0;
}