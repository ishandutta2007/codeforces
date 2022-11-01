#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
//#define int long long
using namespace std;
long long gcd(long long i, long long j) {
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
const long long INF = 1e9;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
   // file_inc();
    int n, r;
    cin >> r >> n;
    vector<int>X(n + 1), Y(n + 1), t(n + 1), mx(n + 1, -1);
    vector<int>dp(n + 1, -1);
    X[0] = Y[0] = 1;
    dp[0] = 0;
    mx[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> X[i] >> Y[i];
        for (int j = i - 1; j >= 0 && j >= i - 1000; --j) {
            if (i - j < 0)break;
           // cout << abs(X[i] - X[j]) + abs(Y[i] - Y[j]) << " " << t[i] - t[j] << endl;
            if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= t[i] - t[j] && dp[j] != -1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (i > 1000) {
            mx[i - 1000] = max(dp[i - 1000], mx[i - 1001]);
            dp[i] = max(dp[i], mx[i - 1000] + 1);
        }
    }
    int nx = 0;
    for (auto x : dp)nx = max(nx, x);
    cout << nx;
    return 0;
}