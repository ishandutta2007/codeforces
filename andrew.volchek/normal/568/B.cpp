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

const int maxn = 4005;
const ll mod = 1000000007;

int c[maxn][maxn];
int dp[maxn][maxn];

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    for (int i = 0; i < maxn; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= mod) {
                c[i][j] -= mod;
            }
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            dp[i][j] = ((ll)dp[i - 1][j - 1] + 1LL * j * dp[i - 1][j]) % mod;
        }
    }


    int n;
    cin >> n;

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            ans += c[n][i] * 1LL * dp[n - i][j] % mod;
        }
        ans %= mod;
    }

    ans++;

    ans %= mod;

    cout << ans << endl;


    return 0;
}