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



int main() {
    //srand(time(NULL));

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
    string s;
    cin >> n >> s;

    int dp[3][2] = {};

    auto chmax2 = [](int &x, int y) {
        if (y > 1) {
            chmax(x, y);
        }
    };

    for (char c : s) {
        if (c == '0') {
            chmax2(dp[2][0], dp[2][1] + 1);
            chmax2(dp[2][0], dp[1][0] + 1);

            chmax2(dp[1][0], dp[1][1] + 1);
            chmax2(dp[1][0], dp[0][0] + 1);

            chmax2(dp[0][0], dp[0][1] + 1);
            chmax(dp[0][0], 1);
        } else {
            chmax2(dp[2][1], dp[2][0] + 1);
            chmax2(dp[2][1], dp[1][1] + 1);

            chmax2(dp[1][1], dp[1][0] + 1);
            chmax2(dp[1][1], dp[0][1] + 1);

            chmax2(dp[0][1], dp[0][0] + 1);
            chmax(dp[0][1], 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            chmax(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}