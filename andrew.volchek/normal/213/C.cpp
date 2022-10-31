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

const int maxn = 305;
const ll inf = 1e16;

int a[maxn][maxn];
ll dp[maxn][maxn], ndp[maxn][maxn];

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
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        fill(dp[i], dp[i] + n, -inf);
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = j; k < n; k++) {
                ndp[j][k] = dp[j][k] + a[j][i] + a[k][i];
                if (j == k) {
                    ndp[j][k] -= a[k][i];
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = j; k < n; k++) {
                if (j + 1 < k) {
                    chmax(ndp[j + 1][k], ndp[j][k] + a[j + 1][i]);
                }

                if (j + 1 == k) {
                    chmax(ndp[j + 1][k], ndp[j][k]);
                }

                if (j == k && j + 1 < n) {
                    chmax(ndp[j + 1][k + 1], ndp[j][k] + a[j + 1][i]);
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = j; k < n; k++) {
                if (k + 1 < n) {
                    chmax(ndp[j][k + 1], ndp[j][k] + a[k + 1][i]);
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dp[j][k] = ndp[j][k];
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;



    return 0;
}