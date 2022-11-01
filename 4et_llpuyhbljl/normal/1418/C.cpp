#pragma comment(linker, "/STACK:2759095000")
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
const int maxN = 100010, maxT = 2001;

int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    vector<int>aa;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>>dp(2, vector<int>(n, INF));
        dp[0][0] = a[0];
        if (n != 1) {
            dp[0][1] = a[0] + a[1];
        }
        for (int i = 1; i < n; ++i) {
            dp[1][i] = min(dp[1][i], dp[0][i - 1]);
            if (i != 1)dp[1][i] = min(dp[1][i], dp[0][i - 2]);
            dp[0][i] = min(dp[0][i], dp[1][i - 1]);
            if (i != 1) dp[0][i] = min(dp[0][i], dp[1][i - 2] + a[i - 1]);
            dp[0][i] += a[i];
        }
        aa.push_back(min(dp[0].back(), dp[1].back()));
    }
    for (auto x : aa)cout << x << "\n";
    return 0;
}
/*
long long x, y, k;
        cin >> x >> y >> k;
        long long tmp = y * k + k - 1;
        cout << (tmp + x - 1) / x + k << "\n";
*/