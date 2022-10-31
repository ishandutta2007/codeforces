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


ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
}

const ll maxn = 360360;
const int inf = 1e9;
ll blk = 1;
int dp[maxn + 1];
ll k;

int f(int from, int to) {
    fill(dp, dp + blk + 1, inf);
    dp[from] = 0;
    for (int i = from; i > to; i--) {
        chmin(dp[i - 1], dp[i] + 1);
        for (int j = 2; j <= k; j++) {
            int x = i - (i % j);
            if (x >= to) {
                chmin(dp[x], dp[i] + 1);
            }
        }
    }
    return dp[to];
}


int main() {
    //srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    ll a, b;
    cin >> a >> b >> k;

    for (int i = 1; i <= k; i++) {
        blk = blk / gcd(blk, i) * i;
    }

    ll ans = 0;

    if (a / blk == b / blk) {
        cout << f(a % blk, b % blk) << endl;
        return 0;
    }

    ans += f(a % blk, 0) + 1;
    a = a - (a % blk) - 1;

    ll need = a / blk - b / blk;
    ans += need * (f(blk - 1, 0) + 1);

    ans += f(blk - 1, b % blk);

    cout << ans << endl;

    return 0;
}