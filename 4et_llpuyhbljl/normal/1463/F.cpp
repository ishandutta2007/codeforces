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
#include<unordered_map>
#include<random>
#include<ctime>
//#define double long double
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
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
//#define int long long
const long long INF = 1e18;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 300100, maxT = 100010;
int d = 3;
void panic() {
    cout << "0\n";
    exit(0);
}
int dp[2][1 << 22];
int valid[1 << 23];
int solve(int n, int x, int y) {
    if (y > x)swap(x, y);
    int lcm = x + y;
    if (x == y)lcm = 2 * x;
    int msk = (1 << x) - 1;
    fill(begin(dp[0]), end(dp[0]), -1);
    fill(begin(valid), end(valid), 1);
    dp[0][0] = 0;
    vector<int>good;
    vector<int>mm1, mm2(1 << x);
    int jj;
    for (int i = 0; i < (1 << (x + 1)); ++i) {
        for (int j = 0; j < x; ++j) {
            if ((i & (1 << j)) == 0)continue;
            if (j + y < x + 1 && (i & (1 << (j + y))) != 0)valid[i] = 0;
            if (j + x < x + 1 && (i & (1 << (j + x))) != 0)valid[i] = 0;
        }
        if (valid[i] && i < (1 << x))good.push_back(i);
    }
    for (int i = 0; i <= min(n, d * lcm); ++i) {
        fill(begin(dp[(i + 1) % 2]), end(dp[(i + 1) % 2]), -1);
        if ((n - i) % lcm == 0) {
            vector<int>vl(1 << x);
            for (int j = 0; j < (1 << x); ++j)vl[j] = dp[i % 2][j];
            mm1 = mm2;
            mm2 = vl;
            jj = i;
        }
        for (auto m : good) {
            if (dp[i % 2][m] == -1)continue;
            int m1 = (m << 1) | 1;
            int m2 = (m << 1);
            if (valid[m1]) {
                dp[(i + 1) % 2][m1 & msk] = max(dp[(i + 1) % 2][m1 & msk], dp[i % 2][m] + 1);
            }
            if (valid[m2]) {
                dp[(i + 1) % 2][m2 & msk] = max(dp[(i + 1) % 2][m2 & msk], dp[(i % 2)][m]);
            }
        }
    }
    int ans = 0;
    int k = (n - jj) / lcm;
    for (auto m : good) {
        ans = max(ans, mm2[m] + k * (mm2[m] - mm1[m]));
    }
    return ans;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(11);
#ifdef _MY
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int n, x, y;
    cin >> n >> x >> y;
    cout << solve(n, x, y);
    return 0;
}