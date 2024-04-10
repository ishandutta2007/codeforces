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

const int maxn = 105;
const ll mod = 1000000007;
ll c[maxn][maxn];
ll a[maxn];
ll dp[11][maxn];

ll solve(int n) {
    for (int i = 0; i < 11; i++) {
        fill(dp[i], dp[i] + maxn, 0);
    }

    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < maxn; j++) {
            for (int k = a[i]; k < maxn; k++) {
                if (k <= j) {
                    dp[i + 1][j - k] += dp[i][j] * c[j][k] % mod;
                    dp[i + 1][j - k] %= mod;
                }
            }
        }
    }

    return dp[10][0];
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

    for (int i = 0; i < maxn; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 1; i < 10; i++) {
        int prv = a[i];
        a[i] = max(0LL, a[i] - 1);
        ans = (ans + solve(n - 1)) % mod;
        a[i] = prv;
    }

    cout << ans << endl;

    return 0;
}