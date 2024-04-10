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
ostream& operator << (ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream& operator << (ostream &s, const vector<U> &x) {
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

const int maxn = 2e5 + 5;

ld solve(char *a, char *b, int n) {
    ld res = 0.0;
    for (int i = 0; i < 26; i++) {
        ld s = 0.0;
        for (int j = n - 1; j >= 0; j--) {
            if (a[j] - 'A' == i) {
                s += n - j;
            }

            if (b[j] - 'A' == i) {
                res += (j + 1) * s;
            }
        }
    }

    return res;
}

char a[maxn], b[maxn];

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

    int n;
    scanf("%d", &n);
    scanf("%s\n", a);
    scanf("%s\n", b);

    ld res = solve(a, b, n) + solve(b, a, n);

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            res -= 1LL * (i + 1) * (n - i);
        }
    }

    ld s = 0.0;
    for (int i = 0; i < n; i++) {
        s += (n - i) * 1LL * (n - i);
    }


    cout.precision(10);
    cout << fixed << res / s << endl;


    return 0;
}