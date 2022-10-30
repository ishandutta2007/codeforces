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

char s[300];

int len(int x) {
    if (x == 0) {
        return 1;
    }
    int res = 0;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
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

    scanf("%s", s);
    int n = strlen(s);
    int ans = -1;

    for (int i = 1; i < 8; i++) {
        if (i > n) {
            continue;
        }

        int x = 0;
        for (int u = 0; u < i; u++) {
            x = x * 10 + s[u] - '0';
        }

        if (len(x) != i) {
            continue;
        }


        for (int j = 1; j < 8; j++) {
            if (i + j > n) {
                continue;
            }

            int y = 0;
            for (int u = 0; u < j; u++) {
                y = y * 10 + s[i + u] - '0';
            }

            if (len(y) != j) {
                continue;
            }

            for (int h = 1; h < 8; h++) {
                if (i + j + h > n) {
                    continue;
                }

                int z = 0;
                for (int u = 0; u < h; u++) {
                    z = z * 10 + s[i + j + u] - '0';
                }

                if (len(z) != h) {
                    continue;
                }

                const int m = 1000000;
                if (i + j + h == n && x <= m && y <= m && z <= m) {
                    chmax(ans, x + y + z);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}