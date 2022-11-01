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
const int maxN = 200100, maxT = 100010;
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
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>t(n + 1), x(n + 1), xx(n + 1);
        ll now_x = 0, now_target = 0, ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (i != n) cin >> t[i] >> x[i];
            else {
                t[i] = 1e16;
                x[i] = 1e17;
            }
            if (now_target != INF) {
                ll need_time = abs(now_x - now_target);
                ll tm = 0;
                if (i != 0) {
                    tm = t[i] - t[i - 1];
                }
                if (tm >= need_time) {
                    now_x = now_target;
                    now_target = INF;
                }
                else {
                    if (now_x > now_target)now_x -= tm;
                    else now_x += tm;
                }
            }
            if (now_target == INF) {
                now_target = x[i];
            }
            xx[i] = now_x;
            if (i != 0) {
                if (min(xx[i], xx[i - 1]) <= x[i - 1] && x[i - 1] <= max(xx[i], xx[i - 1]))++ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}