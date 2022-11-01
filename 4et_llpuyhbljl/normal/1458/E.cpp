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
const long long INF = 2e9;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 500100, maxT = 100010;
void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int>X, Y;
    vector<int>vals_x, vals_y;
    set<pair<int, int>>bad_points;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        bad_points.insert({ x,y });
        vals_x.push_back(x);
        vals_y.push_back(y);
        if (X.count(x))X[x] = min(X[x], y);
        else X[x] = y;
        if (Y.count(y))Y[y] = min(Y[y], x);
        else Y[y] = x;
    }
    sort(vals_x.begin(), vals_x.end());
    vals_x.resize(unique(vals_x.begin(), vals_x.end()) - vals_x.begin());
    sort(vals_y.begin(), vals_y.end());
    vals_y.resize(unique(vals_y.begin(), vals_y.end()) - vals_y.begin());
    vector<pair<int, int>>also_very_bad;
    int x = 0, y = 0;
    while (lower_bound(vals_x.begin(), vals_x.end(), x) != vals_x.end() || 
        lower_bound(vals_y.begin(), vals_y.end(), y) != vals_y.end()) {
        if (bad_points.count({ x,y })) {
            ++x;
            ++y;
            continue;
        }
        if (X.count(x) && y > X[x]) {
            ++x;
            continue;
        }
        if (Y.count(y) && x > Y[y]) {
            ++y;
            continue;
        }
        int d = INF;
        also_very_bad.push_back({ x,y });
        int tm = lower_bound(vals_x.begin(), vals_x.end(), x) - vals_x.begin();
        if (tm != vals_x.size())d = min(d, vals_x[tm] - x);
        tm = lower_bound(vals_y.begin(), vals_y.end(), y) - vals_y.begin();
        if (tm != vals_y.size())d = min(d, vals_y[tm] - y);
        d = max(d, 1);
        x += d;
        y += d;
    }
    also_very_bad.push_back({ x,y });
    while (m--) {
        cin >> x >> y;
        if (bad_points.count({ x,y })) {
            cout << "LOSE\n";
            continue;
        }
        if (X.count(x) && y > X[x] || Y.count(y) && x > Y[y]) {
            cout << "WIN\n";
            continue;
        }
        int r = upper_bound(also_very_bad.begin(), also_very_bad.end(), make_pair(x, y)) - also_very_bad.begin() - 1;
        int x1, y1;
        tie(x1, y1) = also_very_bad[r];
        if (x - x1 == y - y1) {
            cout << "LOSE\n";
        }
        else {
            cout << "WIN\n";
        }
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
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}