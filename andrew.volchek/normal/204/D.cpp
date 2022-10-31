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

const int maxn = 1e6 + 5;
const int mod = 1000000007;

void add(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

void sub(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

int dp[maxn][3][2];
char a[maxn];
int good[2][maxn];

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

    int n, k;
    scanf("%d %d\n", &n, &k);
    scanf("%s", a);

    if (k == 1) {
        if (a[0] == 'B') {
            dp[0][0][0] = 1;
            dp[0][1][0] = 1;
        } else if (a[0] == 'W') {
            dp[0][0][1] = 1;
        } else {
            dp[0][0][0] = 1;
            dp[0][0][1] = 1;
            dp[0][1][0] = 1;
        }
    } else {
        if (a[0] == 'B' || a[0] == 'X') {
            dp[0][0][0] = 1;
        }

        if (a[0] == 'W' || a[0] == 'X') {
            dp[0][0][1] = 1;
        }
    }

    int cnt = 0;

    for (int i = 0; i < k; i++) {
        cnt += a[i] == 'W';
    }

    for (int i = k - 1; i < n; i++) {
        good[0][i] = !cnt;
        cnt -= a[i - k + 1] == 'W';
        cnt += a[i + 1] == 'W';
    }

    cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += a[i] == 'B';
    }

    for (int i = k - 1; i < n; i++) {
        good[1][i] = !cnt;
        cnt -= a[i - k + 1] == 'B';
        cnt += a[i + 1] == 'B';
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == 'B' || a[i] == 'X') {
            add(dp[i][0][0], dp[i - 1][0][0]);
            add(dp[i][0][0], dp[i - 1][0][1]);

            add(dp[i][1][0], dp[i - 1][1][0]);
            add(dp[i][1][0], dp[i - 1][1][1]);

            if (good[0][i]) {
                add(dp[i][1][0], (i < k ? 1 : dp[i - k][0][1]));
                sub(dp[i][1][0], (i < k ? 0 : dp[i - k][1][1]));
            }

            add(dp[i][2][0], dp[i - 1][2][0]);
            add(dp[i][2][0], dp[i - 1][2][1]);
        }

        if (a[i] == 'W' || a[i] == 'X') {
            add(dp[i][0][1], dp[i - 1][0][0]);
            add(dp[i][0][1], dp[i - 1][0][1]);

            add(dp[i][1][1], dp[i - 1][1][0]);
            add(dp[i][1][1], dp[i - 1][1][1]);

            add(dp[i][2][1], dp[i - 1][2][0]);
            add(dp[i][2][1], dp[i - 1][2][1]);

            if (good[1][i]) {
                add(dp[i][2][1], (i < k ? 0 : dp[i - k][1][0]));
                sub(dp[i][2][1], (i < k ? 0 : dp[i - k][2][0]));
            }
        }
    }

    cout << (dp[n - 1][2][0] + dp[n - 1][2][1]) % mod << endl;

    return 0;
}