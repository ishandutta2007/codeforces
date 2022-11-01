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
const long long INF = -(1LL << 31);
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 10010, maxT = 101;
int dp[maxT][maxN];
int a[maxT], b[maxT];
void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        sum += b[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < maxN; ++j) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int add = a[i] - b[i];
        for (int m = n - 1; m >= 0; --m) {
            for (int j = 0; j < maxN; ++j) {
                if (dp[m][j] == -1)continue;
                dp[m + 1][j + b[i]] = max(dp[m + 1][j + b[i]], dp[m][j] + add);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ld ans = 0;
        for (int j = 0; j < maxN; ++j) {
            if (dp[i][j] == -1)continue;
            ans = max(ans, (ld)j + min((ld)(sum - j) / 2, (ld)dp[i][j]));
        }
        cout << fixed << ans << " ";
    }
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
    int t;
   // cin >> t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}