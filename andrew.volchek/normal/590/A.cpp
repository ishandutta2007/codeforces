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
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 5e5 + 5;
int a[maxn];
int b[maxn];

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

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    for (int i = 1; i + 1 < n; i++) {
        b[i] = (a[i] != a[i - 1] && a[i] != a[i + 1]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (!b[i]) {
            continue;
        }

        int j = i;
        while (j < n && b[j]) {
            j++;
        }

        ans = max(ans, (j - i + 1) / 2);

        if ((j - i) & 1) {
            for (int h = i; h < j; h++) {
                a[h] = a[i - 1];
            }
        } else {
            for (int h = 0; h < (j - i) / 2; h++) {
                a[i + h] = a[i - 1];
                a[j - 1 - h] = a[j];
            }
        }

        i = j - 1;
    }

    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", a[i]);
    }



    return 0;
}