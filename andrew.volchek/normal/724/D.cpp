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

const int maxn = 1e5 + 5;
const int inf = 1e9;
char s[maxn];
int tr[maxn * 4];
int get(int v, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return tr[v];
    }
    int res = inf;
    int c = (l + r) >> 1;
    if (i <= c) {
        chmin(res, get(2 * v, l, c, i, j));
    }
    if (c < j) {
        chmin(res, get(2 * v + 1, c + 1, r, i, j));
    }
    return res;
}
void mod(int v, int l, int r, int i, int x) {
    if (l == r) {
        tr[v] = x;
        return;
    }
    int c = (l + r) >> 1;
    if (i <= c) {
        mod(2 * v, l, c, i, x);
    } else {
        mod(2 * v + 1, c + 1, r, i, x);
    }
    tr[v] = min(tr[2 * v], tr[2 * v + 1]);
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

    int m;
    scanf("%d\n%s", &m, s);

    int n = strlen(s);
    fill(tr, tr + maxn * 4, inf);
    mod(1, 0, n, 0, 0);

    for (char c = 'a'; c <= 'z'; c++) {
        int lst = -1;
        bool good = true;
        for (int i = 0; i < n; i++) {
            if (s[i] <= c) {
                lst = i;
            }
            if (i - lst >= m) {
                good = false;
            }
        }
        if (!good) {
            continue;
        }


        for (int i = 0; i < n; i++) {
            int l = max(-1, i - m);
            int r = i - 1;
            int x = get(1, 0, n, l + 1, r + 1);
            if (s[i] < c) {
                mod(1, 0, n, i + 1, x);
            } else if (s[i] == c) {
                mod(1, 0, n, i + 1, x + 1);
            }
        }

        int f = get(1, 0, n, n - m + 1, n);

        string ans;
        for (int i = 0; i < n; i++) {
            if (s[i] < c) {
                ans += s[i];
            }
        }

        for (int i = 0; i < f; i++) {
            ans += c;
        }

        sort(ans.begin(), ans.end());
        cout << ans << endl;
        return 0;
    }

    return 0;
}