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

const int maxn = 505;
const ll inf = 1e12;
ll a[maxn][maxn];

int n, m;

ll get(int x1, int y1, int x2, int y2) {
    if (x1 > x2) {
        swap(x1, x2);
    }
    if (y1 > y2) {
        swap(y1, y2);
    }
    if (x1 < 1 || y1 < 1 || x2 > n || y2 > m) {
        return -inf;
    }

    return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
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

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            scanf("%d", &x);
            a[i][j] = x;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i) {
                a[i][j] += a[i - 1][j];
            }

            if (j) {
                a[i][j] += a[i][j - 1];
            }

            if (i && j) {
                a[i][j] -= a[i - 1][j - 1];
            }
        }
    }

    ll ans = -inf;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll s = get(i, j, i, j + 2);
            s += get(i - 1, j + 2, i - 2, j + 2);
            s += get(i - 2, j + 1, i - 2, j);
            int x = i - 2, y = j;
            chmax(ans, s);
            for (int k = 7; k < maxn; k += 4) {
                if (x < 1 || y < 1 || x > n || y > m) {
                    break;
                }
                
                s += get(x, y - 1, x, y - 2);
                y -= 2;

                s += get(x + 1, y, x + k - 3, y);
                x = x + k - 3;

                s += get(x, y + 1, x, y + 1 + k - 1 - 1);
                y = y + 1 + k - 1 - 1;

                s += get(x - 1, y, x - 1 - (k - 1) + 1, y);
                x = x - 1 - (k - 1) + 1;

                s += get(x, y - 1, x, y - 1 - (k - 1) + 1);
                y = y - 1 - (k - 1) + 1;

                chmax(ans, s);
            }

            s = get(i, j, i, j - 2);
            x = i, y = j - 2;
            s += get(x + 1, y, x + 2, y);
            x = x + 2;
            s += get(x, y + 1, x, y + 4);
            y = y + 4;
            s += get(x - 1, y, x - 4, y);
            x = x - 4;
            s += get(x, y - 1, x, y - 4);
            y = y - 4;
            chmax(ans, s);


            for (int k = 9; k < maxn; k += 4) {

                if (x < 1 || y < 1 || x > n || y > m) {
                    break;
                }

                s += get(x, y - 1, x, y - 2);
                y -= 2;

                s += get(x + 1, y, x + k - 3, y);
                x = x + k - 3;

                s += get(x, y + 1, x, y + 1 + k - 1 - 1);
                y = y + 1 + k - 1 - 1;

                s += get(x - 1, y, x - 1 - (k - 1) + 1, y);
                x = x - 1 - (k - 1) + 1;

                s += get(x, y - 1, x, y - 1 - (k - 1) + 1);
                y = y - 1 - (k - 1) + 1;

                chmax(ans, s);
            }
        }
    }

    cout << ans << endl;

    return 0;
}