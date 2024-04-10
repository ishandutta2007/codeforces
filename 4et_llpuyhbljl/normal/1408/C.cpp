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
const double INF = 1e17;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 100100, maxT = 2001;
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
    int t;
    cin >> t;
    while (t--) {
        int n, l;
        cin >> n >> l;
        deque<int>dd;
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            dd.push_back(t);
        }
        double ans = 0;
        pair<double, double>f = { 0,1 }, s = { l,1 };
        for (int i = 0; i < n; ++i) {
            double d1 = (double)dd.front() - f.first, d2 = s.first - dd.back();
            if (d1 * s.second < d2 * f.second) {
                double tm= d1 / f.second;
                ans += tm;
                f.first = dd.front();
                f.second++;
                dd.pop_front();
                s.first -= s.second * tm;
            }
            else {
                double tm = d2 / s.second;
                ans += tm;
                s.first = dd.back();
                s.second++;
                dd.pop_back();
                f.first += f.second * tm;
            }
        }
        ans += (s.first - f.first) / (s.second + f.second);
        cout << fixed << ans << "\n";
    }
    return 0;
}