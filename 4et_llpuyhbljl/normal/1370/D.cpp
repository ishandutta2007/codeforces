#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 10000000;
const int Y = 200100;
long long n, k;
const long long mod = 1000000007;
int dp[2][Y];
long long a[Y];
bool f(long long v) {
    int mx = 0;
    if (k % 2 == 0) {
        for (int i = 1; i < n; ++i) {
            if (a[i] <= v) {
                dp[1][i] = dp[0][i - 1] + 1;
            }
            else {
                dp[1][i] = -1;
            }
            dp[0][i] = mx;
            mx = max(mx, max(dp[0][i], dp[1][i]));
        }
        if (mx * 2 >= k)return true;
        mx = 0;
        dp[1][1] = dp[0][1] = 0;
        for (int i = 2; i <= n; ++i) {
            if (a[i] <= v) {
                dp[1][i] = dp[0][i - 1] + 1;
            }
            else {
                dp[1][i] = -1;
            }
            dp[0][i] = mx;
            mx = max(mx, max(dp[0][i], dp[1][i]));
        }
        return 2 * mx >= k;
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (a[i] <= v) {
                dp[1][i] = dp[0][i - 1] + 1;
            }
            else {
                dp[1][i] = -1;
            }
            dp[0][i] = mx;
            mx = max(mx, max(dp[0][i], dp[1][i]));
        }
        if (2 * mx >= k + 1)return true;
        dp[1][1] = dp[0][1] = 0;
        mx = 0;
        for (int i = 2; i <= n - 1; ++i) {
            if (a[i] <= v) {
                dp[1][i] = dp[0][i - 1] + 1;
            }
            else {
                dp[1][i] = -1;
            }
            dp[0][i] = mx;
            mx = max(mx, max(dp[0][i], dp[1][i]));
        }
        return 2 * mx >= k - 1;
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    dp[0][0] = dp[1][0] = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long b = 0, e = 1e10;
    while (b + 1 != e) {
        long long mid = (b + e) / 2;
        if (f(mid))e = mid;
        else b = mid;
    }
    cout << e;
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */