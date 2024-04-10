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
const long long INF = 1e18;
//const int mod = 1000000007;
int mod;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 171501, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int k;
vector<int> solve(vector<int>a) {
    int m = a.size() / 2;
    vector<vector<int>>tp(m + 1, vector<int>(k, -1));
    tp[0][0] = 0;

    for (auto x : a) {
        for (int j = m - 1; j >= 0; --j) {
            for (int os = 0; os < k; ++os) {
                int no = (os + x) % k;
                if (tp[j][os] != -1) {
                    tp[j + 1][no] = max(tp[j + 1][no], tp[j][os] + x);
                }
            }
        }
    }
    vector<int>ost(k, -1);
    for (int j = 0; j <= m; ++j) {
        for (int os = 0; os < k; ++os)ost[os] = max(ost[os], tp[j][os]);
    }
    return ost;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    // file_inc();
    int n, m;
    cin >> n >> m >> k;
    vector<int>ost(k, -1);
    ost[0] = 0;
    vector<vector<int>>a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)cin >> a[i][j];
        vector<int>tmp = solve(a[i]);
        vector<int>nn(k, -1);
        for (auto x : ost) {
            if (x == -1)continue;
            for (auto y : tmp) {
                if (y == -1)continue;
                nn[(x + y) % k] = max(nn[(x + y) % k], x + y);
            }
        }
        ost = nn;
    }
    cout << ost[0];
    return 0;
}