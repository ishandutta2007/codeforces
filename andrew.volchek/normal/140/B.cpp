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
#define ld double
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

const int maxn = 305;
int a[maxn][maxn];

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

    int n;
    cin >> n;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            scanf("%d", &x);
            a[i][x] = j;
        }
    }

    vector<int> ans(n + 1, -1);

    int curr = -1;
    int curr2 = -1;

    for (int i = 1; i <= n; i++) {
        if (curr == -1 || a[n + 1][curr] > a[n + 1][i]) {
            curr2 = curr;
            curr = i;
        } else if (curr2 == -1 || a[n + 1][curr2] > a[n + 1][i]) {
            curr2 = i;
        }

        for (int j = 1; j <= n; j++) {
            if (curr == j) {
                if (curr2 != -1) {
                    if (ans[j] == -1 || a[j][curr2] < a[j][ans[j]]) {
                        ans[j] = curr2;
                    }
                }
            } else {
                if (ans[j] == -1 || a[j][curr] < a[j][ans[j]]) {
                    ans[j] = curr;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }

    printf("\n");

    return 0;
}